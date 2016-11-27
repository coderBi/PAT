import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int a1 = Integer.parseInt(str.split("/")[0]);
		int b1 = Integer.parseInt(str.split("/")[1]);
		str = sc.next();
		int a2 = Integer.parseInt(str.split("/")[0]);
		int b2 = Integer.parseInt(str.split("/")[1]);
		double d1 = divide(a1, b1);
		double d2 = divide(a2, b2);

		System.out.print(a1 + "/" + b1);
		if (d1 < d2) {
			System.out.print(" < ");
		} else if (d1 == d2) {
			System.out.print(" = ");
		} else {
			System.out.print(" > ");
		}
		System.out.print(a2 + "/" + b2);
	}

	static double divide(int n1, int n2) {
		BigDecimal bd1 = new BigDecimal(String.valueOf(n1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(n2));
		return bd1.divide(bd2, 16, RoundingMode.HALF_UP).doubleValue();
	}
}