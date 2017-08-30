import java.util.*;
class Rhezo {
    public static int formNumber(String number,int l,int r){
        String substring = number.substring(l-1,r);
        return Integer.parseInt(substring);
    }
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        String number = s.nextLine().trim();
        int q = s.nextInt();
        int l,r;
        int num;
        for(int k=0;k<q;k++){
            l=s.nextInt();
            r=s.nextInt();
            num = formNumber(number,l,r);
            if(num%7==0){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }
}
