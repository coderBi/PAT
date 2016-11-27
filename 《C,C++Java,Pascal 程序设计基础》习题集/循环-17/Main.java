import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, n1 = 0, n2 = 0;
		char op = '=';

		for (i = 0; i < str.length() && str.charAt(i) >= '0'
				&& str.charAt(i) <= '9'; i++) {
			n1 *= 10;
			n1 += str.charAt(i) - '0';
		}
		if (i < str.length()) {
			op = str.charAt(i);
		}
		while (i < str.length() && op != '=') {
			int j;
			for (j = i; j < str.length()
					&& (str.charAt(j) < '0' || str.charAt(j) > '9'); j++) {

			}
			if (j - i > 1) {
				System.out.print("ERROR");
				System.exit(0);
			}
			for (; j < str.length() && str.charAt(j) >= '0'
					&& str.charAt(j) <= '9'; j++) {
				n2 *= 10;
				n2 += str.charAt(j) - '0';
			}

			switch (op) {
			case '+':
				n1 += n2;
				break;
			case '-':
				n1 -= n2;
				break;
			case '*':
				n1 *= n2;
				break;
			case '/':
				if (n2 == 0) {
					System.out.print("ERROR");
					System.exit(0);
				}
				n1 /= n2;
				break;
			default:
				System.out.print("ERROR");
				System.exit(0);
				break;
			}
			if (j < str.length()) {
				op = str.charAt(j);
			}
			i = j;
			n2 = 0;
		}
		System.out.print(n1);
	}
}