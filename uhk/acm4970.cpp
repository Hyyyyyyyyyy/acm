#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
ll ar[maxn];
ll Bit1[maxn];
ll Bit2[maxn];
ll N, M;
void Add1(ll x, ll val)
{
	for (ll i = x; i <= N; i += (i & -i))
		Bit1[i] += val;
}
void Add2(ll x, ll val)
{
	for (ll i = x; i <= N; i += (i & -i))
	{
		Bit2[i] += val;
	}
}
ll Sum1(ll x)
{
	ll res = 0;
	for (ll i = x; i > 0; i -= (i & -i))
	{
		res += Bit1[i];
	}
	return res;
}
ll Sum2(ll x)
{
	ll res = 0;
	for (ll i = x; i > 0; i -= (i & -i))
	{
		res += Bit2[i];
	}
	return res;
}
ll Getsum(ll a, ll b)   //a < b
{
	return b * Sum1(b) - Sum2(b) - ((a - 1)*Sum1(a - 1) - Sum2(a - 1));
}
int main()
{
	ll i, j, k, a, b, c, n, m, q, Q;
	while (scanf("%lld", &N) != EOF && N)
	{
		scanf("%lld", &M);
		memset(Bit1, 0, sizeof(Bit1));
		memset(Bit2, 0, sizeof(Bit2));
		for (m = 1; m <= M; m++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			Add1(a, c);
			Add2(a, (a - 1)*c);
			Add1(b + 1, -c);
			Add2(b + 1, b*(-c));
		}
		ll res = 0;
		scanf("%lld", &Q);
		for (q = 1; q <= Q; q++)
		{
			scanf("%lld %lld", &a, &b);
			if (Getsum(b, N) < a)
				res++;
		}
		printf("%lld\n", res);
	}
	return 0;
}

