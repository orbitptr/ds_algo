#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isLucky(int x){
    int digitcount = 0;
    int s1 = 0;
    int s2 = 0;
    int temp = x;
    while(temp>0){
        digitcount++;
        temp/=10;
    }
    temp = x;
    cout<<endl<<"digitcount :"<<digitcount;
    int middle = digitcount/2;
    bool isodd = ((digitcount%2) != 0);
    cout<<endl<<"isodd :"<<isodd;
    int currentdigitcount = 0;
    while(temp>0){
        int currentdigit = (temp%10);
        currentdigitcount++;
        if(isodd){
            if(currentdigitcount<middle){
                //right
                s2+=currentdigit;
            }else if(currentdigitcount>middle){
                //left
                s1+=currentdigit;
            }
        }else{
            if(currentdigitcount<=middle){
                //right
                s2+=currentdigit;
            }else{
                //left
                s1+=currentdigit;
            }
        }
        temp/=10;
    }
    return (s1 == s2);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x = 555555;
    // cin >> x;

    ++x;
    while(isLucky(x) == false){
        ++x;
    }
    cout<<x;
    return 0;
}
