/*
 * 1������֮ǰ�и�caseͨ������ԭ���Ǵ�ӡ���ܳ��� -0.00������� ����Ľ������������������һ������GetPrecision
 *  ��ʵ����Ҫ���� ��-floor�� floor��֮�����ݵ�����
 */
import java.text.DecimalFormat;
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		double x, y;
		
		if(a == 0 && b == 0 && c == 0){
			System.out.print("Zero Equation");
			System.exit(0);
		} else if(a == 0 && b == 0 && c != 0){
			System.out.print("Not An Equation");
			System.exit(0);
		}
		
		DecimalFormat df = new DecimalFormat("0.00");
		if(a == 0){
			x = (-1)*c/b;
			System.out.print(df.format(Main.GetPrecision(x)));
		} else{
			x = (-1)*b/(2*a);
			double s = x*x - c/a;
			
			if(s == 0){
				System.out.print(df.format(Main.GetPrecision(x)));
			} else if(s > 0){
				y = Math.sqrt(s);
				System.out.print(df.format(Main.GetPrecision(x + y)) + '\n' + df.format(Main.GetPrecision(x - y)));
			} else{
				y = Math.sqrt(-s);
				System.out.print(df.format(Main.GetPrecision(x)) + "+"  + df.format(Main.GetPrecision(y)) + "i\n" + df.format(Main.GetPrecision(x)) + "-"  + df.format(Main.GetPrecision(y)) + "i");
			}
		}
	}
	
	//���������ר��Ϊ�˽�����ܳ���-0.00��ӡ��
	public static double GetPrecision(double x){
		if(x > -0.005 && x < 0.005){  
			return 0;
		} else{
			return x;
		}
	}
}