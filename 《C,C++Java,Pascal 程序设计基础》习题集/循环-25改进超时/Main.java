/*
 * 1,��һ���汾֮������һ��case���г�ʱ���������м���BigDecimal�������� ��������˴����ർ�µ�
 * 2, ����ȥ����Ӧ�Ĵ���ͨ���˲��ԣ�����Ҳ�ܹ�����java ����С���ĵ���֮������˵�����������һ��double �ȽϾ��鷳��
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