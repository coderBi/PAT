import java.util.Scanner;

public class Main{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int i, sum = 0, count = 0;
		
		for(i = a; i <= b; i++){
			sum += i;
			count++;
			System.out.printf("%5d", i);
			if(count%5 == 0){
				System.out.print('\n');
			}
		}
		if(count%5 != 0){
			System.out.print('\n'); //���һ��û����ҲҪ����
		}
		System.out.print("Sum = " + sum);
	}
}