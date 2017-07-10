#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 500000 + 100;
typedef long long ll;
int LIS[maxn];
int ar[maxn];
int ld[maxn], rd[maxn];
int N;
int erfen(int x, int len)
{
	int l = 1;
	int r = len;
	int mid;
	while (r >= l)
	{
		mid = (l + r) / 2;
		if (LIS[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
int lis()
{
	int i, j, k;
	LIS[1] = ar[1];
	ld[1] = 1;
	int len = 1;
	for (i = 2; i <= N; i++)
	{
		if (ar[i] > LIS[len])
		{
			LIS[++len] = ar[i];
			ld[i] = len;
		}
		else
		{
			int t = erfen(ar[i], len);
			LIS[t] = ar[i];
			ld[i] = t;
		}
	}
	return len;
}
int lis2()
{
	int i, j, k;
	LIS[1] = ar[N];
	rd[N] = 1;
	int len = 1;
	for (i = N - 1; i >= 1; i--)
	{
		if (ar[i] > LIS[len])
		{
			LIS[++len] = ar[i];
			rd[i] = len;
		}
		else
		{
			int t = erfen(ar[i], len);
			LIS[t] = ar[i];
			rd[i] = t;
		}
	}
	return len;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		lis();
		lis2();
		int MAX = 0;
		for (i = 1; i <= N; i++)
		{
			int v = min(ld[i], rd[i]) * 2 - 1;
			if (MAX < v)
				MAX = v;
		}
		printf("%d\n", MAX);
	}
	return 0;
}