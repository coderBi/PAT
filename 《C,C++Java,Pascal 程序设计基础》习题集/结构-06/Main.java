import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Plural p1 = new Plural();
		Plural p2 = new Plural();
		p1.real = sc.nextDouble();
		p1.imag = sc.nextDouble();
		p2.real = sc.nextDouble();
		p2.imag = sc.nextDouble();

		printP1P2(p1);
		System.out.print(" + ");
		printP1P2(p2);
		System.out.print(" = ");
		printRes(addPlural(p1, p2));

		printP1P2(p1);
		System.out.print(" - ");
		printP1P2(p2);
		System.out.print(" = ");
		printRes(subStractPlural(p1, p2));

		printP1P2(p1);
		System.out.print(" * ");
		printP1P2(p2);
		System.out.print(" = ");
		printRes(mulPlural(p1, p2));

		printP1P2(p1);
		System.out.print(" / ");
		printP1P2(p2);
		System.out.print(" = ");
		printRes(dividePlural(p1, p2));
	}

	static void printP1P2(Plural p) {
		p.real = getPrecision(p.real);
		p.imag = getPrecision(p.imag);
		DecimalFormat df = new DecimalFormat("0.0");
		if (p.imag >= 0) {
			System.out.print("(" + df.format(p.real) + "+" + df.format(p.imag)
					+ "i)");
		} else {
			System.out.print("(" + df.format(p.real) + df.format(p.imag)
					+ "i)");
		}
	}

	static Plural addPlural(Plural p1, Plural p2) {
		Plural res = new Plural();
		res.real = add(p1.real, p2.real);
		res.imag = add(p1.imag, p2.imag);
		return res;
	}

	static Plural subStractPlural(Plural p1, Plural p2) {
		Plural res = new Plural();
		res.real = subStract(p1.real, p2.real);
		res.imag = subStract(p1.imag, p2.imag);
		return res;
	}

	static Plural mulPlural(Plural p1, Plural p2) {
		Plural res = new Plural();
		res.real = subStract(mul(p1.real, p2.real), mul(p1.imag, p2.imag));
		res.imag = add(mul(p1.real, p2.imag), mul(p1.imag, p2.real));
		return res;
	}

	static Plural dividePlural(Plural p1, Plural p2) {
		Plural res = new Plural();
		double fm = add(mul(p2.real, p2.real), mul(p2.imag, p2.imag));
		res.real = add(mul(p1.real, p2.real), mul(p1.imag, p2.imag));
		res.imag = subStract(mul(p1.imag, p2.real), mul(p1.real, p2.imag));
		res.real = divide(res.real, fm);
		res.imag = divide(res.imag, fm);
		return res;
	}

	static double getPrecision(double x) {
		if (x > -0.05 && x < 0.05) {
			return 0;
		}
		return x;
	}

	static double add(double d1, double d2) {
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.add(bd2).doubleValue();
	}

	static void printRes(Plural res) {
		DecimalFormat df = new DecimalFormat("0.0");
		res.real = getPrecision(res.real);
		res.imag = getPrecision(res.imag);
		if (res.real != 0 && res.imag != 0) {
			if (res.imag >= 0) {
				System.out.println(df.format(res.real) + "+"
						+ df.format(res.imag) + "i");
			} else {
				System.out.println(df.format(res.real) + df.format(res.imag)
						+ "i");
			}

		} else if (res.real == 0 && res.imag == 0) {
			System.out.println("0.0");
		} else if (res.real == 0) {
			System.out.println(df.format(res.imag) + "i");
		} else {
			System.out.println(df.format(res.real));
		}
	}

	static double subStract(double d1, double d2) {
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.subtract(bd2).doubleValue();
	}

	static double mul(double d1, double d2) {
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.multiply(bd2).doubleValue();
	}

	static double divide(double d1, double d2) {
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.divide(bd2, 20, RoundingMode.HALF_UP).doubleValue();
	}
}

class Plural {
	double real;
	double imag;
}