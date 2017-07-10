#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100000 + 10;
typedef long long ll;
struct Node
{
	ll val;
	ll cost;
};
Node ar[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.cost < b.cost;
}
ll N, M;
bool check(ll mid, ll num0)
{
	ll i, j;
	ll cost = 0;
	ll num = 0;
	for (i = 0; i < N; i++)
	{
		if (ar[i].val >= mid)
		{
            if(cost + ar[i].cost <= M)
            {
                num++;
				cost += ar[i].cost;
            }
            else
                break;
		}
	}
	return num == num0;
}
int main()
{
	ll i, j, k, u, n, m, a;
	ll b;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			ll MAX = 0;
			for (i = 0; i < N; i++)
			{
				scanf("%lld %lld", &ar[i].val, &ar[i].cost);
				if (MAX < ar[i].val)
					MAX = ar[i].val;
			}
			sort(ar, ar + N, comp);
			ll cost = 0;
			for (i = 0; i < N; i++)
			{
				cost += ar[i].cost;
				if (cost > M)
				{

					break;
				}
			}
			ll l = 0;
			ll r = MAX;
			ll mid;
			while (r >= l)
			{
				mid = (l + r) / 2;
				if (check(mid, i))
					l = mid + 1;
				else
					r = mid - 1;
			}
			printf("%lld %lld\n", i, r);
		}
	}
	return 0;
}