import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t1 = sc.nextInt();
		int t2 = sc.ne
		double res, mul = 0;

		if (t1 < 5) {
			mul = 30;
		} else{
			mul = 50;
		}
		
		if (t2 <= 40){
			res = mul * t2;
		} else {
			res = mul * 40 + mul*1.5*(t2 - 40);
		}
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print(df.format(res));
	}
}