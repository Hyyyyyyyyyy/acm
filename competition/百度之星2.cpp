#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1000000007;
const int maxn = 10000;
ll C[maxn];
int main()
{
    ll i, j, k, u, n, m, N, M;
    while(scanf("%lld", &n) != EOF)
    {
        for(m  = 1; m <= n; m++)
        {
            scanf("%lld %lld", &N, &M);
            if(N > M)
                swap(N, M);
            for(i = 1; i <= M; i++)  
            {  
                C[i] = 1;
                for(j = i-1; j >= 1; j--)  
                {  
                    C[j] = (C[j-1] + C[j]) % MOD; 
                }  
                C[0] = 1;
            }
            printf("%lld\n", C[N]);
        }
    }
    return 0;
}










#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef __int64 ll;
const ll MOD = 1000000007;
const int maxn = 100000+100;
ll dp[manx];
ll dd[maxn];
struct Node
{
    ll l;
    ll r;
    ll len;
};
Node ar[maxn];
bool comp(Node& a, Node& b)
{
    if(a.l != b.l)
        return a.l < b.l;
    else
        return a.r > b.r;
}
ll stack[maxn];
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%I64d %I64d", &N, &M) != EOF)
    {
        for(m = 1; m <= N; m++)
        {
            scanf("%I64d %I64d", &ar[m].l, &ar[m].r);
        }
        sort(ar+1, ar+1+N, comp);
        memset(dp, 0, sizeof(dp));
        int cnt = 0;
        for(i = 1; i <= N; i++)
        {
            if(R[cnt] < ar[i].l)
            {
                dp[++cnt] = ar[i].r - ar[i].l + 1;
                L[cnt] = ar[i].l;
                R[cnt] = ar[i].r;
            }
            else if(R[cnt] >= ar[i].l && L[cnt] < ar[i].l)
            {
                dp[++cnt] = ar[i].r - L[cnt-1] + 1;
                L[cnt] = L[cnt-1];
                R[cnt] = ar[i].r;
            }
            else if(L[cnt] <= ar[i].l && ar[i].r > R[cnt])
            {
                dp[++cnt] = ar[i].r - L[cnt-1] + 1;
                L[cnt] = L[cnt-1];
                R[cnt] = ar[i].r;
            }
        }
        ll res = 0;
        int top = 0;
        ll t = M;
        int doudou = 1;
        ll Max = 0;
        dd[1] = 0;
        for(i = 2; i <= cnt; i++)
        {
            dd[i] = L[i] - R[i-1];
        }
        for(i = 1; i <= cnt; i++)
        {
            bag[i] = max(bag[i], bag[i-1])
        }
    }
}



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 11;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll dp[11][11][5][5];
int ar[1100];
char s[1100];
int Count;
ll dfs(int pos, int pre, int limit, int sta, int first);
ll solve();
int main()
{
	int i, j, u, max, a, b;
	ll n, m, k, res;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &a) != EOF)
	{
		for (b = 1; b <= a; b++)
		{
			scanf("%s", &s);
			//printf("%lld %lld\n", solve(m), solve(n - 1));
			printf("%lld\n", solve() - 1);
		}
	}
	return 0;
}
ll solve()
{
	int i, j;
	Count = strlen(s);
	for (i = 0; i < Count; i++)
	{
		ar[i + 1] = s[Count - i - 1] - '0';
	}
	return dfs(Count, 0, 1, 2, 1);
}
ll dfs(int pos, int pre, int limit, int sta, int first)
{
	int i, j, k, max;
	ll res = 0;
	if (pos == 0)
		return 1;
	if (!limit && dp[pos][pre][sta][first] != -1)
		return dp[pos][pre][sta][first];
	max = limit ? ar[pos] : 9;
	for (i = 0; i <= max; i++)
	{
        if(first)
        {
            res += dfs(pos - 1, i, limit && i == ar[pos], sta, first && i == 0);
            res %= MOD;
            continue;
        }
		if (sta == 2)
		{
			if (pos == Count)
			{
				res += dfs(pos - 1, i, limit && i == ar[pos], sta, first && i == 0);
				res %= MOD;
			}
			else if (i == pre)
			{
				res += dfs(pos - 1, i, limit && i == ar[pos], sta, first && i == 0);
				res %= MOD;
			}
			else
			{
				res += dfs(pos - 1, i, limit && i == ar[pos], (i > pre ? 1 : 0), first && i == 0);
				res %= MOD;
			}
			continue;
		}
		if (i < pre && sta == 1)
		{
			continue;
		}
		else if (i > pre && sta == 0)
		{
			res += dfs(pos - 1, i, limit && i == ar[pos], 1, first && i == 0);
			res %= MOD;
		}
		else
		{
			res += dfs(pos - 1, i, limit && i == ar[pos], sta, first && i == 0);
			res %= MOD;
		}
	}
	if (!limit)
		dp[pos][pre][sta][first] = res;
	return res;
}