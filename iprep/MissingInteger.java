import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class MissingInteger{
	UtilClass ut=null;
	void init(){
		this.ut = new UtilClass();
	}
	public class UtilClass{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String gets() throws Exception{return br.readLine().trim();}
		int getint() throws Exception {return Integer.parseInt(gets());}
		int[] getarray() throws Exception{			
			String line = gets();
			String elems[]=line.split(" ");
			if(elems != null && elems.length >0){
				int size=elems.length;
				int arr[] = new int[size];
				for(int i=0;i<elems.length;i++){
					arr[i] = Integer.parseInt(elems[i]);
				}
				return arr;
			}else{
				return null;
			}
		}
	}
	public static void main (String args[]) throws Exception {new MissingInteger().mainFun(args);}

	public  void puts(String s){System.out.println(s);}
	public  void puts(int a[]){
		put("\n[");
		int n=a.length;
		for(int i=0;i<n;i++) put(String.valueOf(a[i])+" ");
		put("]");
	}
	public  void puts(int s){puts(String.valueOf(s));}
	public  void puts(long s){puts(String.valueOf(s));}
	public  void puts(float s){puts(String.valueOf(s));}
	public  void puts(double s){puts(String.valueOf(s));}

	public  void put(String s){System.out.print(s);}
	public  void put(int s){put(String.valueOf(s));}
	public  void put(long s){put(String.valueOf(s));}
	public  void put(float s){put(String.valueOf(s));}
	public  void put(double s){put(String.valueOf(s));}
	public  int getint() throws Exception {if(this.ut!=null) return ut.getint();return -1;}
	public  String gets() throws Exception {if(this.ut!=null) return ut.gets();return null;}
	public  int[] getarray() throws Exception {if(this.ut!=null) return ut.getarray();return null;}
	
	public void mainFun(String args[]) throws Exception {
		 init();
		int t = getint();
		while((t--)>0){
			int n = getint();
			int[] input = getarray();
			puts(input);
		}
	}

}
