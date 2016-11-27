import java.util.Scanner;

public class Main{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int y = 0, f = 0, n = sc.nextInt();
		
label1:		for(y = 0; y < 100; y++){
			for(f = 0; f < 100; f++){
				if(f*100 + y == n + 2*y*100 + 2*f){
					break label1;
				}
			}
		}
		
		if(y >= 100){
			System.out.print("No Solution");
		} else {
			System.out.print(y + "." + f);
		}
	}
}