import java.util.Scanner;

public class Attack {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long A = Long.parseLong(sc.next());
		long B = Long.parseLong(sc.next());

		long result = A/B;
		if(A%B != 0) {
			result++;
		}
		System.out.println(result);
	}
}
