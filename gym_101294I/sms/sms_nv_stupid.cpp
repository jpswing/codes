#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <cmath>

using namespace std;

vector<int> ans, tek, c;
vector<long long> a;
int N, M;
long long count = 2e15;

void ololo()
{
	for (int j = 0; j < tek[0]; j++)
		c[j] = 0;
	int t = 0;
	for (int i = 0; i < tek.size() - 1; i++)
	{
		t += tek[i];
		int j = 0;
		while (j < tek[i + 1])
		{
			c[j + t] = t;
			j++;
		}
	}
	long long tcount = 0;
	for (int i = 0; i < N; i++)
		tcount += (i - c[i] + 1) * a[i];
	if (tcount < count)
	{
		count = tcount;
		ans = tek;
	}
}

void gen(int n, int m)
{
	tek.resize(m);
	if (m == 1)
	{
		tek.clear();
		tek.push_back(n);
		for (int i = 0; i < n; i++)
			c[i] = 0;
		int tcount = 0;
		for (int i = 0; i < n; i++)
			tcount += (i - c[i]) * a[i];
		if (tcount < count)
		{
			tcount = count;
			ans = tek;
		}
	}
	if (m == 2)
	{
		for (int i1 = 0; i1 <= n; i1++)
		{
			tek[0] = i1;
			tek[1] = n - i1;
			ololo();
		}
	}
	if (m == 3)
	{
		for (int i1 = 0; i1 <= n; i1++)
		{
			for (int i2 = i1; i2 <= n; i2++)
			{
				tek[0] = i1;
				tek[1] = i2 - i1;
				tek[2] = n - i2;
				ololo();
			}
		}
	}
	if (m == 4)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
				{
					tek[0] = i1;
					tek[1] = i2 - i1;
					tek[2] = i3 - i2;
					tek[3] = n - i3;
					ololo();
				}
	}
	if (m == 5)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
					{
						tek[0] = i1;
						tek[1] = i2 - i1;
						tek[2] = i3 - i2;
						tek[3] = i4 - i3;
						tek[4] = n - i4;
						ololo();
					}
	}
	if (m == 6)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
						for (int i5 = i4; i5 <= n; i5++)
						{
							tek[0] = i1;
							tek[1] = i2 - i1;
							tek[2] = i3 - i2;
							tek[3] = i4 - i3;
							tek[4] = i5 - i4;
							tek[5] = n - i5;
							ololo();
						}
	}
	if (m == 7)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
						for (int i5 = i4; i5 <= n; i5++)
							for (int i6 = i5; i6 <= n; i6++)
							{
								tek[0] = i1;
								tek[1] = i2 - i1;
								tek[2] = i3 - i2;
								tek[3] = i4 - i3;
								tek[4] = i5 - i4;
								tek[5] = i6 - i5;
								tek[6] = n - i6;
								ololo();
							}
	}
	if (m == 8)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
						for (int i5 = i4; i5 <= n; i5++)
							for (int i6 = i5; i6 <= n; i6++)
								for (int i7 = i6; i7 <= n; i7++)
								{
									tek[0] = i1;
									tek[1] = i2 - i1;
									tek[2] = i3 - i2;
									tek[3] = i4 - i3;
									tek[4] = i5 - i4;
									tek[5] = i6 - i5;
									tek[6] = i7 - i6;
									tek[7] = n - i7;
									ololo();
								}
	}
	if (m == 9)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
						for (int i5 = i4; i5 <= n; i5++)
							for (int i6 = i5; i6 <= n; i6++)
								for (int i7 = i6; i7 <= n; i7++)
									for (int i8 = i7; i8 <= n; i8++)
									{
										tek[0] = i1;
										tek[1] = i2 - i1;
										tek[2] = i3 - i2;
										tek[3] = i4 - i3;
										tek[4] = i5 - i4;
										tek[5] = i6 - i5;
										tek[6] = i7 - i6;
										tek[7] = i8 - i7;
										tek[8] = n - i8;
										ololo();
									}
	}
	if (m == 10)
	{
		for (int i1 = 0; i1 <= n; i1++)
			for (int i2 = i1; i2 <= n; i2++)
				for (int i3 = i2; i3 <= n; i3++)
					for (int i4 = i3; i4 <= n; i4++)
						for (int i5 = i4; i5 <= n; i5++)
							for (int i6 = i5; i6 <= n; i6++)
								for (int i7 = i6; i7 <= n; i7++)
									for (int i8 = i7; i8 <= n; i8++)
										for (int i9 = i8; i9 <= n; i9++)
										{
											tek[0] = i1;
											tek[1] = i2 - i1;
											tek[2] = i3 - i2;
											tek[3] = i4 - i3;
											tek[4] = i5 - i4;
											tek[5] = i6 - i5;
											tek[6] = i7 - i6;
											tek[7] = i8 - i7;
											tek[8] = i9 - i8;
											tek[9] = n - i9;
											ololo();
										}
	}
}

int main()
{
    freopen("sms.in", "r", stdin);
    freopen("sms.out", "w", stdout);
    cin >> N >> M;
    a.resize(N);
    c.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    gen(N, M);
    for (int i = 0; i < M; i++)
        cout << ans[i] << ((i == M - 1) ? "\n" : " ");
}