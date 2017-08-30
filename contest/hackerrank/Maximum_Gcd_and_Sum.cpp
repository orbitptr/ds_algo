#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  int r;
  while(b!=0 ){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int maxSumGcd(int a[],int b[],int n){
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    int lastGcd = -1;
    int p1=0,p2=0;
    int n1,n2;
    bool done = false;


    for(int i=0;i<n;i++){
        if(a[i] <= lastGcd){
            break;
        }else{
            for(int j=0;j<n;j++){                
                int n1,n2,r;
                bool shouldProceed = true;
                while(n2!=0 ){
                    r = n1 % n2;
                    n1 = n2;
                    n2 = r;
                    if(a <= lastGcd){
                        shouldProceed = false;
                        break;
                    }
                }
                if(!shouldProceed) boolreak;
                int currentGcd = n1;
                if(lastGcd<currentGcd){
                    lastGcd = currentGcd;
                    p1 = a[i];
                    p2 = b[j];
                }else if(lastGcd ==  currentGcd){
                    if((p1+p2) < (a[i]+b[j])){
                        p1 = a[i];
                        p2 = b[j];
                    }
                }
                if(currentGcd == min(a[i],b[j])){
                    break;
                }
                if(currentGcd > min(a[i],b[j])){
                    done = true;
                    break;
                }
            }
        }
        if(done) break;
    }
    return (p1+p2);
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
    int ans = maxSumGcd(a,b,n);    
    cout<<ans;
    return 0;
}
