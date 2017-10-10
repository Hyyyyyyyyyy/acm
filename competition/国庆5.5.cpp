#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 200000 + 100;
int A[maxn], B[maxn], C[maxn];
int ar[maxn], p[maxn];
int N;
int sum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += ar[x];
		x -= x & (-x);
	}
	return res;
}
void update(int x)
{
	while (x <= N)
	{
		ar[x]++;
		x += x & (-x);
	}
}
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &B[i]);
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &C[i]);
		}
		ll res = 0;
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			p[A[i]] = i;
		}
		for (i = N; i >= 1; i--)
		{
			res += sum(p[B[i]]);
			update(p[B[i]]);
		}
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			p[B[i]] = i;
		}
		for (i = N; i >= 1; i--)
		{
			res += sum(p[C[i]]);
			update(p[C[i]]);
		}
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			p[C[i]] = i;
		}
		for (i = N; i >= 1; i--)
		{
			res += sum(p[A[i]]);
			update(p[A[i]]);
		}
		printf("%lld\n", ((ll)N*(ll)(N-1) - (ll)res) / 2ll);
	}
	return 0;
}