/*
 * 1��������һ��caseûͨ����Ŀ����Ȼ��java��double ��������⣬���潫ֱ��������Ľ������½���һ���ļ���
 * 2��������������Ӧ��BigDecimal����double����ķ���������fz fm �ĳ�double��ʾ���ӿ��ܱ�ʾ�ķ�Χ
 * 3,���ﴦ��֮�����һ��case��ʱ�ˣ������Ǹ���n �ܴ���BigDecimal�����ʣ���һ���汾��ȥ��BigDecimal����
 */
import java.util.Scanner;
import java.text.DecimalFormat;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, N = sc.nextInt();
		double fz = 2, fm = 1;
		double res = 0;

		for (i = 1; i <= N; i++) {
			res = add(res, divide(fz, fm));
			double sum = add(fz, fm);
			fm = fz;
			fz = sum;			 
		}
		System.out.print(new DecimalFormat("0.00").format(GetPrecision(res)));
	}
	
	static double GetPrecision(double x){
		if(x > -0.005 && x < 0.005){
			return 0;
		}
		return x;
	}
	
	static double add(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.add(bd2).doubleValue();
	}
	
	static double divide(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.divide(bd2, 20, RoundingMode.HALF_UP).doubleValue();
	}
	
}