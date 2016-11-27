import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int U = sc.nextInt();
		int D = sc.nextInt();
		int i, height = 0;
		
		for(i = 0;;){
			i++;
			height += U;
			if(height >= N){
				break;
			}
			
			i++;
			height -= D;			
		}
		System.out.print(i);
	}
}