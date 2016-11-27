/*
 * 1��������һ��caseû��ͨ���������ж��������x = (double) fz / fm;  ֱ�ӽ���double���㶪ʧ���ȵ��µ�
 * 2����һ���汾������BigDeciaml��������double����  ���������java�еľ��ȶ�ʧ
 */
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		double threshold = sc.nextDouble();
		double res = 0, x;
		int i, fm = 1, fz = 1;

		for (i = 1;; i++) {
			x = (double) fz / fm;  //�����double������ܶ�ʧ����
			res += x;
			if (x < threshold) {
				break;
			}
			fz *= i;
			fm *= (2 * i + 1);
		}
		DecimalFormat df = new DecimalFormat("0.000000");
		System.out.print(df.format(GetPrecision(2 * res)));
	}

	static double GetPrecision(double x) {
		if (x > -0.0000005 && x < 0.0000005) {
			return 0;
		}
		return x;
	}
}