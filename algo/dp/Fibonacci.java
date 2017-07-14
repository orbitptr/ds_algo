/* Java program for Tabulated version */
public class Fibonacci
{
  int fib(int n)
  {
    int f[] = new int[n+1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
          f[i] = f[i-1] + f[i-2];
    return f[n];
  }

  int fibR(int i,int n,int x_2, int x_1){
    int current = x_1+ x_2;
    i++;
    if(i==n){
      return current;
    }else{
      return  fibR(i,n,x_1,current);
    }
  }
 
  public static void main(String[] args)
  {
    Fibonacci f = new Fibonacci();
    int n = 40;
    System.out.println("Fibonacci number using iter is " + " " + f.fib(n));
    System.out.println("Fibonacci number using recu is " + " " + f.fibR(1,n,0,1));
  } 
}