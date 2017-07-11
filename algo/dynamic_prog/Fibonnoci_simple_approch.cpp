//Fibonoci Simple approch
#include <iostream>
using namespace std;

int fib(int n){
	if(n<=1){
		return n;
	}if(n==2){
		return 2;
	}else{
		int currentVal = fib(n-1);
		currentVal += fib(n-2);
		return currentVal;
	}
}
int main(){
	int n = 5;
	cout<<"Fibbonoci value of "<<n<<": "<<fib(n);
	return 0;
}