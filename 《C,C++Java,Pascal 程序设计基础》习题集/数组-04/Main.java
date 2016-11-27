import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int i, arr[] = new int[n];

		for(i = 0; i < n; i++){
			arr[i] = sc.nextInt();
		}
		
		for(i = 0; i < n; i++){
			if(arr[i] == x){
				break;
			}
		}
		
		if(i >= n){
			System.out.print("Not Found");
		} else{
			System.out.print(i);
		}
	}
}