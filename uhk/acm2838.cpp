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
struct Node
{
	ll num;
	ll id;
};
Node node[maxn];
ll Bit[maxn];
ll Bit2[maxn];
ll N;
bool comp(const Node& a, const Node& b)
{
	return a.num > b.num;
}
void Add1(ll x, ll val)
{
	for (ll i = x; i <= N; i += (i & -i))
		Bit[i] += val;
}
void Add2(ll x, ll val)
{
	for (ll i = x; i <= N; i += (i & -i))
		Bit2[i] += val;
}
ll Sum1(ll x)
{
	ll res = 0;
	for (ll i = x; i > 0; i -= (i & -i))
		res += Bit[i];
	return res;
}
ll Sum2(ll x)
{
	ll res = 0;
	for (ll i = x; i > 0; i -= (i & -i))
		res += Bit2[i];
	return res;
}
int main()
{
	ll i, j, k;
	while (scanf("%lld", &N) != EOF)
	{
		memset(Bit, 0, sizeof(Bit));
		memset(Bit2, 0, sizeof(Bit2));
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &node[i].num);
			node[i].id = i;
		}
		sort(node + 1, node + 1 + N, comp);
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			res += Sum1(node[i].id) * node[i].num;
			res += Sum2(node[i].id);
			Add1(node[i].id, 1);
			Add2(node[i].id, node[i].num);
		}
		printf("%lld\n", res);
	}
	retrun 0;
}