import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int i;
		
		for(i = m; i <= n; i++){
			printPerfectNum(i);
		}
	}
	
	static void printPerfectNum(int num){
		int arr[] = new int[num];
		int i, length = 0, sum = 0;
		
		if(num == 1){
			System.out.println("1 = 1");
			return;
		}
		
		//一开始以为下面写i*i <= num 是合适的，但是仔细一想，应该是 i <= num/2
		for(i = 1; i <= num/2; i++){
			if(num%i == 0){
				arr[length++] = i;
			}
		}
		
		for(i = 0; i < length; i++){
			sum += arr[i];
		}
		if(sum != num){
			return;
		}
		
		System.out.print(num + " = ");
		for(i = 0; i < length -1; i++){
			System.out.print(arr[i] + " + ");
		}
		System.out.println(arr[length - 1]);
	}
}