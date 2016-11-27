import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble();
		double res;

		if (x <= 15) {
			res = 4 * x / 3;
		} else {
			res = 2.5 * x - 17.5;
		}
		//DecimalFormat df = new DecimalFormat("#.00"); //这里如果写的是#.00 可能会打印出 .00 的结果。
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print(df.format(res));
	}
}