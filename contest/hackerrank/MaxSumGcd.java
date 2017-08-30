import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class MaxSumGcd {

    static int maximumGcdAndSum(int[] A, int[] B) {
        Arrays.sort(B,new Comparator<int>{
            public int compare(int a,int b){
                return b-a;
            }
        });
        System.out.println(Arrays.toString(A));
        System.out.println(Arrays.toString(B));
        return 0;
    }

    public static void main(String[] args) {
        // Scanner in = new Scanner(System.in);
        // int n = in.nextInt();
        // int[] A = new int[n];
        // for(int A_i = 0; A_i < n; A_i++){
        //     A[A_i] = in.nextInt();
        // }
        // int[] B = new int[n];
        // for(int B_i = 0; B_i < n; B_i++){
        //     B[B_i] = in.nextInt();
        // }
        int A[] = {3,2,1,4,8};
        int B[]  = {8,12,5,3,2};
        int res = maximumGcdAndSum(A, B);
        System.out.println(res);
    }
}
