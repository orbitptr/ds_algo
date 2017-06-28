import java.util.ArrayList;
class KMPAlgo{
	public static void main(String args[]){
		System.out.println("println");
		String text = "abcabcdababcdabcdabde";
		String pattern = "abcdabcdy";
		kmpAlgo(text,pattern);
	}

	public static void kmpAlgo(String text,String pattern){
		int[] maparray = getCalculatedMap(pattern);
		int patternPtr = 0;
		int match_start = -1;
		int match_end = -1;
		if(true) return;
		for(int i=0;i<text.length();i++){
			System.out.println("\n"+i);
			System.out.println(""+patternPtr);
			System.out.println(""+text.charAt(i));
			System.out.println(""+pattern.charAt(patternPtr));


			if(text.charAt(i)==pattern.charAt(patternPtr)){

				patternPtr++;
				System.out.println("Match");
				if(match_start == -1){
					match_start = i;
				}
				if(patternPtr == (pattern.length())){
					//full match
					match_end = i;
					patternPtr=0;
					System.out.println("==========full Match at:"+match_start+"-"+match_end);
					match_start = -1;
					match_end = -1;
				}
			}else{
				patternPtr = maparray[patternPtr]-1;
				if(patternPtr<0) patternPtr = 0;
				i--;
				System.out.println("MISmatch patternPtr:"+patternPtr);
			}
		}
	}

	public static int[] getCalculatedMap(String pattern){
		int[] maparray = new int[pattern.length()];
		int count = 0;
		int ptr=0;
		for(int i=1;i<pattern.length();i++){
			maparray[i] = count;
			if(pattern.charAt(i) == pattern.charAt(ptr)){
				count++;
				ptr++;
			}else{
				count=0;
				ptr=0;
			}
			
		}
		for(int i=0;i<maparray.length;i++){
			System.out.println(maparray[i]);
		}
		return maparray;
	}
}