import java.text.DecimalFormat;
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble();
		double res;
		
		if(x < 0){
			res = (x + 1)* (x + 1) + 2*x + 1/x;
		} else{
			res = Math.sqrt(x);
		}
		
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print("f(" + df.format(x) + ") = " + df.format(res));
	}
}