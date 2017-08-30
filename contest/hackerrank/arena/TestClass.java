/* IMPORTANT: Multiple classes and nested static classes are supported */


// * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;


class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder bs = new StringBuilder(br.readLine());
        //int ba[] = bsToBa(bs);
        int q = Integer.parseInt(br.readLine());
        for(int t=0;t<n;t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            if(command == 0){
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                printBinaryRep(bs,start,end);
            }else if(command == 1){
                int index = Integer.parseInt(st.nextToken());
                if(bs.charAt(index) == '0') bs.setCharAt(index,'1'); 
                //if(ba[index] == 0) ba[index] = 1; 
            }
        }
    }
    
    public static int[] bsToBa(String bs){
        int result[] = new int[bs.length()];
        for(int i=0;i<bs.length();i++){
            if(bs.charAt(i) =='1')
            result[i] = 1;
            else result[i] = 0;
        }
        return result;
    }
    
    public static void printBinaryRep(String bs,int start,int end){
        /*long decimal = 0;
        int power = 0;
        for(int i=end;i>=start;i--){
            decimal = (long)(ba[i]*Math.pow(2,power));
            power++;
        }*/
        System.out.println(String.valueOf(Integer.parseInt(bs.substring(start,end+1),2)));
    }
}
