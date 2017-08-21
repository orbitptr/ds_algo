#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
void printArr(int a[],int n){
	for(int i=0;i<n;i++){ 
		if(a[i]>0){
			cout<<endl<<" i:"<<i<<"   - "<<a[i];
		}
	}
	cout<<endl;
}

int getMaxDividedNum(int a[],int b[],int n, int max_n){	
	int va[max_n];
	int vb[max_n];
	for(int i=0;i<max_n;i++) va[i] = 0; //marking
	for(int i=0;i<max_n;i++) vb[i] = 0; //marking
	for(int i=0;i<n;i++) va[a[i]] = 1; //marking
	for(int i=0;i<n;i++) vb[b[i]] = 1; //marking
	// printArr(a,n);
	// printArr(b,n);
	// printArr(va,max_n);
	// printArr(vb,max_n);

	int *count = (int*) calloc(sizeof(int)*max_n);

	cout<<endl<< "max_n:"<<max_n;
	int size = sizeof(count)/sizeof(int);
	cout<<endl<<"size:"<<size<<endl;




	// for(int i=0;i<max_n;i++){ 
	// 	count[i] = 0;
	// }


	for(int i=1;i<max_n;i++){
		for(int j=i;j<max_n;j+=i){
			// if(va[j]>0) count[i]++;
			// if(vb[j]>0) count[i]++;
		}
	}
	// printArr(va,max_n);
	// printArr(vb,max_n);
	// printArr(count,max_n);
	return 0;
	// int p1=-1;
	// int p2=-1;
	// int gcd = -1;
	// for(int i=0;i<max_n;i++){
	// 	if(va[i]>1){
	// 		p1=i;
	// 	}else if(p1 == -1){
	// 		p1 = i;
	// 	}
	// 	// if(gcd<=va[i]){
	// 	// 	gcd = va[i];
	// 	// 	p1=i;
	// 	// }
	// }
	// gcd = -1;
	// for(int i=0;i<max_n;i++){
	// 	if(vb[i]>1){
	// 		p2=i;
	// 	}else if(p2 == -1){
	// 		p2 = i;
	// 	}
	// 	// if(gcd<=vb[i]){
	// 	// 	gcd = vb[i];
	// 	// 	p2=i;
	// 	// }
	// }
	// cout<<endl<<"P1:"<<p1;
	// cout<<endl<<"P2:"<<p2<<endl;

	// // free(va);
	// // free(vb);
	// return (p1+p2);
}

int main(){
	// int n;
	// cin >> n;
	// int a[n];
	// int b[n];
	// for(int i=0;i<n;i++) cin>>a[i];
	// for(int i=0;i<n;i++) cin>>b[i];


	int n=5;
	// int a[] = {3, 1 ,4 , 2,8};
	// int b[] = {5, 2, 12, 8, 3};
	
	
	int a[] = {13,11,7,2,1};
	int b[] = {26,13,7,2,1};
	
	// int b[] = {3, 7 ,11 , 13,17};
	// int a[] = {3, 7 ,11 , 13,17};
	
	int max_n = pow(10,6) +1;
	// int val_arr[max_n];
	int ans = getMaxDividedNum(a,b,n,max_n);
	cout<<ans;
	return 0;
}