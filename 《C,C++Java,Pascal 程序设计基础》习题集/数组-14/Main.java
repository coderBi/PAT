import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i, arr[] = new int[4];
		
		for(i = 3; n/10 != 0 && i > 0; n /= 10, i--){
			arr[i] = n%10;
		}
		arr[0] = n;
		
		for(i = 0; i < 4; i++){
			arr[i] = (arr[i] + 9)%10;
		}
		swap(arr, 0, 2);
		swap(arr, 1, 3);
		/*n = 0;
		for(i = 0; i < 4; i++){
			n *= 10;
			n += arr[i];
		}*/
		//System.out.print("The encrypted number is " + n); //经过测试这里多余求了n， 实际上要求打印出前置0
		System.out.print("The encrypted number is ");
		for(i = 0; i < 4; i++){
			System.out.print(arr[i]);
		}
	}
	
	static void swap(int arr[], int i, int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}