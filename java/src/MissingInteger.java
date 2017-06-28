import java.util.ArrayList;
public class MissingInteger{
	public static void main(String[] arg){
		ArrayList<Integer> a = new ArrayList();
		a.add(-2);
		a.add(-1);
		a.add(0);
		a.add(6);
		a.add(10);
		a.add(15);
		a.add(7);
		a.add(8);
		a.add(9);
		a.add(2);
		a.add(4);
		a.add(1);
		a.add(3);
		// a.add(4);
		// a.add(11);
		// a.add(12);
		// a.add(14);
		// a.add(13);
		firstMissingPositive(a);
	}
	public static int firstMissingPositive(ArrayList<Integer> a) {
	    int min = -1,max=-1,imgMax=-1,curr,i,diff=0,result=-1;
	    for(i=0;i<a.size();i++){
	        curr = a.get(i);
	        if(curr>0){
	            min=curr;
	            max=curr;
	            imgMax=curr;
	            diff=0;
	            break;
	        }
	    }
	    for(++i;i<a.size();i++){
	        curr = a.get(i);
	        if(curr>0){
	            if((min-1) == curr){
	                min=curr;
	            }
	            if((max+1) == curr){
	                max=curr;
	            }
	            if(curr<(min-1)){
	            		min=curr;
	            		int newDiff=Math.abs(curr-max)-1;
	            		diff+= (newDiff-1);
	            		max=curr;

	            }
	            if(curr<imgMax){
	            	diff--;
	            }
	            if(curr>imgMax){
	                int newDiff=Math.abs(curr-imgMax)-1;
	                diff+= (newDiff-1);
	                imgMax=curr;
	            }
	            if(diff==0){
	            	max=imgMax;
	            }
	        }
	    }
	    System.out.println("min:"+min+" max:"+max+" imgMax:"+imgMax+" diff:"+diff);
	    return result;
	}
}