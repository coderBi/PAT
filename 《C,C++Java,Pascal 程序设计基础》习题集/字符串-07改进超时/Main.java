/*
 * 1,֮ǰ֮������һ��caseû��ͨ������ʱ�����²�ԭ����String.split ��ʹ�ã���Ϊ�������ַ����ܴﵽ500 000��
 * 2������������д�ķ�����ʵ����һ����˼���ǲ��ģ����Ի��Ǵ��ڳ�ʱ�����
 * 3�������д���һ���Ľ��汾���
 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, j, front, tail;

		for (front = 0; front < str.length() && str.charAt(front) == ' '; front++) {
		}

		for (tail = str.length() - 1; tail >= 0 && str.charAt(tail) == ' '; tail--) {
		}
		
		if (front > tail) {
			System.exit(0);
		}
		
		for (i = tail, j = tail; i >= front; i--) {
			if (str.charAt(i) == ' ') {
				int k;
				for(k = i+1; k <= j; k++){
					System.out.print(str.charAt(k));
				}
				if(i != j){
					System.out.print(" ");
				}				
				j = i -1;
			}
		}
		
		for(i = front; i <= j; i++){
			System.out.print(str.charAt(i));
		}
		
	}
}