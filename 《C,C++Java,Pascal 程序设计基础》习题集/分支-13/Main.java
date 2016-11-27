import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str1 = sc.nextLine();
		String str[] = str1.split("/");
		int year = Integer.parseInt(str[0]);
		int month = Integer.parseInt(str[1]);
		int day = Integer.parseInt(str[2]);
		int res = 0, i;
		
		int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		month--;
		for(i = 0; i < month; i++){
			res += daysPerMonth[i];
		}
		res += day;
		
		if(month > 1 && (year%400 == 0 || (year%4 == 0 && year%100 != 0))){ //之前这里少加了一个month > 1的判断导致一个case没通过
			res++;
		}
		System.out.print(res);
	}
}