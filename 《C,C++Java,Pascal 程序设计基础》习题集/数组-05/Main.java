import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int i, length = str.length();
		char arr[] = new char[length];
		
		for(i = 0; i < length; i++){
			char ch = str.charAt(i);
			if(ch == '#'){
				arr[i] = '\0';
				break;
			}
			if(ch >= 'A' && ch <= 'Z'){
				arr[i] = Character.toLowerCase(ch);
			} else if(ch >= 'a' && ch <= 'z') {
				arr[i] = Character.toUpperCase(ch);
			} else{
				arr[i] = ch;
			}
		}
		System.out.print(String.valueOf(arr));
	}
}