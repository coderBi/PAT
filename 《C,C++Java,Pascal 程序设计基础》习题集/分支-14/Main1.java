/*
 * ������Ȼ������ ��1   2������������ǿ��Է���javaд����̨Զû��C��ô���㡣
 */
import java.util.Scanner;


class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int a = 0, b = 0, i, flag = 1;
		char op = ' ';
		int res = 0;
		
		for(i = 0; i < str.length() && str.charAt(i) == ' '; i++) {}
		if(str.charAt(i) == '-'){
			flag = -1;
			i++;
		}
		for(; i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9'; i++){
			a *= 10;
			a += str.charAt(i) - '0';
		}
		a *= flag;
		i++; // �����ո�
		if(i < str.length()){
			op = str.charAt(i);
		}
		i += 2;
		flag = 1;
		if(str.charAt(i) == '-'){
			flag = -1;
			i++;
		}
		for(; i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9'; i++){
			b *= 10;
			b += str.charAt(i) - '0';
		}
		b *= flag;
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