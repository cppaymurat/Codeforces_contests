package main

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"os"
	"strconv"
	"strings"
)

var SolutionCount map[string]int
var LastContestID int32

func SetLastContestID() {
	Response, ok := http.Get("https://codeforces.com/problemset")
	if ok != nil {
		panic(ok.Error())
	}
	AsBytes, ok := ioutil.ReadAll(Response.Body)
	if ok != nil {
		panic(ok.Error())
	}
	AsString := string(AsBytes)
	keyword := "/problemset/problem/"
	Id := strings.Index(AsString, keyword)
	if Id == -1 {
		panic("Can not find ID of last contest")
	}
	LastContestID = 0
	for i := 0; i < 4; i += 1 {
		LastContestID = LastContestID*10 + rune(AsString[len(keyword)+Id+i]) - '0'
	}
}

func ReplaceSymbols(Code string) string {
	oldSubstrings := [5]string{"&quot;", "&gt;", "&lt;", "&#39;", "&amp;"}
	replaceBy := [5]string{"\"", ">", "<", "'", "&"}
	for i := 0; i < 5; i += 1 {
		Code = strings.Replace(Code, oldSubstrings[i], replaceBy[i], -1)
	}
	return Code
}

func ParseProblemName(problemName string, problemLetter string) string {
	problemName = strings.Replace(problemName, " ", "_", -1)
	{
		problem := ""
		for i := 0; i < len(problemName); i += 1 {
			asRune := rune(problemName[i])
			if (asRune >= 'a' && asRune <= 'z') ||
				(asRune >= 'A' && asRune <= 'Z') ||
				(asRune >= 'а' && asRune <= 'я') ||
				(asRune >= 'А' && asRune <= 'Я') ||
				(asRune >= '0' && asRune <= '9') ||
				(asRune == '.' || asRune == '_') ||
				asRune == ',' || asRune == '-' {
				problem += string(asRune)
			} else if asRune == ' ' {
				problem += "_"
			}
		}
		problemName = problem
	}
	problemName = problemLetter + "." + problemName
	if SolutionCount[problemName] > 0 {
		problemName += "_version_" + strconv.Itoa(SolutionCount[problemName]+1)
	}
	SolutionCount[problemName] += 1
	return problemName
}

func GetCode(url string) string {
	Response, ok := http.Get(url)
	if ok != nil {
		panic(ok.Error())
	}
	if Response.Request.URL.String() != url {
		return "URL: " + url + " redirecting to the main page. " +
			"Couldn't find a code\n" +
			"Probably, the submission is private!"
	}
	ResponseBody, ok := ioutil.ReadAll(Response.Body)
	if ok != nil {
		panic(ok.Error())
	}
	AsString := string(ResponseBody)
	Position := strings.Index(AsString, "program-source-text")
	for AsString[Position] != '>' {
		Position += 1
	}
	Position += 1
	NeedOnly := AsString[Position:]
	Last := strings.Index(NeedOnly, "</pre>")
	Code := NeedOnly[:Last]
	Code = ReplaceSymbols(Code)
	return Code
}

func CreateFolder(path string) {
	if _, err := os.Stat(path); os.IsNotExist(err) {
		err := os.Mkdir(path, 0700)
		if err != nil {
			panic(err.Error())
		}
	}
}

func GetExtension(Language string) string {
	switch Language {
	case "GNU C++17", "GNU C++14", "GNU C++11", "GNU C++", "MS C++ 2017", "MS C++", "GNU C++17 (64)":
		{
			return ".cpp"
		}
	case "GNU C11":
		{
			return ".c"
		}
	case "Node.js", "JavaScript":
		{
			return ".js"
		}
	case "Scala":
		{
			return ".scala"
		}
	case "Rust":
		{
			return ".rs"
		}
	case "Ruby 3":
		{
			return ".rb"
		}
	case "PyPy 3", "PyPy 2", "Python 3 + libs", "Python 3", "Python 2":
		{
			return ".py"
		}
	case "PHP":
		{
			return ".php"
		}
	case "Perl":
		{
			return ".pl"
		}
	case "PascalABC.NET", "FPC", "Delphi":
		{
			return ".pas"
		}
	case "Ocaml":
		{
			return ".ml"
		}
	case "Kotlin":
		{
			return ".kt"
		}
	case "Java 8", "Java 11":
		{
			return ".java"
		}
	case "Haskell":
		{
			return ".hs"
		}
	case "Go":
		{
			return ".go"
		}
	case "D":
		{
			return ".d"
		}
	case "Mono C#", ".NET Core C#":
		{
			return ".cs"
		}

	default:
		{
			return ".txt"
		}
	}
}

func ParseAndGetCode(url string, contestID int32, problemLetter string, problemName string, Language string) {
	Code := GetCode(url)
	path := "Codeforces/Contest" + strconv.Itoa(int(contestID))
	CreateFolder("Codeforces")
	CreateFolder(path)
	problemName = ParseProblemName(problemName, problemLetter)
	problemName += GetExtension(Language)
	err := os.WriteFile(path+"/"+problemName, []byte(Code), 0644)
	if err != nil {
		panic(err.Error())
	}
}

func AddSolution(Submission CF_Submission) {
	TYPE := "contest"
	if Submission.Problem.ContestId > LastContestID {
		TYPE = "gym"
	}
	CodeURL :=
		"https://codeforces.com/" + TYPE + "/" +
			strconv.Itoa(int(Submission.Problem.ContestId)) +
			"/submission/" + strconv.Itoa(int(Submission.Id))
	ParseAndGetCode(
		CodeURL,
		Submission.Problem.ContestId,
		Submission.Problem.Index,
		Submission.Problem.Name,
		Submission.ProgrammingLanguage,
	)
}

func main() {
	handle := "iMurat"
	SolutionCount = make(map[string]int)
	SetLastContestID()
	Client := http.Client{}
	Response, ok := Client.Get("https://codeforces.com/api/user.status?handle=" + handle + "&from=1&count=100000")
	if ok != nil {
		panic(ok.Error())
	}
	ResponseBody, ok := ioutil.ReadAll(Response.Body)
	if ok != nil {
		panic(ok.Error())
	}
	response := &StatusResponse{}
	err := json.Unmarshal(ResponseBody, response)
	if err != nil {
		panic(err.Error())
	}
	for i := 0; i < len(response.Result); i += 1 {
		if response.Result[i].Verdict == "OK" {
			AddSolution(response.Result[i])
		}
	}
}
