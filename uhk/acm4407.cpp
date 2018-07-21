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
const int maxn = 400000 + 100;
const int maxm = 1000000 + 100;
vector<ll> G;
map<ll, ll> mp;
map<ll, ll>::iterator it;
ll N, M;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}
void getfactor(ll P)
{
	ll i, j, k;
	G.clear();
	for (i = 2; i*i <= P; i++)
	{
		if (P % i == 0)
		{
			G.push_back(i);
			P /= i;
			while (P % i == 0)
			{
				P /= i;
			}
		}
	}
	if (P > 1)
		G.push_back(P);
}
ll factor_sum(ll L, ll R, ll val)
{
	ll res;
	ll cnt = (R / val) - ((L - 1) / val);     //项数
	ll first = (L%val == 0) ? L : (L + (val - L % val));     //首项
	ll end = R - R % val;       //末项
	res = (first + end) * cnt / 2;
	return res;
}
ll query_sum(ll L, ll R, ll P)
{
	getfactor(P);
	ll i, j;
	ll res = 0;     //所有因子倍数和
	ll size = G.size();
	for (i = 1; i < (1 << size); i++)
	{
		ll bits = 0;
		ll val = 1;
		for (j = 0; j < size; j++)
		{
			if (i & (1 << j))
			{
				bits++;
				val *= G[j];
			}
		}
		ll ans = factor_sum(L, R, val);       //枚举到的因子倍数和
		if (bits & 1)
			res += ans;
		else
			res -= ans;
	}
	ll sum = (L + R) * (R - L + 1) / 2;     //所有数字和
	return sum - res;
}
ll solve(ll L, ll R, ll P)
{
	ll res = query_sum(L, R, P);
	if (mp.size() == 0)
		return res;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if (it->first < L || it->first > R)
			continue;
		if (gcd(P, it->first) == 1)
			res -= it->first;
		if (gcd(P, it->second) == 1)
			res += it->second;
	}
	return res;
}
int main()
{
	ll i, j, k, op, a, b, p, CAS, cas;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &M);
			mp.clear();
			for (ll m = 1; m <= M; m++)
			{
				scanf("%lld", &op);
				if (op == 1)
				{
					scanf("%lld %lld %lld", &a, &b, &p);
					if (a > b)
						swap(a, b);
					ll res = solve(a, b, p);
					printf("%lld\n", res);
				}
				else
				{
					scanf("%lld %lld", &a, &b);
					mp[a] = b;
				}
			}
		}
	}
	return 0;
}
/*查询操作的话我们就把序列一直当做1~n的序列来查询，然后迭代器跑一遍map判断对查询有无影响即可，总之操作最多2000次； 
对于查询操作，我们可以先分解出p的质因数，
设p的每种质因数组合的里的质因数乘积为value，那么[x,y]内value的倍数与p必定不互素，
求出value的区间[x,y]内所有倍数和（用等比数列求和公式），然后对结果进行容斥求和，即得出区间[x,y]内与p不互素的数的和sum，
然后区间所有数的和（用等差数列求和公式）减去sum即可。*/
