import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, j, count = 0, N = sc.nextInt();
		
		for(i = 1; i*i <= N/2; i++){
			for(j = i; i*i + j*j < N; j++){
			}
			if(i*i + j*j == N){
				System.out.println(i + " " + j);
				count++;
			}
		}
		if(count == 0){
			System.out.println("No Solution");
		}
	}
}