/*
 * 1������Ĵ���ʽ��һ�����⣬��Ϊ���á� �� �ָ���ﴦ���ˡ�1   2�����������
 * 2������Ĵ�����ͨ����pat�Ĳ��Եģ��������������������⣬�ҽ���ͬһ��Ŀ¼�����ٽ�һ��Main1.java����������д����
 */
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str1 = sc.nextLine();
		String str[] = str1.split(" ") ;
		int a = Integer.parseInt(str[0]); //���������ǡ�1   2�� �����Ҫ����Խ����
		char op = str[1].charAt(0);
		int b = Integer.parseInt(str[2]);;
		int res = 0;
		
		switch(op){
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '/':
			res = a / b;
			break;
		case '*':
			res = a * b;
			break;
		case '%':
			res = a % b;
			break;
		default:
				System.out.print("ERROR");
				System.exit(0);
		}
		
		//res �����float ����double �⻹Ҫ������ܳ��ֽ���� -0.0�����
		System.out.print(res);
	}
}