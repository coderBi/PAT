import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in = sc.nextInt();
		int i, j, k;
		
		for(i = in; i < in + 4; i++){
			int count = 0;
			for(j = in; j < in + 4; j++){
				if(j == i){
					continue;
				}
				
				for(k = in; k < in + 4; k++){
					if(k == i || k == j){
						continue;
					}
					System.out.print("" + i + j + k);
					count++;
					if(count%6 != 0){
						System.out.print(" ");
					} else{
						System.out.print("\n");
					}
				}
			}
		}
	}
}