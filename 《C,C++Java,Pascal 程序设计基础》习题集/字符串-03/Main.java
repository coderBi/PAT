import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String fL = sc.nextLine();
		int pos = 0;
		int N = GetIntFromString(fL, pos)[0];
		pos = GetIntFromString(fL, pos)[1];
		int K = GetIntFromString(fL, pos)[0];
		pos = GetIntFromString(fL, pos)[1];
		//System.out.println("N = " + N + " k = " + K);
		
		int i, tail, arr[] = new int[N];
		String str[] = new String[N];

		for (i = 0; i < N; i++) {
			arr[i] = i;
			str[i] = sc.nextLine();
		}

		tail = str.length;
		for (i = 0; i < K; i++) {
			int j;
			for (j = 0; tail > 0 && j < tail - 1; j++) {
				if (str[j].compareTo(str[j + 1]) > 0) {
					String temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
					//System.out.println("here exchangeed!" + " " + j);
					//System.out.println(str[j] + " " + str[j + 1]);
				}
			}
			tail--;
		}

		for (i = 0; i < str.length; i++) {
			System.out.println(str[i]);
		}
	}

	public static int[] GetIntFromString(String str, int front){
		int i = front, res = 0, arr[] = new int[2];
		
		for(; i < str.length() && (str.charAt(i) < '0' || str.charAt(i) > '9'); i++){}
		
		for(; i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9'; i++){
			res *= 10;
			res += str.charAt(i) - '0';
		}
		arr[0] = res;
		arr[1] = i;
		return arr;
	}
}