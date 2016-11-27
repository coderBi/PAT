import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int tortoise = 0, rabbit = 0, i, j;

		for (i = 0;;) {
			for (; i + 10 <= t && tortoise >= rabbit; i += 10) {
				tortoise += 3 * 10;
				rabbit += 9 * 10;
			}

			if (tortoise >= rabbit) {
				tortoise += 3 * (t - i);
				rabbit += 9 * (t - i);
				break;
			}

			if (i + 30 <= t) {
				tortoise += 3 * 30;
				i += 30;
			} else {
				tortoise += 3 * (t - i);
				break;
			}
		}

		if (tortoise > rabbit) {
			System.out.print("@_@ " + tortoise);
		} else if (tortoise == rabbit) {
			System.out.print("-_- " + tortoise);
		} else {
			System.out.print("^_^ " + rabbit);
		}
	}

}