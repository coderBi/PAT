/*
 * 1��֮ǰ��һ��caseû��ͨ����ԭ�򣬷����ǽ�100001000 ����Ҫ����һ����һǧ �Ķ�����һ��һǧ
 * 2�� �����ѭ���ڲ�����flag = 1������ȥ��������
 * 3�� �������﷢����ʵ���и�û������ȷ�ģ�������0 ��ʱ����ʵ��û��ӡ�κζ�����, ���������caseû��ͨ����ԭ��
 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int i, arr[] = new int[9];
		int length = 0, flag = 1; //flag = 0 ��ʾ��ǰ�жϵ�ǰ����0�� = 1��ʾ����0
		char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		char arr2[] = {'0', 'W', 'Y'};
		char arr3[] = {'0', 'S', 'B', 'Q'};
		
		//��ӵĶ�����0�Ĵ���
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
			//flag = 1; //�޸ĵ�
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