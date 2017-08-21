public class Numerology{
	public static void main(String args[]){
		char map[][] = {{'A','I','J','Q','Y'},
				{'B','K','R'},
				{'C','G','L','S'},
				{'D','M','T'},
				{'H','E','N','X'},
				{'U','V','W'},
				{'O','Z'},
				{'P','F'}};
		int num = 0;
		System.out.println(args);
		System.out.println(args.length);
		String input = args[0];
		
		input = input.toUpperCase().trim();
		for(int k=0;k<input.length();k++){
			boolean done = false;
			for(int i=0;i<map.length;i++){
				for(int j=0;j<map[i].length;j++){
					if(input.charAt(k) == map[i][j]){
						num+=(i+1);
						done = true;
						break;
					}
					if(done) break;
				}
			}
		}
		System.out.println(input + ": "+ num);
		System.out.println("Name: " + args[0] + ": "+ num+" => " + digitSum(num));
	}

	public static int digitSum(int num){
	        int sum = 0;
	        while (num > 0) {
	            sum = sum + num % 10;
	            num = num / 10;
	        }
	        return sum;
	}
}