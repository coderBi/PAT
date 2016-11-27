import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, length = str.length(), res = 0; //这里之所以保存str的length 是避免写在for里面重复被计算
		
		for(i = 0; i < length; i++){
			char ch = str.charAt(i);
			if(ch >= '0' && ch <= '9'){
				res *= 10;
				res += ch - '0';
			}
		}
		System.out.print(res);
	}
}