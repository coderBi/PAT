import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, length = str.length(), flag = 1, res = 0;

		for (i = 0; i < length; i++) {
			char ch = str.charAt(i);
			if (ch == '#') {
				break;
			} else if (ch == '-') {
				flag = -1;
				i++;
				break;
			} else if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')
					|| (ch >= 'a' && ch <= 'f')) {
				break;
			}
		}

		for (; i < length; i++) {
			char ch = str.charAt(i);
			if (ch == '#') {
				break;
			}
			if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')
					|| (ch >= 'a' && ch <= 'f')) {
				res *= 16;
				res += Character.getNumericValue(ch);
			}
		}
		System.out.print(res * flag);
	}
}