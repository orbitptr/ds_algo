import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class KandenAlgo extends BaseJava{
	int maxSumBruteForce(int arr[]){
		Integer maxSum=null;
		int n=arr.length;
		for(int start=0;start<n;start++){
			for(int end=(start);end<n;end++){
				int currSum=0;
				puts(arr,start,end);
				for(int k=start;k<=end;k++){
					currSum+=arr[k];
				}
				if(maxSum == null){
					maxSum = currSum;
				}else if(maxSum<currSum){
					maxSum = currSum;
				}
			}			
		}
		return maxSum;
	}

	int maxSumKandenAlgo(int arr[]){
		if(arr == null || arr.length<=0) return 0;
		int graphEndingHere=arr[0];
		int graphSoFar = arr[0];
		for(int i=1;i<arr.length;i++){
			graphEndingHere = Math.max(arr[i],arr[i]+graphSoFar);
			graphSoFar=Math.max(graphSoFar,graphEndingHere);
		}
		return graphSoFar;
	}
	
	@Override
	public void mainFun(String args[]) throws Exception {
		puts("running");
		init();
		int t = getint();
		for(int k=1;k<=t;k++){
			int n=getint();
			int arr[] = getarray();
			puts(arr);
			puts("TestCase:"+k+":"+maxSumKandenAlgo(arr));
		}
	}

}
