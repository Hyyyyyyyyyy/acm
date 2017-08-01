#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100000 + 10;
typedef long long ll;
ll c1[maxn], c2[maxn];
ll S[maxn];
ll N, M;
char s[10];
void update(ll x,ll val)
{
	ll i, j;
	for (i = x; i <= N; i += i & -i)
	{
		c1[i] += val;
		c2[i] += val*x;
	}
}
ll getsum(ll x)
{
	ll i;
	ll res = 0;
	for (i = x; i >= 1; i -= i&-i)
	{
		res += (x + 1)*c1[i] - c2[i];
	}
	return res;
}
int main()
{
	ll i, j, k, u, n, m, a, b, c;
	while (scanf("%lld %lld", &N, &M) != EOF)
	{
		S[0] = 0;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &S[i]);
			S[i] += S[i - 1];
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%s", s);
			if (s[0] == 'C')
			{
				scanf("%lld %lld %lld", &a, &b, &c);
				update(a, c);
				update(b + 1, -c);
			}
			else
			{
				scanf("%lld %lld", &a, &b);
				printf("%lld\n", S[b] - S[a-1] + getsum(b) - getsum(a - 1));
			}
		}
	}
	return 0;
}