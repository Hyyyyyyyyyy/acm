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
const ll MOD = 1e9 + 7;
const int maxn = 3000 + 100;
int ar[maxn][maxn], dp[maxn], RES, stack[maxn][maxn];
int N;
void dfs(int dep, int num)
{
	int i, j, u, v;
	if (num == 0)
	{
		if (RES < dep)
			RES = dep;
		return;
	}
	for (i = 0; i < num; i++)
	{
		u = stack[dep][i];
		if (dep + dp[u] <= RES)
			return;
		if (dep + N - u + 1 <= RES)
			return;
		int top = 0;
		for (j = i + 1; j < num; j++)
		{
			v = stack[dep][j];
			if (ar[u][v])
				stack[dep + 1][top++] = v;
		}
		dfs(dep + 1, top);
	}
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n)  != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            memset(ar, 0, sizeof(ar));
            for(i = 1; i <= N-1; i++)
            {
                for(j = 1; j <= N-i; j++)
                {
                    scanf("%d", &ar[i][i+j]);
                    ar[i+j][i] = ar[i][i+j];
                }
            }
            int doudou = 1;
            for (i = N; i >= 1; i--)
            {
                int top = 0;
                for (j = i+1; j <= N; j++)
                    if (ar[i][j])
                        stack[1][top++] = j;
                dfs(1, top);
                dp[i] = RES;
                if (RES >= 3)
                    doudou = 0;
            }
            if(!doudou)
            {
                printf("Bad Team!\n");
            }
            else
            {
                printf("Great Team!\n");
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
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 1000000 + 10;
ll N;
int res[maxn];
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext()      //有优化
{
    int i, j, k;
    int L = strlen(former);
    Next[0] = -1;
    i = 0;
    j = -1;
    while (i < L && j < L)
    {
        if (j == -1 || former[i] == former[j])
        {
            i++;
            j++;
            //优化
            if (former[i] == former[j])
                Next[i] = Next[j];
            else
                Next[i] = j;
            //如果不要优化，这样：
            //Next[i] = j;
        }
        else
            j = Next[j];
    }
}
ll KMP()       //返回目标串在主串中出现的次数
{
    int i, j;
    GETnext();
    int L1 = strlen(former);
    int L2 = strlen(latter);
    i = 0;
    j = 0;
    int res = 0;
    while(i < L2)
    {
        if(j == -1 || latter[i] == former[j])
        {
            if(j == L1-1)
            {
                res++;
                j = -1;
            }
            i++;
            j++;
        }
        else
        {
            if(j != -1)
            {
                res[0]++;
                res[j]--;
            }
            j = Next[j];
        }
    }
    ll T = res[0] * 1;
    for(i = 1; i < L1; i++)
    {
        res[i] += res[i-1];
        T = (T + res[i] * (i+1) % MOD) % MOD;
    }
    return T;
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%s", latter);
            scanf("%s", former);
            int l1 = strlen(latter);
            int l2 = strlen(former);
            reverse(latter, latter+l1);
            reverse(former, former+l2);
            memset(res, 0, sizeof(res));
            printf("%lld\n", KMP());
        }
    }
    return 0;
}