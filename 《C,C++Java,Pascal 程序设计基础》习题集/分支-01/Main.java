import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		
		if(in > 60){
			System.out.print("Speed: " + in + " - Speeding");
		}else{
			System.out.print("Speed: " + in + " - OK");			
		}
	}
}