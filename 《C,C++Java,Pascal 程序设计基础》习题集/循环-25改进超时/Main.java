/*
 * 1,上一个版本之所以有一个case运行超时，怀疑是中间用BigDecimal来做运算 由于运算此处过多导致的
 * 2, 这里去掉相应的处理，通过了测试，但是也能够看出java 处理小数的蛋疼之处。简单说这里如果加入一个double 比较就麻烦了
 */
import java.util.Scanner;
import java.text.DecimalFormat;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, n = sc.nextInt();
		double ad, res = 0;
		
		for(i = 1; i <= n; i++){
			ad = 1.0/(2*i - 1);
			res += ad;
		}
		System.out.print("sum = " + new DecimalFormat("0.000000").format(res));
	}
	
}