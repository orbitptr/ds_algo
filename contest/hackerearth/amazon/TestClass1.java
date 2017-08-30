/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/
//import for Scanner and other utility classes
// import java.util.*;


// class TestClass1 {
//     public static void main(String args[] ) throws Exception {
//     }
// }


/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/
//import for Scanner and other utility classes
import java.util.*;
import java.math.BigInteger;

class TestClass1 {
    public static void main(String args[] ) throws Exception {
         Scanner sn = new Scanner(System.in);
        int n = sn.nextInt();
        BigInteger ans = new BigInteger("1");
        long a[] = new long[n];
        for(int i=0;i<n;i++){
            a[i] = sn.nextInt();
            //System.out.println("a[i]:"+a[i]);
            ans = ans.multiply(BigInteger.valueOf(a[i]+1));
            a[i] = ((a[i]/2) +1);
            
        }
        //System.out.println(ans);
        BigInteger evensum = new BigInteger(String.valueOf(a[0]));
        for(int i=1;i<n;i++){
            evensum.multiply(BigInteger.valueOf((long)Math.pow(2,a[i])));
        }
        ans= ans.add(evensum);
        System.out.println(ans);
    }
}
