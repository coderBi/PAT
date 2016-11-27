import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, N = sc.nextInt();
		int front = 1;
		
		for(i = 1; i < N; i++){
			front *= 10;
		}
		
		for(i = front; i < front*10; i++){
			int sum = 0, rem = i;
			int j, ad = 1;
			while(rem/10 != 0){
				ad = 1;
				for(j = 0; j < N; j++){
					ad *= rem%10;
				}
				sum += ad;
				rem /= 10;
			}
			ad = 1;
			for(j = 0; j < N; j++){
				ad *= rem;
			}
			sum += ad;
			
			if(sum == i){
				System.out.println(i);
			}
		}
	}
}