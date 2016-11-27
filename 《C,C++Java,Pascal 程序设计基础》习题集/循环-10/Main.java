/*
 * 1，这里有一个case没通过，目测依然是java中double 运算的问题，下面将直接在这里改进，不新建另一个文件了
 * 2，这里除了添加相应的BigDecimal处理double运算的方法，还将fz fm 改成double表示增加可能表示的范围
 * 3,这里处理之后，最后一个case超时了，估计是给的n 很大用BigDecimal不合适，下一个版本将去掉BigDecimal处理
 */
import java.util.Scanner;
import java.text.DecimalFormat;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, N = sc.nextInt();
		double fz = 2, fm = 1;
		double res = 0;

		for (i = 1; i <= N; i++) {
			res = add(res, divide(fz, fm));
			double sum = add(fz, fm);
			fm = fz;
			fz = sum;			 
		}
		System.out.print(new DecimalFormat("0.00").format(GetPrecision(res)));
	}
	
	static double GetPrecision(double x){
		if(x > -0.005 && x < 0.005){
			return 0;
		}
		return x;
	}
	
	static double add(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.add(bd2).doubleValue();
	}
	
	static double divide(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.divide(bd2, 20, RoundingMode.HALF_UP).doubleValue();
	}
	
}