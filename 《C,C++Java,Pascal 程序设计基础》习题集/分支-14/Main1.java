/*
 * 这里虽然处理了 “1   2”的情况，但是可以发现java写控制台远没有C那么方便。
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
		i++; // 跳过空格
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
		
		//res 如果是float 或者double 这还要处理可能出现结果是 -0.0的情况
		System.out.print(res);
	}
}