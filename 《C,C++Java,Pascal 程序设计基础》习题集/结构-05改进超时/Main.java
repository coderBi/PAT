/*
 * 1������Ĺ�֮����Ȼ���һ��caseû�г�ʱ�ˣ�����ȴ��ʾ�������
 * 2��Ϊ���ų����������ǽ����ӷ�ĸ��Ϊdouble��Ӱ�죬��һ���汾�����Ǹ�Ϊint
 */
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, n = Integer.parseInt(sc.nextLine());
		Fraction arr[] = new Fraction[n];
		Fraction res = new Fraction();
		res.fz = 0;
		res.fm = 1;
		
		for(i = 0; i < n; i++){
			arr[i] = new Fraction();
			String str[] = sc.next().split("/");
			arr[i].fz = Double.parseDouble(str[0]);
			arr[i].fm = Double.parseDouble(str[1]);
		}
		
		for(i = 0; i < n; i++){
			add(res, arr[i]);
		}
		res.fm *= n;
		double gy = getMaxGy(res.fz, res.fm);
		res.fz /= gy;
		res.fm /= gy;
		
		DecimalFormat df = new DecimalFormat("0");
		if(res.fm == 1){
			System.out.print(df.format(res.fz));
		} else {
			System.out.print(df.format(res.fz) + "/" + df.format(res.fm));
		}
	}
	
	static void add(Fraction res, Fraction f){
		res.fz = res.fz*f.fm + f.fz*res.fm;
		res.fm *= f.fm;
	}
	
	static double getMaxGy(double d1, double d2){
		if(d1 < d2){
			double temp = d1;
			d1 = d2;
			d2 = temp;
		}
		
		while(d1%d2 !=  0){
			double temp = d1%d2;
			d1 = d2;
			d2 = temp;
		}
		return d2;
	}
}

class Fraction{
	double fz;
	double fm;
}