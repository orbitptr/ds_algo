package main
import (
	"fmt"
)

func myfun(name string,channel chan string) {
	fmt.Println("++Spawned :",name)
	channel <- "Finished the thread"
}

func main(){
	var doneChannel chan string = make(chan string)
	go myfun("jithu1",doneChannel)
	msg:= <-doneChannel //Blocking
	fmt.Println("Finished with msg:",msg)
	// go myfun("jithu2")
	// go myfun("jithu3")
	// go myfun("jithu4")
	// go myfun("jithu5")
	
	// var input string
	// fmt.Scanln(&input)
}