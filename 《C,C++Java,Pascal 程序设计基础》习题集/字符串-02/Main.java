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
			} else{  //�޸ĵ㣬ֻ���ڲ����ϵ�ʱ��Ż�i++��֮ǰi++ �����������for���浼��������caseûͨ��
				i++;
			}
		}
		System.out.print(str);
	}
}