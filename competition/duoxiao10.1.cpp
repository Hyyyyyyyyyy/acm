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
const ll MOD = 998244353ll;
const int maxn = 100000+100;
ll N;
ll res;
ll dp[maxn];
long long MUL(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
long long MULL(long long a, long long b)
{
	long long res = 0;
	while (b)
	{
		if (b & 1)
		{
			res = (res + a) % MOD;
		}
		a = (a + a) % MOD;
		b >>= 1;
	}
	return res;
}
int main()
{
    ll i, j, k, u, n, m;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld", &N);
            if(N == 1)
            {
                printf("1\n");
            }
            else if(N == 2)
            {
                printf("9\n");
            }
            else if(N == 3)
            {
                printf("36\n");
            }
            else
            {
                res = 1;
                res = (res + MUL(N, 3ll)) % MOD;
                res = (res + MUL(N-1, 3ll)) % MOD;
                for(i = 2; N-i >= 2; i++)
                {
                    ll t = i / 2 + 1;
                    res = (res + MULL(MUL(N-i, 3ll), t)) % MOD;
                }
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}