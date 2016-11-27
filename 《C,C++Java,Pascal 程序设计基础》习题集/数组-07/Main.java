import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, x, count = 0,  n = sc.nextInt();
		int arr[] = new int[10];
		int res[] = new int[10];
		
		for(i = 0; i < n; i++){
			x = sc.nextInt();
			getTimes(x, arr);
		}
		for(i = 0; i < arr.length; i++){
			if(arr[i] > count){
				count = arr[i];
			}
		}
		
		int length = 0;
		for(i = 0; i < arr.length; i++){
			if(arr[i] == count){
				res[length++] = i;
			}
		}
		System.out.print(count + ": ");
		printArr(res, length);
	}
	
	static void getTimes(int x, int arr[]){
		while(x/10 != 0){
			arr[x%10]++;
			x /= 10;
		}
		arr[x]++;
	}
	
	static void printArr(int arr[], int length){
		if(length <= 0){
			return;
		}
		
		for(int i =0; i < length - 1; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.print(arr[length - 1]);
	}
}