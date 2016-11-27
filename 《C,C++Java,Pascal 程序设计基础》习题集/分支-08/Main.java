/*
 * 1,题目下面给出的例子说明未超速的条件是 < 而不是 <=
 * 2，float double 计算不应该带入不精确的数字，这也是下面第19行的意思
 */
import java.text.DecimalFormat;
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int speed = sc.nextInt();
		int maxS = sc.nextInt();
		double res, prt;
		
		DecimalFormat df = new DecimalFormat("#.00");
		//res = Float.parseFloat(df.format(speed/maxS -1)); //res 格式化处理的太早了，影响下面的结果
		res = (speed/(double)maxS) -1;
		res = Double.parseDouble(new DecimalFormat("#.0000").format(res)); //多取了两位小数，足以跟10%（0.01精度）进行比较啦
		prt = Double.parseDouble(df.format(res));
		//System.out.println((double)speed + " " + (double)maxS + " " + res);
		if(res < 10.0/100){
			System.out.print("OK");
		} else if(res < 50.0/100){			
			System.out.print("Exceed " + (int)(prt*100) + "%. Ticket 200");
		} else{
			System.out.print("Exceed " + (int)(prt*100) + "%. License Revoked");
		}
	}
}