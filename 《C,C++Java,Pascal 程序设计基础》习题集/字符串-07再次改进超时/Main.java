/*
 * ������߼���ͨ����C����ʵ�ֵ�һģһ����������ʱ�Ŀ�����java����Ĵ�����ƣ�
 * ���Կ�������ͨ���ļ���case���ǽӽ�100ms �����һ���󳤶ȵ�stringû��ͨ��
 * ���ܸ������
 * for(i = 0; i < length; i++){
			arr[i] = str.charAt(i);
		}
	charAt�йأ��������ﲻȷ������Ϊ�����Ʋ��charAtҲ�����ڲ��򵥵Ľ���������
	���ۣ�1������ͨ���������һ��case��java�����йأ�
	 	 2��Ŀ���ѭ���ڵ�charAt��ʹ���йأ����Ǵ���
	 ps�� �ѵ�����һ�⣬�����ϴ��Ҳ������ͬ��������
 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, front, j, length = str.length();
		char arr[] = new char[length];
		
		for(i = 0; i < length; i++){
			arr[i] = str.charAt(i);
		}
		for(front = 0; front < length && arr[front] == ' '; front++){
			
		}
		if(front >= length){
			System.exit(0);
		}
		for(i = length -1, j = length -1; i >= front; i--){
			if(arr[i] == ' '){
				int k;
				for(k = i +1; k <= j; k++){
					System.out.print(arr[k]);
				}
				if(i != j){
					System.out.print(" ");
				}
				j = i -1;
			}		
		}
		for(i = front; i <= j; i++){
			System.out.print(arr[i]);
		}
	}
}