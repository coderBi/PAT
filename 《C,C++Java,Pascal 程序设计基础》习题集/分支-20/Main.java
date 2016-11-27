import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int res;
		
		if(in < 0){
			res = -1;
		} else if(in == 0){
			res = 0;
		} else{
			res = 1;
		}
		
		System.out.print("sign(" + in + ") = " + res);
	}
}