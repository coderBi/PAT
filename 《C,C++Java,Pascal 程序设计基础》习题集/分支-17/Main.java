import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, x, N = sc.nextInt();
		int arr[] = new int[5];
		 
		for(i = 0; i < N; i++){
			x = sc.nextInt();
			if(x >= 90){
				arr[0]++;
			} else if(x >= 80){
				arr[1]++;
			} else if(x >= 70){
				arr[2]++;
			} else if(x >= 60){
				arr[3]++;
			} else{
				arr[4]++;
			}
		}
		
		for(i = 0; i < arr.length - 1; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.print(arr[arr.length - 1]);
	}
}