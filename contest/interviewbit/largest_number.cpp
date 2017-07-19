//https://www.interviewbit.com/problems/largest-number/
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cmath>
using namespace std;

int getFirstDigit(int num,int digitcount){
    // cout<<endl<<"getFirstDigit  digitCount - " <<digitcount;
    int dividor = 1;
    digitcount--;
    while(digitcount--){
        dividor*=10;
    }
    // cout<<endl<<"getFirstDigit dividor - " <<dividor;
    return ((int)num/(int)dividor);
}

int countDigit(int number){
    int count = 0;
    while(number>0){
        // cout<<endl<<"number before division - "<< number;
        number/=10;
        count++;
        // cout<<endl<<"number after division - "<< number;
        // cout<<endl << typeid(number).name() << '\n';
    }
    return count;
    // cout<<endl<<"inside countDigit - "<<number;
    // int digits = 1, pten=10; while ( pten <= number ) { cout<<endl<<"1pten - "<<pten ;digits++; pten*=10; cout<<endl<<"2pten - "<<pten; }
    // return digits;
}

string largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector < vector <int> > > map; 
    
    vector<int>::const_iterator it;
    for(it=A.begin();it<A.end();it++){
        cout<<endl<<" current value is "<< (*it);
        int current = (int)(*it);
        int digitcount = countDigit(current);
        cout<<endl<<" digitcount - "<< (digitcount);
        int firstDigit = getFirstDigit(current,digitcount);
        cout<<endl<<"*****************firstDigit - "<< (firstDigit);
        



        if(firstDigit >= map.size()){
            vector< vector <int> > firstdigitlist;//  = NULL;
            map.insert(map.begin()+firstDigit,firstdigitlist);            
            return "asdsa";
        }
        if(digitcount>= map[firstDigit].size()){
            vector<int> digitcountlist;
            map[firstDigit].insert(map[firstDigit].begin()+digitcount,digitcountlist);
        }
        map[firstDigit][digitcount].push_back(current);
    } 
    return "test";
    
}


int main(){
    //int arr[] = {3, 30, 34, 5, 9};

    static const int arr[] =  {3, 30, 34, 5, 9};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    //vector<int> v(arr,(sizeof(arr)/sizeof(int)));
    largestNumber(vec);
    return 0;
}