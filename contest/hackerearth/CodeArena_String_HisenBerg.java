/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/
//import for Scanner and other utility classes
import java.util.*;


class CodeArena_String_HisenBerg {
    public static void main(String args[] ) throws Exception {
        Scanner sn = new Scanner(System.in);
        int n=sn.nextInt();
        String strs[] = new String[n];
        for(int i=0;i<n;i++){
            strs[i] = sn.next().trim();
        }
        int visited[] = new int[n];
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            String current = strs[i];
            visited[i] = 1;
            for(int k=0;k<n;k++){
                if(visited[k]==0){
                    int temp = possibleComb(k,current,strs,n,visited);
                    if(temp>ans){
                        ans = temp;
                    }
                }
            }
        }
        System.out.println("ans:"+ans);
    }
        
    
    
    public static int possibleComb(int i,String last,String strs[],int n,int visited[]){
        visited[i] = 1;
        System.out.println("i:"+i);
        String current = strs[i];
        int subStart = isC(last,current);
        System.out.println("subStart:"+subStart);
        int currentMax=0;
        int lengthSoFar=0;
        int max_previousMerge = 0;
        if(subStart != -1){
            lengthSoFar = last.length() - (last.length()-subStart);
            for(int k=0;k<n;k++){
                if(visited[k]==0){
                    int temp = possibleComb(k,current,strs,n,visited);
                    if(max_previousMerge<temp){
                        max_previousMerge = temp;
                    }
                }
            }
        }
        visited[i]=0;
        lengthSoFar +=max_previousMerge;
        return lengthSoFar;
    }

    public static int isC(String s1,String s2){
        int result =-1;
        boolean isMatch = false;
        int s2c = 0;
        for(int i=0;i<s1.length();i++){
            if((s2c < s2.length()) && (s1.charAt(i) == s2.charAt(s2c))){
                if(result== -1){
                    result  = i;
                }
                isMatch = true;
                s2c++;
            }else {
                if(isMatch){
                    return -1;
                }
            }
        }
        return result;
    }
}
