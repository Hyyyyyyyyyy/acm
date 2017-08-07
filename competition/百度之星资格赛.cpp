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
typedef unsigned long long ll;
const int maxn = 1000 + 10;
int dp[maxn];
int sco[110], cost[110];
struct Node
{
	int stack[110];
	int top;
	int sum;
};
Node ar[maxn];
int main()
{
	int i, j, k, u, n, m, cas = 1, N, B, T;
	while (scanf("%d", &T) != EOF)
	{
		for (m = 1; m <= T; m++)
		{
			scanf("%d", &B);
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &sco[i], &cost[i]);
			}
			for (i = 0; i <= B; i++)
			{
				ar[i].top = 0;
				ar[i].sum = 0;
				dp[i] = -INF;
			}
			dp[0] = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = B; j >= cost[i]; j--)
				{
					if (dp[j] < dp[j - cost[i]] + sco[i])
					{
						dp[j] = dp[j - cost[i]] + sco[i];
						ar[j] = ar[j - cost[i]];
						ar[j].stack[++ar[j].top] = i;
						ar[j].sum += i;

					}
					else if(dp[j] == dp[j - cost[i]] + sco[i] && ar[j].sum > ar[j - cost[i]].sum && ar[j - cost[i]].sum > 0)
					{
						ar[j] = ar[j - cost[i]];
					}
				}
			}
			printf("Case #%d:\n", m);
			int Max = -INF;
			int Maxi;
			int Maxs = INF;
			for (i = B; i >= 0; i--)
				if (Max < dp[i] || (Maxs > ar[i].sum && Max == dp[i] && ar[i].sum > 0))
					Max = dp[i], Maxi = i, Maxs = ar[i].sum;
			printf("%d %d\n", Max, Maxi);
			if (ar[Maxi].top > 0)
			{
				for (i = 1; i <= ar[Maxi].top; i++)
				{
					if (i != 1)
						putchar(' ');
					printf("%d", ar[Maxi].stack[i]);
				}
				printf("\n");
			}
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
typedef unsigned long long ll;
const int maxn = 100000 + 10;
struct mon
{
    int xue;
    int fang;
};
mon ar[maxn];
struct ji
{
    int jing;
    int shang;
    double x;
};
ji sa[1000+10];
bool comp(const ji& a, const ji& b)
{
    return a.x > b.x;
}
int main()
{
    int i, j, k, u, n, m, a, b;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        for(i = 1; i <= N; i++)
        {
            scanf("%d %d", &ar[i].xue, ar[i].fang);
        }
        for(i = 1; i <= M; i++)
        {
            scanf("%d %d", &sa[i].jing, &sa[i].shang);
            sa[i].x = (double)sa[i].shang / (double)sa[i].jing;
        }
        sort(sa+1, sa+1+M, comp);
        for(i = 1; i <= N; i++)
        {

        }
    }
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
typedef unsigned long long ll;
const int maxn = 3000 + 10;
int fa[maxn];
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}
int ar[maxn][maxn];
int main()
{
	int i, j, k, u, n, m, N, M, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			fa[i] = i;
		}
		int res = INF;
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			int t1 = find(a);
			int t2 = find(b);
			if (t1 != t2)
			{
				fa[t2] = t1;
			}
			ar[t1][t2] += c;
			ar[t2][t1] += c;
		}
		//int res = INF;
		// for(i = 1; i <= N; i++)
		// {
		//     if(fa[i] != i)
		//     {
		//         int Min = INF;
		//         for(j = 1; j <= N; j++)
		//         {
		//             if(ar[i][j])
		//                 Min = min(Min, ar[i][j]);
		//         }
		//         res = min(res, Min);
		//     }
		// }
        for(i = 1; i <= N; i++)
            if(fa[i] == i)
                break;
        for(j = 1; j <= N; j++)
			if(ar[i][j])
            	res = min(ar[i][j], res);
		printf("%d\n", res);
	}
	return 0;
}