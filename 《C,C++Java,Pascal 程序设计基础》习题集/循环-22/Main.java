import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, n = sc.nextInt();
		
		if(n <= 2000 || n > 2100){
			System.out.print("Invalid year!");
			System.exit(0);
		}
		for(i = 2004; i <= n; i += 4){
			if(i%100 != 0 || i%400 == 0){
				System.out.println(i);
			}
		}
	}
}