import java.util.ArrayList;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i, count = 0, n = sc.nextInt();
		ArrayList<Integer> al = new ArrayList<Integer>();
		
		for(i = 1; i <= n; i++){
			al.add(i);
		}
		
		while(al.size() > 1){
			for(i = 0; i < al.size(); i++){
				count++;
				if(count == 3){
					al.remove(i);
					i--;
					count = 0;
				}			
			}
		}
		System.out.print(al.get(0));
	}
}