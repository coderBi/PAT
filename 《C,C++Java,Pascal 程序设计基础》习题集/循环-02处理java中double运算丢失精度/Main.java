/*
 * 1，通过用相同逻辑的C语言代码测试，发现将i, fm = 1, fz = 1; 全部由int 改为 double可以通过测试，
 * 这里的结果也是一样
 * 2，这里猜测的原因是测试数据可能fm超过了int范围，但是在double高位的表示范围内
 */
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		double threshold = sc.nextDouble();
		double res = 0, x;
		double i, fm = 1, fz = 1;

		for (i = 1;; i++) {
			x = divide(fz, fm);
			res = add(res, x);
			if (subStract(x, threshold) < 0) {
				break;
			}
			fz *= i;
			fm *= (2 * i + 1);
		}
		DecimalFormat df = new DecimalFormat("0.000000");
		System.out.print(df.format(GetPrecision(mul(2.0, res))));
	}

	static double GetPrecision(double x) {
		if (x > -0.0000005 && x < 0.0000005) {
			return 0;
		}
		return x;
	}
	
	static double divide(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.divide(bd2, 20, RoundingMode.HALF_UP).doubleValue();
	}
	
	static double add(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.add(bd2).doubleValue();
	}
	
	static double subStract(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.subtract(bd2).doubleValue();
	}
	
	static double mul(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.multiply(bd2).doubleValue();
	}
}