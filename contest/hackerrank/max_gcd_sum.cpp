#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
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
    int lastGcd = -1;
    int p1=0,p2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int currentGcd = gcd(a[i],b[j]); 
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
        }
    }
    cout<<endl<<"p1-"<<p1<<" p2-"<<p2<<endl;
    cout<<(p1+p2);
    return 0;
}
