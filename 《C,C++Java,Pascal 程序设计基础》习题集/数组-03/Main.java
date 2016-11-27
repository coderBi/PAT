import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int arr[] = new int[n];

		for(int i = 0; i < n; i++){
			arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < k; i++){
			for(int j = 0; j < n - i - 1; j++){
				if(arr[j] > arr[j + 1]){
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		
		for(int i = 0; i < n -1; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.print(arr[n - 1]);
	}
}