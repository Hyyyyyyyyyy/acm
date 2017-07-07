#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 10010;
ll Q[1000010], factors[maxn];
ll cnt;
void Primefactor(ll n)
{
	ll i, j;
	cnt = 0;
	for (i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			factors[++cnt] = i;
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	if (n > 1)
		factors[++cnt] = n;
}
ll solve(ll n)
{
	ll i, j, t;
	ll count = 0;
	Q[0] = -1;
	for (i = 1; i <= cnt; i++)
	{
		t = count;
		for (j = 0; j <= t; j++)
		{
			Q[++count] = Q[j] * (-1) * factors[i];
		}
	}
	ll sum = 0;
	for (i = 1; i <= count; i++)
	{
		sum += n / Q[i];
	}
	return sum;
}
int main()
{
	ll i, j, k, u, n, m, a, b, N;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld %lld", &a, &b, &N);
			a--;
			Primefactor(N);
			printf("Case #%lld: %lld\n", m, b - solve(b) - (a - solve(a)));
		}
	}
	return 0;
}