import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, n = sc.nextInt();
		int ad = 1, res = 0;
		
		for(i = 1; i <= n; i++){
			ad *= i;
			res += ad;
		}
		System.out.print(res);
	}
}