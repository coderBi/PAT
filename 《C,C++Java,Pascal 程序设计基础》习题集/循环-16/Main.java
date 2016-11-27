import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i, sum = 1;

		for (i = 1; i <= n - 1; i++) {
			sum++;
			sum *= 2;
		}
		System.out.print(sum);
	}

}