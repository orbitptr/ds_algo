#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin>>n;
    int* a,*b;
    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>(a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>(b[i]);
    }
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());



    int maxGcd = -1;
    int p1,p2;
    int ai =0 ,bi = 0;
    int arrnum = (a[ai]>b[bi])?1:2;
    bool done = false;



    while(true){
        if((ai>=n) || (bi>=n)){
            break;
        }
        cout<<endl<<"ai-"<<ai<<" bi-"<<bi<<endl;    
        cout<<endl<<a[ai]<<"-"<<b[bi];
        if(a[ai]%b[bi] == 0){
            int gcd = min(a[ai],b[bi]);
            if(gcd > maxGcd){
                p1 = a[ai];
                p2 = b[bi];
                maxGcd = gcd;
            }
            break;
        }else{
            int currentgcd = gcd(a[ai],b[bi]);
            cout<<endl<<"currentgcd - "<<currentgcd;
            if(currentgcd > maxGcd){
                maxGcd = currentgcd;
                p1 = a[ai];
                p2 = b[bi];
            }
        }
        arrnum = (a[ai]>b[bi])?1:2;
        if((ai==(n-1)) && (bi==(n-1))){
            cout<<endl<<"debug 3";    
            break;
        }else
        if(ai==(n-1) && arrnum == 1){
            cout<<endl<<"debug 1";    
            arrnum = 2;
        }else
        if(bi==(n-1) && arrnum == 2){
            cout<<endl<<"debug 2";    
            arrnum = 1;
        }  


        if(arrnum == 1){
            ai++;
        }else{
            bi++;
        }
    }
    cout<<endl<<"p1-"<<p1<<" p2-"<<p2<<endl;
    // p1= a[ai];
    // p2= b[bi];
    cout<<(p1+p2);
    return 0;
}
