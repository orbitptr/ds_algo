package main
import (
	"fmt"
	"strconv"
)

type Global struct{
	name string
	address string
}

func gofunction(o *Global,id string,doneChannel chan string) {
	fmt.Println("++Spawned :",id," name:",o.name)
	o.name = id
	doneChannel <- string(id) + " done!"
}

func main(){
	var o *Global = &Global{name:"InitialName",address:"InitialAddress"}
	var doneChannel chan string=make(chan string)
	var n int = 10
	for i :=0;i<n;i++{
		id:= strconv.Itoa(i)
		go gofunction(o,id,doneChannel)	
	}
	for i :=0;i<n;i++{
		msg:= <-doneChannel
		fmt.Println("--Finished:",msg)
	}
	// var input string
    // fmt.Scanln(&input)
}