#!/bin/python3
import sys
def getrounded(grade):
	if grade > 37 :
		remainder = grade%5
		if remainder >= 3 :
			return (grade + (5-remainder))
	return grade

n = int(input().strip())
i=0
for i in range(n):
	num = int(input().strip())
	print(getrounded(num))
