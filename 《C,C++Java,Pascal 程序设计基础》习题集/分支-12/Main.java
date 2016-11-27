import java.text.DecimalFormat;
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t1 = sc.nextInt();
		int t2 = sc.nextInt();
		int hour, min, res;
		
		hour = t2/100 - t1/100;
		min = t2%100 - t1%100;
		if(min < 0){
			min += 60;
			hour--;
		}
		DecimalFormat df = new DecimalFormat("00");
		System.out.print(df.format(hour) + ":" + df.format(min));
	}
}