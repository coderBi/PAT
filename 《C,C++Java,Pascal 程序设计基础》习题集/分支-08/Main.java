/*
 * 1,��Ŀ�������������˵��δ���ٵ������� < ������ <=
 * 2��float double ���㲻Ӧ�ô��벻��ȷ�����֣���Ҳ�������19�е���˼
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
		//res = Float.parseFloat(df.format(speed/maxS -1)); //res ��ʽ�������̫���ˣ�Ӱ������Ľ��
		res = (speed/(double)maxS) -1;
		res = Double.parseDouble(new DecimalFormat("#.0000").format(res)); //��ȡ����λС�������Ը�10%��0.01���ȣ����бȽ���
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