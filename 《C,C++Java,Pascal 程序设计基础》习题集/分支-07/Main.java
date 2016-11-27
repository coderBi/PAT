import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = new int[3], i, j;

		for (i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		
		for(i = 0; i < arr.length; i++){
			for(j = i +1; j < arr.length; j++){
				if(arr[i] > arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		for(i = 0; i < arr.length - 1; i++){
			System.out.print(arr[i] + "->");
		}
		System.out.print(arr[arr.length - 1]);
	}
}