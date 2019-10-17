import java.io.*;
import java.util.*;

public class TestsGen {

	PrintWriter out;
	Random rnd;
	int tNumber;

	class Test {
		ArrayList<Integer> a;
		int m;

		void printTest() throws IOException {
			if (tNumber < 10)
				out = new PrintWriter("0" + tNumber);
			else
				out = new PrintWriter("" + tNumber);
			tNumber++;
			out.println(a.size() + " " + m);
			for (int i = 0; i < a.size(); i++) {
				out.print(a.get(i));
				if (i < a.size() - 1)
					out.print(" ");
				else
					out.println();
			}
			out.close();
			clear();
		}

		void clear() {
			a = new ArrayList<Integer>();
			m = 0;
		}

		void genRandTest(int N, int M, int c, int d) {
			m = M;
			c += d;
			for (int i = 0; i < N; i++) {
				a.add(c - rnd.nextInt(d) - 1);
			}
		}

		void insertNumber(int t, int x) {
			a.set(t, x);
		}

		void insertNumberInRandomPlace(int x) {
			a.set(rnd.nextInt(a.size()), x);
		}

		Test() {
			a = new ArrayList<Integer>();
		}
	}

	public void solve() throws IOException {
		tNumber = 2;
		rnd = new Random(31);
		Test t = new Test();

		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				t.genRandTest(i, j, 0, 100);
				t.printTest();
			}
		}
		for (int i = 1; i <= 3; i++) {
			t.genRandTest(30, 1, 0, 100);
			t.printTest();
		}

		t.genRandTest(5, 10, 0, 100);
		t.printTest();

		t.genRandTest(11, 10, 5, 100);
		t.printTest();

		for (int j = 0; j < 6; j++) {
			t.genRandTest(30, 10, 0, 1000);
			for (int i = 0; i < j; i++) {
				t.insertNumberInRandomPlace(rnd.nextInt(500000) + 500000);
			}
			t.printTest();
		}
		
		for (int j = 0; j < 6; j++) {
			t.genRandTest(30, 10, 0, 1000);
			int z = rnd.nextInt(12);
			for (int i = 0; i < 10 + j; i++) {
				
				t.insertNumber(z + i, rnd.nextInt(100000) + 900000);
			}
			t.printTest();
		}
		
	}

	public void run() {
		try {

			solve();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new TestsGen().run();
	}
}
