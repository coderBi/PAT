import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int i, count = 0, sum = 0;
		
		for(i = m; i <= n; i++){
			if(IsPrime(i)){
				count++;
				sum += i;
			}
		}
		System.out.print(count + " " + sum);
	}
	
	static boolean IsPrime(int x){
		int i;
		if(x < 2){
			return false;
		}
		for(i = 2; i*i <= x; i++){
			if(x%i == 0){
				return false;
			}
		}
		return true;
	}
}