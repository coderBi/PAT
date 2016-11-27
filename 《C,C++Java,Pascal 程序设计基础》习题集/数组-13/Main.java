import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i = 0, j = 0, k, n = sc.nextInt();
		int arr[][] = new int[n][n];
		int top = 0, left = 0, down = n - 1, right = n - 1;
		int dir = 1; // 1:ÓÒ 2£ºÏÂ 3£º×ó 4£º ÉÏ

		for (k = 1; k <= n * n; k++) {
			arr[i][j] = k;
			switch (dir) {
			case 1:
				j++;
				if (j >= right) {
					dir = 2;
					top++;
				}
				break;
			case 2:
				i++;
				if (i >= down) {
					dir = 3;
					right--;
				}
				break;
			case 3:
				j--;
				if (j <= left) {
					dir = 4;
					down--;
				}
				break;
			case 4:
				i--;
				if (i <= top) {
					dir = 1;
					left++;
				}
				break;
			default:
				break;
			}
		}
		printArr(arr);
	}
	
	static void printArr(int arr[][]){
		int m = arr.length;
		int n = arr[0].length;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n -1; j++){
				System.out.printf("%3d", arr[i][j]);
			}
			System.out.printf("%3d\n", arr[i][n -1]);
		}
	}
}