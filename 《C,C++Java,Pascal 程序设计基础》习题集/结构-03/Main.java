import java.text.DecimalFormat;
import java.util.Scanner;

public class Main{
	static class Point{
		double x;
		double y;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Point v1 = new Point(), v2 = new Point();
		v1.x = sc.nextDouble();
		v1.y = sc.nextDouble();
		v2.x = sc.nextDouble();
		v2.y = sc.nextDouble();
		
		double a = v1.x + v2.x;
		double b = v1.y + v2.y;
		
		DecimalFormat df = new DecimalFormat("0.0");
		System.out.print("(" + df.format(getPrecision(a)) + ", " + df.format(getPrecision(b)) + ")");
	}
	
	static double getPrecision(double x){
		if(x > -0.05 && x < 0.05){
			return 0;
		}
		return x;
	}
}