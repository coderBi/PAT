/*
 * 这道题真心要吐槽啦，下面用BigDecimal多复杂！！！ 不用好像有个case通过了
 */
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i;
		double arr[] = new double[6];
		double a1, b1, a2, b2, L, A;
		
		for(i = 0; i < 6; i++){
			arr[i] = sc.nextDouble();
		}
		a1 = subStract(arr[2], arr[0]);
		a2 = subStract(arr[4], arr[0]);
		b1 = subStract(arr[3], arr[1]);
		b2 = subStract(arr[5], arr[1]);
		if((a1 == 0 && a2 == 0) || (a1 != 0 && a2 != 0 && divide(b1, a1) == divide(b2, a2))){
			System.out.print("Impossible");
			System.exit(0);
		}
		double l1 = Math.sqrt(add(mul(a1, a1), mul(b1, b1)));
		double l2 = Math.sqrt(add(mul(a2, a2), mul(b2, b2)));
		double a3 = subStract(a1, a2);
		double b3 = subStract(b1, b2);
		double l3 = Math.sqrt(add(mul(a3, a3), mul(b3, b3)));
		L =  add(add(l1, l2), l3);
		double cos = divide(add(mul(a1, a2), mul(b1, b2)), mul(Math.sqrt(add(mul(a1, a1), mul(b1, b1))),  Math.sqrt(add(mul(a2, a2), mul(b2, b2)))));
		A = mul(Math.sqrt(add(mul(a1, a1), mul(b1, b1))),  Math.sqrt(add(mul(a2, a2), mul(b2, b2)))) * Math.sqrt(subStract(1.0, cos*cos))/2;
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print("L = " + df.format(L) + ", A = " + df.format(A));
	}
	
	static double add(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.add(bd2).doubleValue();
	}
	
	static double subStract(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.subtract(bd2).doubleValue();
	}
	
	static double mul(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.multiply(bd2).doubleValue();
	}
	
	static double divide(double d1, double d2){
		BigDecimal bd1 = new BigDecimal(String.valueOf(d1));
		BigDecimal bd2 = new BigDecimal(String.valueOf(d2));
		return bd1.divide(bd2, 16, RoundingMode.HALF_UP).doubleValue();
	}
}