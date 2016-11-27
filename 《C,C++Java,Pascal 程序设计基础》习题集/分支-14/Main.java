/*
 * 1，这里的处理方式有一种问题，因为是用“ ” 分割，这里处理不了“1   2”的输入情况
 * 2，这里的代码是通过了pat的测试的，但是针对上面分析的问题，我将在同一个目录下面再建一个Main1.java，在里面重写本题
 */
import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str1 = sc.nextLine();
		String str[] = str1.split(" ") ;
		int a = Integer.parseInt(str[0]); //如果输入的是“1   2” 这里就要访问越界啦
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
		
		//res 如果是float 或者double 这还要处理可能出现结果是 -0.0的情况
		System.out.print(res);
	}
}