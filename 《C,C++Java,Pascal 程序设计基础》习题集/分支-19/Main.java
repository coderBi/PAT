import java.text.DecimalFormat;
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double res, mul = 0.53, up = 0.05, num = sc.nextDouble();
		
		if(num < 0){
			System.out.print("Invalid Value!");
			System.exit(0);
		}
		
		if(num <= 50){
			res = mul * num;
		}else{
			res = 50 * mul + (mul + up)*(num - 50);
		}
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print("cost = " + df.format(Main.GetPrecision(res)));
	}
	
	public static double GetPrecision(double x){
		if(x > -0.005 && x < 0.005){
			return 0;
		}
		return x;
	}
}