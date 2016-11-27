import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int i;
		
		for(i = 2; i <= in - i; i++){
			if(IsPrime(i) && IsPrime(in -i)){
				break;
			}
		}
		
		System.out.print(in + " = " + i + " + " + (in -i));
	}

	public static boolean IsPrime(int num) {
		if (num < 2) {
			return false;
		}

		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}
}