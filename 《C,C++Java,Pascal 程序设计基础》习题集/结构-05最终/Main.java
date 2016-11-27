/*
 * 1������fz fm��Ϊint ֮�󣬻���ֻ�����һ��caseû��ͨ��
 * 2�����շ����������һ��caseû��ͨ����ӦΪ���ڽ�� 0/n û�д�������ȥ�ҹ�������ʵ�Ǵ��
 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, n = Integer.parseInt(sc.nextLine());
		Fraction arr[] = new Fraction[n];
		Fraction res = new Fraction();
		res.fz = 0;
		res.fm = 1;

		for (i = 0; i < n; i++) {
			arr[i] = new Fraction();
			String str[] = sc.next().split("/");
			arr[i].fz = Integer.parseInt(str[0]);
			arr[i].fm = Integer.parseInt(str[1]);
		}

		for (i = 0; i < n; i++) {
			add(res, arr[i]);
		}
		if (res.fz == 0) {
			System.out.print(res.fz);
		} else {
			res.fm *= n;
			int gy = getMaxGy(res.fz, res.fm);
			res.fz /= gy;
			res.fm /= gy;
			if(res.fm == 1){
				System.out.print(res.fz);
			} else {
				System.out.print(res.fz + "/" + res.fm);
			}
		}		
	}

	static void add(Fraction res, Fraction f) {
		res.fz = res.fz * f.fm + f.fz * res.fm;
		res.fm *= f.fm;
	}

	static int getMaxGy(int n1, int n2) {
		if (n1 < n2) {
			int temp = n1;
			n1 = n2;
			n2 = temp;
		}

		while (n1 % n2 != 0) {
			int temp = n1 % n2;
			n1 = n2;
			n2 = temp;
		}
		return n2;
	}
}

class Fraction {
	int fz;
	int fm;
}