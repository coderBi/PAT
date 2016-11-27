/*
 * ��һ�Ȿ����û׼����javaͨ���ˣ���Ϊ�������double��ص�����ľ�ȷ����û�а취��֤�ģ����ϵ�������һ��������
 * Arith�������������ò��Ǻܷ���
 */
import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a3 = sc.nextDouble();
		double a2 = sc.nextDouble();
		double a1 = sc.nextDouble();
		double a0 = sc.nextDouble();
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double res;

		for (;;) {
			if (b - a < 0.01) {
				res = (a + b) / 2;
				break;
			}
			double mid = (a + b) / 2;
			double sum = a3 * mid * mid * mid + a2 * mid * mid + a1 * mid + a0;
			double cmp = a3 * a * a * a + a2 * a * a + a1 * a + a0;
			if ((sum > 0 && cmp > 0) || (sum < 0 && cmp < 0)) {
				a = mid;
			} else {
				b = mid;
			}
		}
		System.out.print(new DecimalFormat("0.00").format(res));
	}
}