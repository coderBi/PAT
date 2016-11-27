import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String in = sc.nextLine();
		String str[] = in.split(" ");
		int i, front;

		for (front = 0; front < str.length && str[front].equals("") == true; front++) {
		}

		if (front >= str.length) {
			System.exit(0);
		}
		for (i = str.length - 1; i > front; i--) {
			if (!str[i].equals("")) {
				System.out.print(str[i] + " ");
			}
		}

		System.out.print(str[front]);
	}
}