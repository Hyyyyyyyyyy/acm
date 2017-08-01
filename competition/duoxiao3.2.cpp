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
typedef unsigned long long ll;
const int maxn = 100000 + 10;
const ll MOD = 1e9 + 7;
int N, K, M, top;
ll MUL(ll a, ll b)
{
	ll res = 1ll;
	while (b)
	{
		if (b & 1ll)
		{
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	ll i, j, k, n, m;
	int cas = 1;
	while (scanf("%llu %llu", &n, &m) != EOF)
	{
		n %= MOD;
		printf("Case #%d: %llu\n", cas++, MUL(n, m));
	}
	return 0;
}