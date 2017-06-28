//string practice c++
#include <iostream>
#include <string>
using namespace std;
int main(){
	std::string name;
	//std::getline(std::cin,name);
	//std::cout<<name;
	const string base_str= "123456789";
	std::string str=base_str;
	std::cout<<str<<endl;
	cout<<"length(): "<<str.length()<<endl;
	cout<<"capacity(): "<<str.capacity()<<endl;
	cout<<"max_size(): "<<str.max_size()<<endl;
	cout<<"size(): "<<str.size()<<endl;
	cout<<"back(): "<<str.back()<<endl;
	cout<<"front(): "<<str.front()<<endl;
	cout<<"at(3): "<<str.at(3)<<endl;
	cout<<"str[3]: "<<str[3]<<endl;
	cout<<"string::npos: "<<string::npos<<endl;
	cout<<"find(\"67\"): "<<str.find("67")<<endl;
	cout<<"find(\"667\"): "<<str.find("667")<<endl;
	
	size_t returnval = str.find("667");
	cout<<"returnval: "<<returnval<<endl;
	if(returnval == -1){
		cout<<"returnval == -1"<<endl;
	}
	if (returnval == string::npos){
		cout<<"returnval  == string::npos"<<endl;
	}
	if (str.find("66") == -1){
		cout<<"(str.find(\"66\") == -1) => true"<<endl;
	}

	cout<<"str.rfind(\"67\"): "<<str.rfind("67")<<endl;
	cout<<"str.data(): "<<str.data()<<endl;
	cout<<"str.c_str(): "<<str.c_str()<<endl;
	cout<<"str.find_first_of('4'): "<<str.find_first_of('4')<<endl;
	cout<<"str.find_first_of(\"521\"): "<<str.find_first_of("521")<<endl;
	cout<<"str.find_first_of(\"52\"): "<<str.find_first_of("52")<<endl;
	cout<<"str.find_first_of(\"935\"): "<<str.find_first_of("935")<<endl;

	cout<<endl<<"SUBSTR"<<endl;
	cout<<"str.substr(3,4): "<<str.substr(3,4)<<endl;
	cout<<"str.substr(3,110): "<<str.substr(3,110)<<endl;
	try{
		cout<<"str.substr(89,110): "<<str.substr(89,110)<<endl;
	}catch(exception e1){
		cout<<"catch(exception e1)"<<endl;
	}
	try{
		cout<<"str.substr(89,110): "<<str.substr(89,110)<<endl;
	}catch(...){
		cout<<"catch(...)"<<endl;
	}
	cout<<"str.substr(6,110): "<<str.substr(3,110)<<endl;
	cout<<"str.substr(6,string::npos): "<<str.substr(3,string::npos)<<endl;

	cout<<endl<<"INSERT"<<endl;
	cout<<"str.insert(3,\"new\"): "<<str.insert(3,"new")<<endl;
	try{
		cout<<"str.insert(string::npos,\"new\"): "<<str.insert(string::npos,"new")<<endl;
	}catch(exception& e){
		cout<<"catch(exception e) e.what():"<<e.what()<<endl;
	}

	str=base_str;
	str.insert(str.begin(),10,'n');
	cout<<"str.insert(str.end(),10,'n'): "<<str<<endl;
	str=base_str;
	str.insert(str.end(),10,'n');
	cout<<"str.insert(str.end(),10,'n'): "<<str<<endl;

	str=base_str;
	str.insert(4,"newstr",4);
	cout<<"str.insert(4,\"newstr\",4): "<<str<<endl;

	cout<<endl<<"REPLACE"<<endl;
	str=base_str;
	str.replace(4,3,"replacement");
	cout<<"str.replace(4,3,\"replacement\"): "<<str<<endl;
	str=base_str;
	str.replace(4,3,"replacement",0,5);
	cout<<"str.replace(4,3,\"replacement\",0,5): "<<str<<endl;

	cout<<endl<<"SWAP"<<endl;
	str=base_str;
	string str2 = "this is str2";
	cout<<"str1: "<<str<<endl;
	cout<<"str2: "<<str2<<endl;
	str.swap(str2);
	cout<<"after swapping: "<<endl;
	cout<<"str1: "<<str<<endl;
	cout<<"str2: "<<str2<<endl;
	cout<<endl<<"SWAP"<<endl;


	str=base_str;
	cout<<"str1: "<<str<<endl;
	str.pop_back();
	cout<<"str.pop_back(): "<<str<<endl;

	cout<<endl<<"ERASE"<<endl;
	cout<<"str1: "<<str<<endl;
	str=base_str;
	str.erase(2,2);
	cout<<"str.erase(2,2): "<<str<<endl;
	str=base_str;
	str.erase(str.begin()+3);
	cout<<"str.erase(str.begin()+3): "<<str<<endl;
	str=base_str;
	str.erase(str.begin()+3,str.end());
	cout<<"str.erase(str.begin()+3,str.end()): ["<<str<<"]"<<endl;
	str=base_str;
	str.erase(str.begin(),str.end());
	cout<<"str.erase(str.begin(),str.end()): ["<<str<<"]"<<endl;
	str=base_str;
	str.erase(str.begin(),str.end()-1);
	cout<<"str.erase(str.begin(),str.end()-1): ["<<str<<"]"<<endl;
	return 0;
}