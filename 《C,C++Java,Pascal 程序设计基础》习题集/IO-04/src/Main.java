import java.text.DecimalFormat;
import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		float f1, f2;
		int in;
		String c;
		
		DecimalFormat df = new DecimalFormat("#.00");  //��򵥵ķ���������һ��DecimalFormat�����ʽ����round����ʵ��Ҫ����Ϊβ��0���ܱ���
		Scanner sc =  new Scanner(System.in);
		String str[] = sc.nextLine().split(" ");
		f1 = Float.parseFloat(str[0]);
		in = Integer.parseInt(str[1]);
		c = str[2];
		f2 = Float.parseFloat(str[3]);
		System.out.print(c + " " + in + " " + df.format(f1) + " " + df.format(f2));
	}

}
