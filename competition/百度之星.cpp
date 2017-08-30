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
const int maxn = 50000 + 100;
int Y, M, D, res;
bool check(int mid)
{
	int m = M;
	int d = D+1;
	if (m == 1 || m == 2)
	{
		m += 12;
		mid--;
	}
	if ((d + 2 * m + 3 * (m + 1) / 5 + mid + mid / 4 - mid / 100 + mid / 400) % 7 == res)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int i, j, k, u, n;
	while (scanf("%d", &n) != EOF)
	{
		for (u = 1; u <= n; u++)
		{
			scanf("%d-%d-%d", &Y, &M, &D);
			int y = Y;
			int m = M;
			int d = D+1;
			if (m == 1 || m == 2)
			{
				m += 12;
				y--;
			}
			res = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
			for (i = Y + 1;; i++)
			{
                if(M == 2 && D == 29 && !(i % 4 == 0 && i % 100 != 0 && i % 400 == 0))
                    continue;
				if (check(i))
				{
					break;
				}
			}
			printf("%d\n", i);
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
const int maxn = 50000 + 100;
int main()
{
    int i, j, k, u, n, m, P;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &P);
            int t = abs(1 - P);
            int res = 0;
            for(i = 1;  i <= P; i++)
            {
                if(t % i == 0)
                    res++;
            }
            printf("%d\n", res);
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
const int maxn = 200;
int N, M, doudou, flag, flag0, flag1, cnt;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int ar[maxn][maxn];
void dfs(int x, int y)
{
    int i, j;
    if(ar[x][y] == '1')
    {
        for(i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx > N || xx < 1 || yy > M || yy < 1 || ar[xx][yy] == '0' || visit[xx][yy])
                continue;
            visit[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
    else
    {
        for(i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx > N || xx < 1 || yy > M || yy < 1)
            {
                flag1 = 1;
                continue;
            }
            if(visit[xx][yy])
                continue;
            if(ar[xx][yy] == '1')
                continue;
            visit[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        for(i = 1; i <= N; i++)
        {
            scanf("%s", ar[i]+1);
            doudou = 0;
            flag = 0;
            cnt = 0;
            memset(visit, 0, sizeof(visit));
            for(i = 1;  i <= N; i++)
            {
                for(j = 1; j <= M; j++)
                {
                    if(doudou && !visit[i][j] && ar[i][j] == '1')
                    {
                        flag = -1;
                        break;
                    }
                    if(ar[i][j] == '1')
                        doudou = 1;
                    if(!visit[i][j])
                    {
                        flag1 = 0;
                        dfs(i, j);
                        if(flag1 == 0 && ar[i][j] == '0')
                            cnt++;
                    }
                }
                if(flag == -1)
                    break;
            }
            if(cnt == 1 && flag != -1 && doudou)
                printf("0\n");
            else if(flag != -1 && cnt == 0 && doudou)
                printf("1\n");
            else
                printf("-1\n");
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
typedef long long ll;
const int maxn = 100;
int N, M, bx, by, ex, ey, F;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char ar[maxn][maxn];
int visit[maxn][maxn][2][2];
struct Node
{
    int x;
    int y;
    int step;
    int sta;
    int F;
    bool operator < (const Node& a) const
    {
        return step > a.step;
    }
};
Node now, after;
int bfs()
{
	int i, j;
    priority_queue<Node>q;
    F = 0;
    now.x = bx;
    now.y = by;
    now.step = 0;
    now.sta = 0;
    now.F = 0;
    visit[bx][by][0][0] = 1;
    q.push(now);
    while(!q.empty())
    {
        now = q.top();
        q.pop();
        if(now.x == ex && now.y == ey)
            return now.step;
        for(i = 0; i < 4; i++)
        {
            after.x = now.x + dir[i][0];
            after.y = now.y + dir[i][1];
            after.step = now.step + 1;
            after.sta = now.sta;
            if(ar[after.x][after.y] == '*')
                after.F = now.F ^ 0;
            if(ar[after.x][after.y] == 'K')
                after.sta = 1;
            if(after.x > N || after.x < 1 || after.y > M || after.y < 1 || visit[after.x][after.y][after.sta][after.F])
                continue;
            if(after.F == 0 && ar[after.x][after.y] == 'x')
                continue;
            if(after.F == 1 && ar[after.x][after.y] == '.')
                continue;
            if(ar[after.x][after.y] == 'E' && after.sta == 0)
                continue;
            visit[after.x][after.y][after.sta][after.F] = 1;
            q.push(after);
        }
    }
    return -1;
}
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m  = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &M);
            for(i = 1; i <= N; i++)
            {
                scanf("%s", ar[i]+1);
                for(j = 1; j <= M; j++)
                {
                    if(ar[i][j] == 'S')
                    {
                        bx = i;
                        by = j;
                    }
                    if(ar[i][j] == 'E')
                    {
                        ex = i;
                        ey = j;
                    }
                }
            }
            memset(visit, 0, sizeof(visit));
            printf("Case #%d:\n%d\n", m, bfs());
        }
    }
    return 0;
}