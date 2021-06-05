package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strconv"
	"strings"
)

// Note: C++ Only!!!

var SolutionCount map[string]int

func ParseAndGetCode(url string, contestID int32, problemLetter string, problemName string) {
	//fmt.Println("Parsing url: " + url)
	Client := http.Client{}
	Response, ok := Client.Get(url)
	if ok != nil {
		panic(ok.Error())
	}
	if Response.Request.URL.String() != url {
		return
	}
	ResponseBody, ok := ioutil.ReadAll(Response.Body)
	if ok != nil {
		panic(ok.Error())
	}
	AsString := string(ResponseBody)
	Position := strings.Index(AsString, "#include")
	NeedOnly := AsString[Position:]
	Last := strings.Index(NeedOnly, "</pre>")
	Code := NeedOnly[:Last]
	// TODO: make as function
	Code = strings.Replace(Code, "&quot;", "\"", -1)
	Code = strings.Replace(Code, "&gt;", ">", -1)
	Code = strings.Replace(Code, "&lt;", "<", -1)
	Code = strings.Replace(Code, "&#39;", "'", -1)
	Code = strings.Replace(Code, "&amp;", "&", -1)
	path := "Codeforces"
	if _, err := os.Stat(path); os.IsNotExist(err) {
		err := os.Mkdir(path, 0700)
		if err != nil {
			panic(err.Error())
		}
	}
	path = "Codeforces/Contest" + strconv.Itoa(int(contestID))
	problemName = strings.Replace(problemName, " ", "_", -1)
	{
		problem := ""
		for i := 0; i < len(problemName); i += 1 {
			asRune := rune(problemName[i])
			// TODO: make as function
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
	problemName += ".cpp"
	if _, err := os.Stat(path); os.IsNotExist(err) {
		err := os.Mkdir(path, 0700)
		if err != nil {
			panic(err.Error())
		}
	}
	err := os.WriteFile(path+"/"+problemName, []byte(Code), 0644)
	if err != nil {
		panic(err.Error())
	}
}

func main() {
	SolutionCount = make(map[string]int)
	Client := http.Client{}

	Response, ok := Client.Get("https://codeforces.com/api/user.status?handle=iMurat&from=1&count=100000")
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
		// TODO: add versions as array
		if response.Result[i].Verdict == "OK" &&
			(response.Result[i].ProgrammingLanguage == "GNU C++17" ||
				response.Result[i].ProgrammingLanguage == "GNU C++" ||
				response.Result[i].ProgrammingLanguage == "GNU C++14" ||
				response.Result[i].ProgrammingLanguage == "GNU C++11") {
			fmt.Println(
				response.Result[i].Id,
				response.Result[i].Problem.ContestId,
				response.Result[i].Problem.Index,
				response.Result[i].Problem.Name,
			)
			CodeURL := ""
			// TODO: refactor
			if response.Result[i].Problem.ContestId > 1535 {
				CodeURL = "https://codeforces.com/gym/" + strconv.Itoa(int(response.Result[i].Problem.ContestId)) + "/submission/" + strconv.Itoa(int(response.Result[i].Id))
			} else {
				CodeURL = "https://codeforces.com/contest/" + strconv.Itoa(int(response.Result[i].Problem.ContestId)) + "/submission/" + strconv.Itoa(int(response.Result[i].Id))
			}
			ParseAndGetCode(CodeURL, response.Result[i].Problem.ContestId, response.Result[i].Problem.Index, response.Result[i].Problem.Name)
		}
	}
}
