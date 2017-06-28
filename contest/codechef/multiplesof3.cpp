#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int* array = NULL;
	int n,q,ans;
	int c,a,b;
	scanf("%d%d",&n,&q);
	array = (int*)calloc(sizeof(int),n);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&c,&a,&b);
		if(c==0){
			for(int j=a;j<=b;j++){
				array[j]++;
			}
		}else if(c==1){
			ans = 0;
			for(int j=a;j<=b;j++){
				if((array[j]%3) == 0){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}