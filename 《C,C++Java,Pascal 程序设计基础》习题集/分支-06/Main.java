import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt(), pos;
		char res[] = { 'E', 'D', 'C', 'B', 'A' };

		if (in >= 100) {
			pos = 4;
		} else if (in < 60) {
			pos = 0;
		} else{
			in -= 60;
			pos = in/10 + 1;
		}
		System.out.print(res[pos]);
	}
}