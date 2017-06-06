#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int visit[60][60];
char ar[60][60];
int dir[4][2] = {0, -1, -1, 0, 1, 0, 0, 1};
int N, M, X, Y;
bool dfs(char ch, int num, int x, int y);
int main()
{
    int i, j, k, n, m, u, a, b, c, doudou;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        for(i = 1; i <= N; i++)
        {
            scanf("%s", ar[i]+1);
        }
        memset(visit, 0, sizeof(visit));
        doudou = 0;
        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= M; j++)
            {
                memset(visit, 0, sizeof(visit));
                for(k = 0; k < 4; k++)
                {
                    if(i + dir[k][0] < 1 || i + dir[k][0] > N || j + dir[k][1] < 1 || j + dir[k][1] > M)
                        continue;
                    if(ar[i+dir[k][0]][j+dir[k][1]] != ar[i][j])
                        continue;
                    X = i;
                    Y = j;
                    if(dfs(ar[i+dir[k][0]][j+dir[k][1]], 2, i + dir[k][0], j + dir[k][1]))
                    {
                        printf("Yes\n");
                        doudou = 1;
                        break;
                    }
                }
                if(doudou)
                    break;
            }
            if(doudou)
                break;
        }
        if(!doudou)
            printf("No\n");
    }
    return 0;
}
bool dfs(char ch, int num, int x, int y)
{
    int i, j, k, t, u, v;
    if(x == X && y == Y && num >= 4)
        return true;
    visit[x][y] = 1;
    for(i = 0; i < 4; i++)
    {
        u = x + dir[i][0];
        v = y + dir[i][1];
        if(visit[u][v])
            continue;
        if(u < 1 || u > N || v < 1 || v > M)
            continue;
        if(ar[u][v] != ch)
            continue;
        if(u == X && v == Y && num < 4)
            continue;
        if(dfs(ch, num+1, u, v))
            return true;
    }
    visit[x][y] = 0;
    return false;
}
