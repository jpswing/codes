import java.io.*;
import java.util.*;

public class sms_pk {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	public String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	int[] a;
	long tRes;
	ArrayList<Integer> tAns;
	int N, M;

	void gen(int n, int m, ArrayList<Integer> ans, long res, int k) {
		if (n == N) {
			if (res < tRes) {
				tRes = res;
				tAns = (ArrayList<Integer>) ans.clone();
			}
			return;
		}
		if (m < M - 1) {
			ans.add(n);
			gen(n + 1, m + 1, ans, res + k * a[n], 1);
			ans.remove(ans.size() - 1);
		}
		gen(n + 1, m, ans, res + k * a[n], k + 1);
	}

	public void solve() throws IOException {
		N = nextInt();
		assert((1 <= N) && (N <= 30));
		M = nextInt();
		assert((1 <= M) && (M <= 10));
		a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = nextInt();
			assert((0 <= a[i]) && (a[i] <= 1000000));
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		long res = 0;
		tRes = Long.MAX_VALUE;
		gen(0, 0, ans, res, 1);
		int t = 0;
		for (int i = 0; i < tAns.size(); i++) {
			out.print((tAns.get(i) - t + 1) + " ");
			N -= tAns.get(i) - t + 1;
			t = tAns.get(i) + 1;
		}
		for (int i = tAns.size(); i < M; i++) {
			out.print(N + " ");
			N = 0;
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("sms.in"));
			out = new PrintWriter("sms.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new sms_pk().run();
	}
}