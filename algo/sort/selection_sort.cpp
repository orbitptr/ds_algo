#include <iostream>
using namespace std;
void printArray(int a[],int n){
	cout<<endl<<"[";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"]";
}
void selectionSort(int a[],int n){
	for(int i=0;i<(n-1);i++){
		int minIndex = i;
		//cout<<endl<<"taking - "<<a[i];

		//trying to find the lowest value after this
		for(int j=(i+1);j<n;j++){
			if(a[j]<a[minIndex]){ // compare against the last lowest value
				minIndex = j; //update minIndex
			}
			//for 5 min element could be like 4,3,2 or 3,4,2 or 2,3,4
			//so its necessory to scan the whole remainging array
		}
		cout<<endl<<endl<<a[i]<<"<-->"<<a[minIndex];
		if(minIndex != i)
		{
			int temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
		printArray(a,n);
	}
}
int main(){
	int a[] = {4,5,3,2,1};
	int n = (sizeof(a)/sizeof(int));
	cout<<"size of array = "<< n;
	cout<<endl<<"before";
	printArray(a,n);
	selectionSort(a,n);
	cout<<endl<<"after";
	printArray(a,n);
	return 0;
}