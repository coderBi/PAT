import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, arr[] = new int[3], pos;
		char res[] = { 'A', 'B', 'C' };

		for (i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		if (arr[0] == arr[1]) {
			pos = 2;
		} else if (arr[0] == arr[2]) {
			pos = 1;
		} else {
			pos = 0;
		}

		System.out.print(res[pos]);
	}
}