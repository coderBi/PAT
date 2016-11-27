/*
 * 本来可以用动态数组进行元素的删除，这里为了更好的展现逻辑，用普通数组，自己写相应的删除处理
 */
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, j, n = sc.nextInt();
		int arr[] = new int[n];
		
		for(i = 0; i < n; i++){
			arr[i] = sc.nextInt();
		}
		
		int k = sc.nextInt();
		int arr1[] = new int[k];
		for(i = 0; i < k; i++){
			arr1[i] = sc.nextInt();
		}
		
		arr = removeRepeats(arr);
		arr1 = removeRepeats(arr1);
		
		int res[] = new int[arr.length + arr1.length];
		int length = 0;
		for(i = 0; i < arr.length; i++){
			for(j = 0; j < arr1.length; j++){
				if(arr1[j] == arr[i]){
					break;
				}
			}
			if(j == arr1.length){
				res[length++] = arr[i];
			}
		}
		for(i = 0; i < arr1.length; i++){
			for(j = 0; j < arr.length; j++){
				if(arr[j] == arr1[i]){
					break;
				}
			}
			if(j == arr.length){
				res[length++] = arr1[i];
			}
		}
		printArr(res, length);
	}
	
	static void printArr(int arr[], int length){
		if(length <= 0){
			return;
		}
		
		for(int i = 0; i < length -1; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.print(arr[length -1]);
	}
	
	static int[] removeRepeats(int arr[]){
		int i, j;
		for(i = 0; i < arr.length; i++){
			for(j = i -1; j >= 0; j--){
				if(arr[j] == arr[i]){
					arr = deleteElement(arr, i);
					i--;
					break;
				}
			}
		}
		return arr;
	}
	
	static int[] deleteElement(int arr[], int pos){
		int length = arr.length -1;
		int res[] = new int[length];
		
		for(int i = 0, k = 0; i < arr.length; i++){
			if(i != pos){
				res[k++] = arr[i];
			}
		}
		return res;
	}
}