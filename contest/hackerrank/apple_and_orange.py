import sys
s,t = map(int,input().strip().split())
a,b = map(int,input().strip().split())
m,n = map(int,input().strip().split())
ac=0
oc=0
al=list(map(int,input().strip().split()))
ol=list(map(int,input().strip().split()))
for i in range(m):
	pos = (a+al[i]) 
	if (pos >= s) and (pos <=t):
		ac+=1
for i in range(n):
	pos = (b+ol[i])
	if (pos >= s) and (pos <=t):
		oc+=1
print(ac)
print(oc)
