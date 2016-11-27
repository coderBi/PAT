/*
 * 1，这里有一个case没有通过，初步判断是下面的x = (double) fz / fm;  直接进行double运算丢失精度导致的
 * 2，下一个版本将会用BigDeciaml类来处理double运算  这样来解决java中的精度丢失
 */
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		double threshold = sc.nextDouble();
		double res = 0, x;
		int i, fm = 1, fz = 1;

		for (i = 1;; i++) {
			x = (double) fz / fm;  //这里的double运算可能丢失精度
			res += x;
			if (x < threshold) {
				break;
			}
			fz *= i;
			fm *= (2 * i + 1);
		}
		DecimalFormat df = new DecimalFormat("0.000000");
		System.out.print(df.format(GetPrecision(2 * res)));
	}

	static double GetPrecision(double x) {
		if (x > -0.0000005 && x < 0.0000005) {
			return 0;
		}
		return x;
	}
}