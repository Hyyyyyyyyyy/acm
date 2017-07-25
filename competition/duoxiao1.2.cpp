#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cctype>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const ll MOD = 1e9 + 7;
const int maxn = 100000 + 100;
ll visit[26];
ll ar[26][maxn];
struct Node
{
	ll w;
	ll id;
};
Node sa[26];
ll Pow[maxn];
char s[maxn];
bool comp(const Node& a, const Node& b)
{
	ll i;
	for (i = 100000; i >= 0; i--)
		if (ar[a.id][i] != ar[b.id][i])
			return ar[a.id][i] < ar[b.id][i];
	return 0;
}
int main()
{
	ll i, j, k, u, n, m, N;
	int cas = 1;
	Pow[0] = 1;
	for (i = 1; i <= 100000; i++)
		Pow[i] = (Pow[i - 1] * 26) % MOD;
	while (scanf("%lld", &N) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(visit, 0, sizeof(visit));
		for (i = 1; i <= N; i++)
		{
			scanf("%s", s);
			ll L = strlen(s);
			if(L > 1)
				visit[s[0] - 'a'] = 1;
			for (j = 0ll; j < L; j++)
			{
				ar[s[j] - 'a'][L - j - 1]++;
				if (ar[s[j] - 'a'][L - j - 1] >= 26)
				{
					ar[s[j] - 'a'][L - j - 1] -= 26;
					ar[s[j] - 'a'][L - j]++;
				}
			}
		}
		for (i = 0; i < 26; i++)
			sa[i].w = 0, sa[i].id = i;
		sort(sa, sa + 26, comp);
		for (i = 0; i < 26; i++)
		{
			for (j = 0; j <= 100000; j++)
			{
				if (ar[sa[i].id][j] == 0)
					continue;
				sa[i].w = (sa[i].w + (ar[sa[i].id][j] * Pow[j] % MOD)) % MOD;
			}
		}
		if (visit[sa[0].id])
		{
			for (i = 1; i < 26; i++)
			{
				if (!visit[sa[i].id])
				{
					for (j = i; j > 0; j--)
						swap(sa[j], sa[j - 1]);
					break;
				}
			}
		}
		ll res = 0;
		for (i = 1; i < 26; i++)
		{
			res = (res + (i * sa[i].w % MOD)) % MOD;
		}
		//ll zero = -1;
		//for (i = 0; i < 26; i++)
		//{
		//	if (!visit[sa[i].id])
		//	{
		//		zero = sa[i].id;
		//		break;
		//	}
		//}
		//ll res = 0;
		//ll x = 25ll;
		//for (i = 25; i >= 0; i--)
		//{
		//	if(zero != sa[i].id)
		//		res = (res + ((x--) * sa[i].w % MOD)) % MOD;
		//}
		printf("Case #%d: %lld\n", cas++, res);
	}
	return 0;
}