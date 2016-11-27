import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int i, j, count = 0, arr[][] = new int[m][n];
		
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				arr[i][j] = sc.nextInt();
			}
		}
		
		for(i = 1; i < m - 1; i++){
			for(j = 1; j < n -1; j++){
				if(arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j]
						&& arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1]){
					System.out.println(arr[i][j] + " " + (i + 1) + " " + (j + 1));
					count++;
				}
			}
		}
		if(count == 0){
			System.out.print("None " + m + " " + n);
		}
	}
}