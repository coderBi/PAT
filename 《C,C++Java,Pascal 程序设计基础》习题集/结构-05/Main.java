/*
 * 1,这里有一个case超时,分析应该是这里做了n - 1 次的来回同分在化简
 * 2，接下来一个版本将不对中间结果进行化简
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
		
		for(i = 0; i < n; i++){
			arr[i] = new Fraction();
			String str[] = sc.next().split("/");
			arr[i].fz = Double.parseDouble(str[0]);
			arr[i].fm = Double.parseDouble(str[1]);
		}
		
		for(i = 1; i < n; i++){
			arr[0] = add(arr[0], arr[i]);
		}
		arr[0].fm *= n;
		double gy = getMaxGy(arr[0].fz, arr[0].fm);
		arr[0].fz /= gy;
		arr[0].fm /= gy;
		
		DecimalFormat df = new DecimalFormat("0");
		if(arr[0].fm == 1){
			System.out.print(df.format(arr[0].fz));
		} else {
			System.out.print(df.format(arr[0].fz) + "/" + df.format(arr[0].fm));
		}
	}
	
	static Fraction add(Fraction f1, Fraction f2){
		double gy = getMaxGy(f1.fm, f2.fm);
		double gb = (f1.fm * f2.fm) / gy;
		f1.fz = (f1.fz * gb / f1.fm) + (f2.fz * gb / f2.fm);
		f1.fm = gb;
		gy = getMaxGy(f1.fz, f1.fm);
		f1.fm /= gy;
		f1.fz /= gy;
		return f1;
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