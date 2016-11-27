import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int randNum = sc.nextInt();
		int n = sc.nextInt();
		int i, guss;

		for (i = 1; i <= n; i++) {
			guss = sc.nextInt();

			if (guss == randNum) {
				if (i == 1) {
					System.out.println("Bingo!");
				} else if (i <= 3) {
					System.out.println("Lucky You!");
				} else {
					System.out.println("Good Guess!");
				}
				break;
			} else if (guss > randNum) {
				System.out.println("Too big");
			} else {
				if (guss < 0) {
					System.out.println("Game Over");
					break;
				}
				System.out.println("Too small");
			}
		}

		if (i > n) {
			System.out.println("Game Over");
		}
	}
}