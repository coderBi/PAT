import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;
import java.text.DecimalFormat;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, n = sc.nextInt();
		double ad, res = 0;
		
		for(i = 1; i <= n; i++){
			ad = divideDouble(1, 2*i - 1);
			res = addDouble(res, ad);
		}
		System.out.print("sum = " + new DecimalFormat("0.000000").format(res));
	}
	
	static double addDouble(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(Double.toString(d1));
		BigDecimal bd2 = new BigDecimal(Double.toString(d2));
		return bd1.add(bd2).doubleValue();
	}
	
	static double divideDouble(int n1, int n2){
		BigDecimal bd1 = new BigDecimal(Integer.toString(n1));
		BigDecimal bd2 = new BigDecimal(Integer.toString(n2));
		return bd1.divide(bd2, 16, RoundingMode.HALF_UP).doubleValue();
	}
}