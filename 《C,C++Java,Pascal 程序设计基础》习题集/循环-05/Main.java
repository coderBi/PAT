import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int i, a = 1, b = 1, sum = 0;
		
		if(N <= 1){
			System.out.print(1);
			System.exit(0);
		}
		
		for(i = 3;; i++){
			sum = a + b;
			if(sum >= N){
				break;
			}
			a = b;
			b = sum;
		}
		
		System.out.print(i);
	}
}