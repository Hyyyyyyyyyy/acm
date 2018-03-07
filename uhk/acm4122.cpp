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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 3000 + 100;
const int maxm = 100000 + 100;
map<string, ll> mp;
ll CMON[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
ll LMON[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
ll num, R, N, M, T, S;
struct Date
{
	char s[5];
	ll d;
	ll y;
	ll h;
	ll num;
};
Date ar[maxn];      //时间
ll make[maxm];     //制作费
				   //线段树最小值
struct Node
{
	ll l;
	ll r;
	ll mid;
	ll min;
};
Node G[4 * maxm];
void pushup(ll root)
{
	if (make[G[root * 2].min] + (M - G[root * 2].min)*S < make[G[root * 2 + 1].min] + (M - G[root * 2 + 1].min)*S)
		G[root].min = G[root * 2].min;
	else
		G[root].min = G[root * 2 + 1].min;
}
void build(ll root, ll begin, ll end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	G[root].min = INF;
	if (begin == end)
	{
		G[root].min = begin;
		return;
	}
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
	pushup(root);
}
ll query(ll root, ll b, ll e)
{
	if (b <= G[root].l && G[root].r <= e)
	{
		return G[root].min;
	}
	ll temp = INF;
	ll index = -1;
	if (G[root].mid >= b)
	{
		ll t = query(root * 2, b, e);
		if (t > -1 && temp > make[t] + (M - t)*S)
			index = t, temp = make[t] + (M - t)*S;
	}
	if (G[root].mid < e)
	{
		ll t = query(root * 2 + 1, b, e);
		if (t > -1 && temp >= make[t] + (M - t)*S)
			index = t, temp = make[t] + (M - t)*S;
	}
	return index;
}
bool leapyear(ll x)
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
		return true;
	return false;
}
ll Time(ll year, ll month, ll day, ll h, ll num)
{
	ll i, j, k;
	ll countdays = 0;
	ll res = 0;
	for (i = 2000; i < year; i++)
	{
		if (leapyear(i))
			countdays += 366;
		else
			countdays += 365;
	}
	if (leapyear(year))
		countdays += LMON[month - 1];
	else
		countdays += CMON[month - 1];
	countdays += day - 1;
	res = countdays * 24 + h + 1;
	return res;
}
int main()
{
	mp["Jan"] = 1;
	mp["Feb"] = 2;
	mp["Mar"] = 3;
	mp["Apr"] = 4;
	mp["May"] = 5;
	mp["Jun"] = 6;
	mp["Jul"] = 7;
	mp["Aug"] = 8;
	mp["Sep"] = 9;
	mp["Oct"] = 10;
	mp["Nov"] = 11;
	mp["Dec"] = 12;

	ll i, j, k, n, m;
	while (scanf("%lld %lld", &N, &M) != EOF && N + M)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s %lld %lld %lld %lld", ar[i].s, &ar[i].d, &ar[i].y, &ar[i].h, &ar[i].num);
		}
		scanf("%lld %lld", &T, &S);
		for (i = 1; i <= M; i++)
		{
			scanf("%lld", &make[i]);
		}
		build(1, 1, M);
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			ll k = Time(ar[i].y, mp[ar[i].s], ar[i].d, ar[i].h, ar[i].num);
			ll q = query(1, k - T, k);
			res += ar[i].num * (make[q] + (k - q)*S);
		}
		printf("%lld\n", res);
	}
	return 0;
}