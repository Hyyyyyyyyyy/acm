#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e10;
const ll INF = 1e18;
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 500000 + 100;
int ar[maxn];
int L, N, M;
bool comp(int a, int b)
{
	return a > b;
}
bool check(int n)
{
	int i, j, k;
	int res = 1;
	int t = 0;
	for (i = 1; i <= N+1; i++)
	{
		if (t + ar[i] - ar[i + 1] > n)
		{
			res++;
			t = ar[i] - ar[i + 1];
		}
		else
			t += ar[i] - ar[i + 1];
		if (t > n)
			return false;
		if (res > M)
			return false;
	}
	return true;
}
int main()
{
	int i, j, k;
	while (scanf("%d %d %d", &L, &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		ar[N + 1] = L;
		ar[N + 2] = 0;
		sort(ar + 1, ar + 3 + N, comp);
		int l = 0;
		int r = L;
		int mid;
		while (r >= l)
		{
			mid = (l + r) / 2;
			if (check(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}