import java.io.IOException;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int a, b;
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		Main cl = new Main();
		cl.Calculate(a, b);
	}

	public void Calculate(int a, int b){
		System.out.println(a + " + " + b + " = " + (a+b));
		System.out.println(a + " - " + b + " = " + (a-b));
		System.out.println(a + " * " + b + " = " + (a*b));
		System.out.println(a + " / " + b + " = " + (a/b));
	}
}
