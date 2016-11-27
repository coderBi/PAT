import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i, front = n - 1; 
		int arr[] = new int[n], arr1[] = new int[n];
		for(i = 0; i < n; i++){
			arr[i] = arr1[i] = 1;
		}
		
		for(i = 0; i < n; i++){
			printSpace(front--);
			if(i == 0){
				System.out.printf("%4d\n", 1);
				continue;
			}
			
			int j;
			System.out.printf("%4d", 1);
			for(j = 1; j < i; j++){
				arr1[j] = arr[j - 1] + arr[j];
				System.out.printf("%4d", arr1[j]);
			}
			System.out.printf("%4d\n", 1);
			for(j = 1; j < i; j++){
				arr[j] = arr1[j];
			}
		}
	}
	
	static void printSpace(int front){
		int i;
		for(i = 0; i < front; i++){
			System.out.print(" ");
		}
	}
}