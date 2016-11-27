import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, j, N = sc.nextInt();
		
		for(i = 1; i <= N; i++){
			for(j = 1; j <= i; j++){
				System.out.printf("%d*%d=%-4d", j, i, j*i);
			}
			System.out.print("\n");
		}		
	}
}