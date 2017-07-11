#include <iostream>
#include <string>
#include <list>
using namespace std;

int* calculateMap(string pattern){
	 int* maparray = (int*)malloc(sizeof(int)*(pattern.length()));
	 list<char> que;
	 int count = 0;
	 for(i=0;i<pattern.length();i++){
	 	que.push_back(char);
	 	
	 }
	 return maparray;
}

int main(){
	string text = "abcabcdababcdabcdabde";
	string pattern = "abcdabd";
	int *maparray =calculateMap(pattern);
	int i=0,patternPtr=0,match_start=-1,match_end=-1,k,j,last_occurance;
	cout<<text<<endl;
	cout<<pattern<<endl;
	for(i=0;i<text.length();i++){
		if(pattern.at(patternPtr) == text.at(i)){
			if(match_start == -1){
				match_start = i;
			}
			//match
			if((patternPtr+1) == (pattern.length())){
				//full match
				match_end=i;
				cout<<endl<<"Match from:"<<match_start<<":"<<match_end;
				match_start =-1;
				match_end=-1;
				patternPtr=0;
			}else{
				patternPtr++;
			}
		}else{
			//mismatch then adjust the pattern ptr
			//find the last occurance of the curent word
			last_occurance = -1;
			for(j=0;j<pattern.length();j++){
				if(pattern.at(j) == text.at(i)){
					last_occurance = j;
					break;
				}
			}
			if(last_occurance != -1){
				//found some occurance
				k=last_occurance-1;
				for(j=(patternPtr-1);(j>=0)&&(k>=0);){
					if(pattern.at(j) != pattern.at(k)){
						patternPtr = 0;
						match_start=-1;
						match_end=-1;
						continue;
					}
					j--;
					k--;
				}
				patternPtr=last_occurance+1;
				match_start= (i-last_occurance);
				match_end=-1;
			}else{
				patternPtr = 0;
			}

		}
	}
	return 0;
}