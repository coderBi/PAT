import java.util.Scanner;


public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double arr[] = new double[4];
		int i;
		StringBuffer res = new StringBuffer("");
		
		for(i = 0; i < arr.length; i++){
			arr[i] = sc.nextDouble();
		}
		if(arr[0] > arr[3]){
			res.append("BW-Solid");
		} else if(arr[0] < arr[3]){
			res.append("R-Hollow");
		} else{
			res.append("R-Cross");
		}
		
		if(arr[1] > arr[0] && arr[1] > arr[3] && arr[2] < arr[0] && arr[2] < arr[3]){
			res.append(" with Lower Shadow and Upper Shadow");
		} else if(arr[1] > arr[0] && arr[1] > arr[3]){
			res.append(" with Upper Shadow");
		} else if(arr[2] < arr[0] && arr[2] < arr[3]){
			res.append(" with Lower Shadow");
		}
		
		System.out.print(res);
	}
}