#!/bin/python3

import sys
def solveLinear(n,s,d,m):
    winlen=0
    sum=0
    ans=0
    for i in range(0,n):
        winlen+=1
        sum+=s[i]
        if winlen is m:
            winlen-=1
            if sum is d:
                ans+=1
            sum-=s[i-m-1]
    return ans
    
n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
d, m = input().strip().split(' ')
d, m = [int(d), int(m)]
result = solveLinear(n, s, d, m)
print(result)
