import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i, j, k, x1, x2, y1, y2;
		int count = 0, total = 2*n*n;
		char arr[][] = new char[2*n][2*n];
		
		for(i = 0; i < 2*n; i++){
			for(j = 0; j < 2*n; j++){
				arr[i][j] = sc.next().charAt(0);
			}
		}
		
		k = sc.nextInt();
		for(i = 0; i < k; i++){
			x1 = sc.nextInt();
			y1 = sc.nextInt();
			x2 = sc.nextInt();
			y2 = sc.nextInt();
			
			if(arr[x1 - 1][y1 -1] == arr[x2 - 1][y2 -1] && arr[x1 - 1][y1 -1] != '*'){
				arr[x1 - 1][y1 -1] = '*';
				arr[x2 - 1][y2 -1] = '*';
				total--;
				if(total == 0){
					System.out.print("Congratulations!");
					break;
				} else {
					printArr(arr);
				}
			} else {
				System.out.println("Uh-oh");
				count++;
				if(count >= 3){
					System.out.print("Game Over");
					break;
				}
			}
		}
	}
	
	static void printArr(char arr[][]){
		int m = arr.length;
		int n = arr[0].length;
		int i, j;
		
		for(i = 0; i < m; i++){
			for(j = 0; j < n-1; j++){
				System.out.print(arr[i][j] + " ");
			}
			System.out.println(arr[i][n -1]);
		}
	}
}