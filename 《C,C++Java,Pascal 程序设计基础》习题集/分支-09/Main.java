import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double x = sc.nextDouble();
		double res;

		if (x <= 15) {
			res = 4 * x / 3;
		} else {
			res = 2.5 * x - 17.5;
		}
		//DecimalFormat df = new DecimalFormat("#.00"); //�������д����#.00 ���ܻ��ӡ�� .00 �Ľ����
		DecimalFormat df = new DecimalFormat("0.00");
		System.out.print(df.format(res));
	}
}