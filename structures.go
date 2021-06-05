package main

type CF_Problem struct {
	ContestId      int32    `json:"contestId"`
	ProblemSetName string   `json:"problemsetName"`
	Index          string   `json:"index"`
	Name           string   `json:"name"`
	Type           string   `json:"type"`
	Points         float32  `json:"points"`
	Rating         int32    `json:"rating"`
	Tags           []string `json:"tags"`
}

type CF_Member struct {
	Handle string `json:"handle"`
}

type CF_Party struct {
	Members []CF_Member `json:"members"`
}

type CF_Submission struct {
	Id                  int32      `json:"id"`
	ContestId           int32      `json:"contestId"`
	CreationTimeSeconds int32      `json:"creationTimeSeconds"`
	RelativeTimeSeconds int32      `json:"relativeTimeSeconds"`
	Problem             CF_Problem `json:"problem"`
	Author              CF_Party   `json:"author"`
	ProgrammingLanguage string     `json:"programmingLanguage"`
	Verdict             string     `json:"verdict"`
	TestSet             string     `json:"testset"`
	PassedTestCount     int32      `json:"passedTestCount"`
	TimeConsumedMillis  int32      `json:"timeConsumedMillis"`
	MemoryConsumedBytes int32      `json:"memoryConsumedBytes"`
	Point               float32    `json:"points"`
}

type StatusResponse struct {
	Status string          `json:"status"`
	Result []CF_Submission `json:"result"`
}
