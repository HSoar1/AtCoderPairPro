package ABC301;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//提出時、Mainに直す

public class B_Fill_the_Gaps {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = 0;
		int preA = 0;
		List<Integer> list = new ArrayList<>();

		for (int j = 0; j < N; j++) {
			A = sc.nextInt();
			if (preA == 0) {
				list.add(A);
			} else {
				int length = Math.abs(A - preA);
				if (length == 1) {
					list.add(A);
				} else {
					for (int i = 0; i < length; i++) {
						if (preA < A) {
							list.add(preA + i + 1);
						} else {
							list.add(preA - i - 1);
						}
					}
				}
			}
			preA = A;
		}
		for (int l : list) {
			System.out.print(l);
			System.out.print(" ");
		}
	}
}
