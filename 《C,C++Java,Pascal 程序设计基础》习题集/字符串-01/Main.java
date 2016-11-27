import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		char c = sc.nextLine().charAt(0);
		int i;
		
		for(i = 0; i < str.length(); i++){
			if(str.charAt(i) == c){
				break;
			}
		}
		
		if(i == str.length()){
			System.out.print("Not found");
		} else{
			for(; i < str.length(); i++){
				System.out.print(str.charAt(i));
			}
		}
	}
}