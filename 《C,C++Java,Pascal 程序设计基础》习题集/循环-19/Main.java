/*
 * 1，之前有一个case没有通过的原因，分析是将100001000 这样要读做一亿零一千 的读成了一亿一千
 * 2， 这里把循环内部最后的flag = 1的重置去掉就行了
 * 3， 但是这里发现其实还有个没处理正确的，是输入0 的时候其实是没打印任何东西的, 而这是这个case没有通过的原因
 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int i, arr[] = new int[9];
		int length = 0, flag = 1; //flag = 0 表示当前判断点前面是0， = 1表示不是0
		char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		char arr2[] = {'0', 'W', 'Y'};
		char arr3[] = {'0', 'S', 'B', 'Q'};
		
		//添加的对输入0的处理
		if(in == 0){
			System.out.print(arr1[0]);
			System.exit(0);
		}
		
		while(in/10 != 0){
			arr[length++] = in%10;
			in /= 10;
		}
		arr[length++] = in;
		
		int j = (length -1)/4;
		for(i = length -1; j > 0; j--){
			for(; i > 4*j; i--){
				if(arr[i] != 0){
					if(flag == 0){
						System.out.print(arr1[0]);
					}
					System.out.print(arr1[arr[i]] + "" + arr3[i%4]);
					flag = 1;
				} else {
					flag = 0;
				} 
			}
			if(arr[i] == 0){
				for(int k = 1; i + k < length && k < 4; k++){
					if(arr[i +k] != 0){
						System.out.print(arr2[j]);
						break;
					}
				}
			}  else {
				if(flag == 0){
					System.out.print(arr1[0]);
				}
				System.out.print(arr1[arr[i]]);
				System.out.print(arr2[j]);
			}
			//flag = 1; //修改点
			i--;
		}
		
		for(; i > 0; i--){
			if(arr[i] != 0){
				if(flag == 0){
					System.out.print(arr1[0]);
				}
				System.out.print(arr1[arr[i]] + "" + arr3[i%4]);
				flag = 1;
			} else {
				flag = 0;
			} 
		}
		
		if(arr[i] != 0){
			if(flag == 0){
				System.out.print(arr1[0]);
			}
			System.out.print(arr1[arr[i]]);
		} 
	}
}