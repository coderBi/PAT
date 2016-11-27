import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int arr[] = new int[4], i; 
		
		for(i = 0; i < str.length(); i += 8){
			int j = i;
			for(; j < str.length() && j < i + 8; j++){
				int pos = i/8;
				arr[pos] *= 2;
				arr[pos] += str.charAt(j) - '0';
			}
		}
		for(i = 0; i < arr.length - 1; i++){
			System.out.print(arr[i] + ".");
		}
		System.out.print(arr[arr.length -1]);
	}
}