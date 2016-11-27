import java.text.DecimalFormat;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		float mile = sc.nextFloat(), time = sc.nextFloat(), sum = 0;
		float bound1 = 10, bound2 = (10 - 3) * 2 + bound1; 
		
		sum += 2*(int)(time/5);
		if(mile <= 3){
			sum += bound1;
		}else if(mile <= 10){
			sum += bound1 + (mile - 3)*2;
		}else{
			sum += bound2 + (mile - 10)*3;
		}
		
		DecimalFormat df = new DecimalFormat("#");
		System.out.print(df.format(sum));
	}
}