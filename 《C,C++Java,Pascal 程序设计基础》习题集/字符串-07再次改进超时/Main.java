/*
 * 这里的逻辑跟通过的C语言实现的一模一样，分析超时的可能是java本身的处理机制，
 * 可以看到上面通过的几个case都是接近100ms ，最后一个大长度的string没有通过
 * 可能跟下面的
 * for(i = 0; i < length; i++){
			arr[i] = str.charAt(i);
		}
	charAt有关，不过这里不确定，因为个人推测的charAt也就是内部简单的交表索引。
	结论：1，这里通过不过最后一个case跟java本身有关，
	 	 2，目测跟循环内的charAt的使用有关，但是存疑
	 ps： 搜到的这一题，网络上大家也都遇到同样的问题
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