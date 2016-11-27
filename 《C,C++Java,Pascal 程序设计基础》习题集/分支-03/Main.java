import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int op = in%5; 
		
		if(op >= 1 && op <= 3){
			System.out.print("Fishing");
		}else{
			System.out.print("Drying");			
		}
		System.out.print(" in day " + in);
	}
}