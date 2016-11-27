/*
 * 去掉之后通过了所有测试
 */
import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, N = sc.nextInt();
		double fz = 2, fm = 1;
		double res = 0;

		for (i = 1; i <= N; i++) {
			res += fz/fm;
			double sum = fz + fm;
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
	
}