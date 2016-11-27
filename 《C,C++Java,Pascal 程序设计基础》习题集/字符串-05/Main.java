import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		StringBuffer str = new StringBuffer(sc.nextLine());
		int bits = sc.nextInt(); 
		
		bits %= str.length();
		String subStr = str.substring(0, bits);
		str.replace(0, str.length() - bits, str.substring(bits));
		str.replace(str.length() - bits, str.length(), subStr);
		System.out.print(str);
	}
}