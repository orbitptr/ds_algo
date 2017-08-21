def gcd(a,b):
	if a == b :
		return a
	if a > b:
		return gcd(a-b,b)
	return gcd(a,b-a)
def lcm(a,b):
	return ((a*b)/gcd(a,b))

x1,x2,v1,v2 = map(int,input().strip().split());
lcmval = lcm(v1,v2)
print (lcmval)
