/*
 * 1,之前之所以有一个case没有通过（超时），猜测原因是String.split 的使用，因为给出的字符可能达到500 000个
 * 2，但是这里所写的方法其实跟上一个的思想是差不多的，所以还是存在超时的情况
 * 3，问题有待下一个改进版本解决
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