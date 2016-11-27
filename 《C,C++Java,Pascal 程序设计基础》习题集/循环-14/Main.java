import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		int m, n;

		if (M < N) {
			M ^= N;
			N ^= M;
			M ^= N;
		}
		m = M;
		n = N;
		while (m % n != 0) {
			int temp = n;
			n = m % n;
			m = temp;
		}
		System.out.print(n + " " + (M * N / n));
	}
}