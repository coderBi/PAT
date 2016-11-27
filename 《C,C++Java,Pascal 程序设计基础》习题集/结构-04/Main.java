import java.util.Scanner;

public class Main {
	static class Person {
		String name;
		String birthday;
		String sex;
		String phone;
		String tel;
	}

	public static void main(String[] args){	
		Scanner sc = new Scanner(System.in);
		int i, n = Integer.parseInt(sc.nextLine());
		Person arr[] = new Person[n];
		
		for(i = 0; i < n; i++){
			String str[] = sc.nextLine().split(" ");
			arr[i] = new Person(); //注意这里跟C语言里的结构体不同，上面的Person arr[] = new Person[n];定义了一系列引用没有开辟实际空间
			arr[i].name = str[0];
			arr[i].birthday = str[1];
			arr[i].sex = str[2];
			arr[i].phone = str[3];
			arr[i].tel = str[4];
		}
		
		int k = sc.nextInt();
		for(i = 0; i < k; i++){
			int x = sc.nextInt();
			if(x < 0 || x >= n){
				System.out.println("Not Found");
			} else {
				printPerson(arr, x);
			}
		}
	}

	static void printPerson(Person arr[], int i){
		System.out.print(arr[i].name + " " + arr[i].phone + " " + arr[i].tel 
							+ " " + arr[i].sex + " ");
		System.out.println(arr[i].birthday);
	}
}