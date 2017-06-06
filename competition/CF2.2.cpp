#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
typedef unsigned __int64 ll;
ll ar[maxn], sa[maxn];
int N, M;
int main()
{
	int i, j, k, u, n, m;
	while (cin >> N >> M)
	{
		for (i = 1; i <= N; i++)
		{
			cin >> ar[i];
		}
		int l = 0;
		int r = N;
		int mid;
		ll sum = 0;
		ll res = 0;
		while (r >= l)
		{
			sum = 0;
			mid = (l + r) / 2;
			for (i = 1; i <= N; i++)
				sa[i] = ar[i] + i*mid;
			sort(sa + 1, sa + N + 1);
			for (i = 1; i <= mid; i++)
				sum += sa[i];
			if (sum <= M)
			{
				res = sum;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << r << " " << res << endl;
	}
	return 0;
}
