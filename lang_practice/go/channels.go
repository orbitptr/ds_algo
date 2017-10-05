package main
import (
	"fmt"
	"time"
	"strconv"
)

func process1(id string,commonChannel chan string) {
	fmt.Println("++Spawned P1 ID:",id)
	time.Sleep(time.Second * 5)
	commonChannel <- "Process1 completed for id:" +id
}

func process2(id string,commonChannel chan string) {
	fmt.Println("++Spawned P2 ID:",id)
	msgFromP1 := <-commonChannel
	fmt.Println("\""+msgFromP1 +"\" message came for Process2 ID:"+id)
}

func main(){	
	var commonChannel chan string=make(chan string)
	var n int = 10
	for i :=1;i<=n;i++{
		id:= strconv.Itoa(i)
		go process1(id,commonChannel)	
		go process2(id,commonChannel)	
	}
	var input string
    fmt.Scanln(&input)
}