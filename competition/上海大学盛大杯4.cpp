#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1000000000;
typedef long long ll;
const ll mod = 1e9 + 7;
ll multiply(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}
int main()
{
	int i, j, k, u, n, m;
	ll N;
	while (scanf("%lld", &N) != EOF)
	{
		printf("%lld\n", multiply(2ll, N, mod) - 1);
	}
	return 0;
}