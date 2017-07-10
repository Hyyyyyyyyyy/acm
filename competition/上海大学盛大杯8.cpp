#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 20000 + 100;
typedef long long ll;
ll ar[maxn];
vector<ll>G[maxn];
ll N, M;
bool comp(ll a, ll b)
{
	return a > b;
}
int main()
{
	ll i, j, k, u, n, m, a, b;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			for (i = 0; i < N; i++)
			{
				scanf("%lld", &ar[i]);
				G[i].clear();
			}
			for (i = 1; i <= N - 1; i++)
			{
				for (j = 0; j <= N - 1; j += i)
				{
					G[i].push_back(ar[j]);
				}
				sort(G[i].begin(), G[i].end(), comp);
			}
			for (i = 1; i <= M; i++)
			{
				scanf("%lld %lld", &a, &b);
				if(a >= N)
                {
                    if(b == 1)
                        printf("%lld\n", ar[0]);
                    else
                        printf("-1\n");
                }
                else
                {
                    if(b > G[a].size())
                    	printf("-1\n");
                    else
                        printf("%lld\n", G[a][b-1]);
                }
			}
		}
	}
	return 0;
}