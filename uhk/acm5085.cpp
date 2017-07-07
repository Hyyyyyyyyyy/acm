#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30;
typedef long long ll;
ll ar[maxn], num[maxn], A[maxn], Pow[maxn][maxn];
ll K, S, N;
ll dfs(ll len, ll top, ll sum)
{
	ll i, j;
	if (len * Pow[top][K] < sum)
		return 0;
	if (sum < 0)
		return 0;
	if (top == 0)
	{
		if (sum)
			return 0;
		num[0] = len;
		ll res = A[N];
		for (i = 0; i <= 9; i++)
			res /= A[num[i]];
		return res;
	}
	ll res = 0;
	for (i = 0; i <= len; i++)
	{
		num[top] = i;
		res += dfs(len - i, top - 1, sum - i * Pow[top][K]);
	}
	return res;
}
ll solve2(ll len, ll sum)
{
	if (len == 0)
		return sum == 0;
	N = len;
	return dfs(len, 9, sum);
}
ll solve(ll n)
{
	ll i, j, cnt = 0;
	ll sum = S, res = 0;
	while (n)
	{
		ar[++cnt] = n % 10;
		n /= 10;
	}
	for (i = cnt; i > 0; i--)
	{
		for (j = 0; j < ar[i]; j++)
		{
			res += solve2(i - 1, sum - Pow[j][K]);
		}
		sum -= Pow[ar[i]][K];
	}
	if (sum == 0)
		res++;
	return res;
}
int main()
{
	ll i, j, k, u, n, m, a, b;
	A[0] = 1;
	for (i = 1; i <= 20; i++)
	{
		A[i] = A[i - 1] * i;
	}
	for (i = 1; i <= 9; i++)
	{
		Pow[i][0] = 1;
		for (j = 1; j <= 16; j++)
		{
			Pow[i][j] = Pow[i][j - 1] * i;
		}
	}
	while (scanf("%lld %lld %lld %lld", &a, &b, &K, &S) != EOF)
	{
		printf("%lld\n", solve(b) - solve(a - 1));
	}
	return 0;
}