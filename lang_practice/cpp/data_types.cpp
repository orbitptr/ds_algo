//string practice c++
#include <iostream>
#include <string>
using namespace std;
int main(){
	size_t size_t1;
	int int1;
	unsigned int un_int_1;
	long long1;
	unsigned long un_long1;
	long long long_long1;
	unsigned long long un_long_long1;
	cout<<typeid(int1).name()<<" :int: "<<endl;
	cout<<typeid(un_int_1).name()<<" :un_int_: "<<endl;
	cout<<typeid(long1).name()<<" :long: "<<endl;
	cout<<typeid(un_long1).name()<<" :un_long: "<<endl;
	cout<<typeid(long_long1).name()<<" :long_long: "<<endl;
	cout<<typeid(un_long_long1).name()<<" :un_long_long: "<<endl;
	cout<<typeid(size_t1).name()<<" :size_t: "<<endl;
	return 0;
}