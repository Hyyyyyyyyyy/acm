#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 30000 + 100;
typedef long long ll;
const ll mod = 1000000007;
ll ar[maxn], res[maxn], num[maxn];
ll inv[maxn];
struct Node
{
	ll l;
	ll r;
	ll id;
	ll block_id;
};
Node Q[maxn];
ll block_len;
ll exGcd(ll a, ll b, ll &x, ll &y)
{
	ll res, temp;
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	res = exGcd(b, a%b, x, y);
	temp = x;
	x = y;
	y = temp - a / b*y;
	return res;
}
void getinv()
{
	ll x, y, i;
	inv[1] = 1;
	for (i = 2; i < maxn; i++)
	{
		exGcd(i, mod, x, y);
		inv[i] = (x % mod + mod) % mod;
	}
}
bool comp(Node& a, Node& b)
{
	if (a.block_id != b.block_id)
		return a.block_id < b.block_id;
	return a.r < b.r;
}
ll N, M;
int main()
{
	ll i, j, k, n, m;
	getinv();
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			block_len = (ll)sqrt(N);
			for (i = 1; i <= M; i++)
			{
				scanf("%lld %lld", &Q[i].l, &Q[i].r);
				Q[i].id = i;
				Q[i].block_id = Q[i].l / block_len;
			}
			sort(Q + 1, Q + 1 + M, comp);
			ll l = 1;
			ll r = 0;
			ll ans = 1;
			memset(res, 0, sizeof(res));
			memset(num, 0, sizeof(num));
			for (i = 1; i <= M; i++)
			{
				while (r < Q[i].r)
				{
					r++;
					num[ar[r]]++;
					ans = ans * (r - l + 1) % mod * inv[num[ar[r]]] % mod;
				}
				while (r > Q[i].r)
				{
					ans = ans * inv[r - l + 1] % mod * num[ar[r]] % mod;
					num[ar[r]]--;
					r--;
				}
				while (l < Q[i].l)
				{
					ans = ans * inv[r - l + 1] % mod * num[ar[l]] % mod;
					num[ar[l]]--;
					l++;
				}
				while (l > Q[i].l)
				{
					l--;
					num[ar[l]]++;
					ans = ans * (r - l + 1) % mod * inv[num[ar[l]]] % mod;
				}
				res[Q[i].id] = ans;
			}
			for (i = 1; i <= M; i++)
				printf("%lld\n", res[i]);
		}
	}
	return 0;
}