#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 2000 + 100;
ll N, M;
ll yh[2015][2015];
ll POW[2015][2015];
void C()
{
	yh[0][0] = 1;
	for (ll i = 1; i <= 2002; i++)
	{
		yh[i][1] = 1ll;
		yh[i][i] = 1ll;
	}

	for (ll i = 3; i <= 2002; i++)
	{
		for (ll j = 2; j<i; j++)
			yh[i][j] = (yh[i - 1][j] + yh[i - 1][j - 1]) % MOD;
	}
}
void pow()
{
	for (ll i = 0; i <= 2005; i++)
		POW[0][i] = 0ll;
	for (ll i = 1; i <= 2005; i++)
	{
		POW[i][0] = 1ll;
		for (ll j = 1; j <= 2005; j++)
		{
			POW[i][j] = (POW[i][j-1] * i) % MOD;
		}
	}
}
int main()
{
	ll i, j, k, u, n, m;
	C();
	pow();
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			ll MIN = min(N, M);
			ll res = 0;
			for (i = 1; i <= MIN; i++)
			{
				ll tt = 0;
				ll F = 1;
				for (j = i; j >= 1; j--)
				{
					tt = (tt + (yh[i + 1][j + 1] * F * POW[j][N] % MOD + MOD) %MOD) % MOD;
					F *= -1;
				}
				res = (res + tt * yh[M + 1][i + 1] % MOD * POW[M - i][N] % MOD) % MOD;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
