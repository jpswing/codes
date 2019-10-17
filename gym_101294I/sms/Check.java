import ru.ifmo.testlib.*;
import ru.ifmo.testlib.Outcome.Type;

public class Check implements Checker {

	@Override
	public Outcome test(InStream inf, InStream ouf, InStream ans) {
		int n = inf.nextInt();
		int m = inf.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = inf.nextInt();
		}
		
		int[] b = new int[m];
		int sj = 0;
		for (int i = 0; i < m; i++) {
			b[i] = ans.nextInt();
			if ((b[i] < 0))
				return new Outcome(Type.FAIL, "Negative numbers in jury's answers");
			sj += b[i];
		}
		if (sj != n) {
			return new Outcome(Type.FAIL, "Sum of buttons isn't equal to n");
		}
		
		int[] c = new int[m];
		int sc = 0;
		for (int i = 0; i < m; i++) {
			c[i] = ouf.nextInt();
			if ((c[i] < 0))
				return new Outcome(Type.WA, "Negative numbers in contestant's answers");
			sc += c[i];
		}
		if (sc != n) {
			return new Outcome(Type.WA, "Sum of buttons isn't equal to n");
		}
		
		long s1 = 0;
		int t = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < b[i]; j++) {
				s1 += (j + 1) * a[t + j];
			}
			t += b[i];
		}
		
		long s2 = 0;
		t = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < c[i]; j++) {
				s2 += (j + 1) * a[t + j];
			}
			t += c[i];
		}
		
		if (s1 < s2) {
			return new Outcome(Type.WA, "Jury's answer is better");
		}
		
		if (s1 > s2) {
			return new Outcome(Type.FAIL, "Contestant's answer is better");
		}
		
		return new Outcome(Type.OK, "Contestant's solution is optimal");
	}
	
}
