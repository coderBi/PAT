/*
 * 这里使用Set可以将所以的不同元素唯一的打印出来，但是由于set内部的无序性，这里没有办法保证toArray之后
 * 更原输入的顺序的一致。
 */
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, k, count = 0;

		int n = sc.nextInt();
		Set<Integer> st1 = new HashSet<Integer>();
		for (i = 0; i < n; i++) {
			st1.add(sc.nextInt());
		}
		Integer arr1[] = st1.toArray(new Integer[0]);

		k = sc.nextInt();
		Set<Integer> st2 = new HashSet<Integer>();
		
		for (i = 0; i < k; i++) {
			st2.add(sc.nextInt());
		}
		Integer arr2[] = st2.toArray(new Integer[0]);
		
		int res[] = new int[arr1.length + arr2.length];
		int length = 0;
		for(i = 0; i < arr1.length; i++){
			int j;
			for(j = 0; j < arr2.length; j++){
				if(arr1[i] == arr2[j]){
					break;
				}	
			}
			if(j == arr2.length){
				res[length++] = arr1[i];
			}
		}
		
		for(i = 0; i < arr2.length; i++){
			int j;
			for(j = 0; j < arr1.length; j++){
				if(arr2[i] == arr1[j]){
					break;
				}	
			}
			if(j == arr1.length){
				res[length++] = arr2[i];
			}
		}
		
		for(i = 0; i < length -1; i++){
			System.out.print(res[i] + " ");
		}
		System.out.print(res[length -1]);
	}
}