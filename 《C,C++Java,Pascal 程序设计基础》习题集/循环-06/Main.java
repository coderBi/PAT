import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int count = 0, i;
		
		for(i = 0; i < str.length();){
			for(; i < str.length() && str.charAt(i) == ' '; i++){
	
			}
			
			if(i < str.length()){
				count++;
			}
			
			for(; i < str.length() && str.charAt(i) != ' '; i++){
				
			}
		}
		System.out.print(count);
	}
}