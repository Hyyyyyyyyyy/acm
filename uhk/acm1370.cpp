#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
const int maxn = 20;
using namespace std;
ll A[maxn], M[maxn];
void extend_Euclid(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	extend_Euclid(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - (a / b) * y;
}
ll CRT(ll n)
{
	ll ans = 0;
	ll MM = 1;
	for (ll i = 1; i <= n; i++)
		MM *= M[i];
	for (ll i = 1; i <= n; i++)
	{
		ll x, y;
		ll Mi = MM / M[i];
		extend_Euclid(Mi, M[i], x, y);
		ans = (ans + Mi * x * A[i]) % MM;
	}
	if (ans < 0) ans += MM;
	return ans;
}
int main()
{
	int i, j, k, u, n, m;
	ll a, b, c, d;
	int cas = 1;
	scanf("%d", &u);
	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != EOF && (a != -1 || b != -1 || c != -1 || d != -1))
	{
		M[1] = 23;
		M[2] = 28;
		M[3] = 33;
		A[1] = a;
		A[2] = b;
		A[3] = c;
		ll RES = CRT(3);
		if (RES > d)
			printf("Case %d: the next triple peak occurs in %lld days.\n", cas++, RES - d);
		else
			printf("Case %d: the next triple peak occurs in %lld days.\n", cas++, RES + 21252 - d);
	}
	return 0;
}