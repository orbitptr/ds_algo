#!/bin/python3
def getMaxVal(arr,n):
	if arr == None or len(arr) <=0:
		return -1
	max_ending_here = max_overall = arr[0]
	start=end=tempstart=0
	for i in range(1,n):
		val = arr[i]
		if val > (max_ending_here+val):
			tempstart=i
			max_ending_here = val
		else:
			max_ending_here +=val
		if max_overall < max_ending_here:
			max_overall = max_ending_here
			start = tempstart
			end=i
	print ("range is ["+ str(start+1)+","+str(end+1)+"]")
	return max_overall

t=int(input().strip())
for i in range(t):
	n=int(input().strip())
	arr=list(map(int,input().strip().split()))
	print(getMaxVal(arr,n))
