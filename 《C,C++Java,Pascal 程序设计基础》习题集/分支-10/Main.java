import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble();
		double res, mul = 0;

		if (x <= 1600) {
			mul = 0;
		} else if (x <= 2500) {
			mul = 0.05;
		} else if (x <= 3500) {
			mul = 0.1;
		} else if (x <= 4500) {
			mul = 0.15;
		} else {
			mul = 0.2;
		}
		DecimalFormat df = new DecimalFormat("0.00");
		if (x > 1600) {
			res = Double.parseDouble(df.format(mul * (x - 1600)));
		} else { //之前不是这样写的，是0*(x - 1600) 这样可能出现结果是 -0.00的情况
			res = 0;
		}

		System.out.print(df.format(res));
	}
}