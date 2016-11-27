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

		int gy = getMaxGY(a1, b1);
		a1 /= gy;
		b1 /= gy;
		gy = getMaxGY(a2, b2);
		a2 /= gy;
		b2 /= gy;

		gy = getMaxGY(b1, b2);
		int gb = b1 * b2 / gy;
		a1 *= gb / b1;
		b1 = gb;
		a2 *= gb / b2;
		b2 = gb;

		a1 += a2;
		gy = getMaxGY(a1, b1);
		a1 /= gy;
		b1 /= gy;
		if (b1 == 1) {
			System.out.print(a1);
		} else {
			System.out.print(a1 + "/" + b1);
		}
	}

	static int getMaxGY(int x, int y) {
		if (x < y) {
			int temp = x;
			x = y;
			y = temp;
		}

		while (x % y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return y;
	}
}