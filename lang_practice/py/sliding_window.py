#!/bin/python3
import sys
def slidingWindowLinear(n,s,w):
    winlen=0
    for i in range(0,n):
        winlen+=1
        if winlen is w:
            winlen-=1
            print(""+str(i-(w-1))+"-"+str(i))


def slidingWindowLinear2(n,s,w):    
    w=min(n,w)
    start=0
    sum=0
    ans=0
    print(""+str(start)+"-"+str(w-1))
    for i in range(0,w):
        sum+=s[i]
    if sum is d:
        ans+=1
    for i in range(w,n):
        sum-=s[start]
        sum+=s[i]
        print(""+str(start)+"-"+str(i))
        start+=1
    return ans

s = list(map(int, input().strip().split(' ')))
w=int(input().strip())
slidingWindowLinear(len(s),s,w)