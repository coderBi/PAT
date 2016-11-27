import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		StringBuffer str = new StringBuffer(sc.nextLine());
		String str1 = sc.nextLine();
		int i;
		
		for(i =0; i <= str.length() - str1.length();){
			if(str.substring(i, i + str1.length()).equals(str1)){
				str.delete(i, i + str1.length());
				i -= str1.length() - 1;
				if(i < 0){
					i = 0;
				}
			} else{  //修改点，只有在不符合的时候才会i++，之前i++ 放在了上面的for里面导致有两个case没通过
				i++;
			}
		}
		System.out.print(str);
	}
}