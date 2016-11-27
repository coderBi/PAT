import java.util.Scanner;
import java.text.DecimalFormat;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, j, n = sc.nextInt();
		int ad, res = 0;
		
		for(i = 1; i <= n; i++){
			ad = 1;
			for(j = 1; j <= i; j++){
				ad *= 2;
			}
			res += ad;	
		}
		System.out.print("sum = " + res);
	}
	
}