import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int arr[] = new int[4], i, sum;
		Scanner sc = new Scanner(System.in);
		for (i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		Main gs = new Main();
		sum = gs.GetSum(arr);
		System.out.print("Sum = " + sum + "; Average = " + Math.round(10*sum/4)/10.0);
	}

	int GetSum(int arr[]) {
		int sum = 0, i;

		for (i = 0; i < arr.length; i++) {
			sum += arr[i];
		}
		return sum;
	}
}
