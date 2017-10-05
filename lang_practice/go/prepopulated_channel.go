package main

import (
  "fmt"
  "time"
  "strconv"
)

func printer(c chan string) {
  for value := range c{
    fmt.Println("Channel Msg:"+ value)
    time.Sleep(time.Second * 1)
  }
}

func main() {
  var c chan string = make(chan string)
  n:=10
  go printer(c) // if this channel msg receiver is not declared before sending msg in channel then it will result in a deadlock
  for i :=1;i<=n;i++{
    channelmsg :=  strconv.Itoa(i)
    c<-channelmsg
  }
  fmt.Println("Sent all the messages:")

  var input string
  fmt.Scanln(&input)
}