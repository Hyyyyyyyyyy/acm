#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool visit[30];
int ar[30][30];
int res, a;
int link[30];
bool dfs(int f);
int main()
{
    int i, j, k, n, m, u;
    char leftN[30][3], rightN[30][3];
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &a);
            for (i = 1; i <= a; i++)
            {
                scanf("%s", rightN[i]);
                if (rightN[i][1] == 'H')
                    rightN[i][1] = '4';
                else if (rightN[i][1] == 'S')
                    rightN[i][1] = '3';
                else if (rightN[i][1] == 'D')
                    rightN[i][1] = '2';
                else if (rightN[i][1] == 'C')
                    rightN[i][1] = '1';
                if (rightN[i][0] == 'T')
                    rightN[i][0] = 'A';
                else if (rightN[i][0] == 'A')
                    rightN[i][0] = 'T';
                else if (rightN[i][0] == 'K')
                    rightN[i][0] = 'Q';
                else if (rightN[i][0] == 'Q')
                    rightN[i][0] = 'K';
                rightN[i][2] = '\0';
            }
            for (i = 1; i <= a; i++)
            {
                scanf("%s", leftN[i]);
                if (leftN[i][1] == 'H')
                    leftN[i][1] = '4';
                else if (leftN[i][1] == 'S')
                    leftN[i][1] = '3';
                else if (leftN[i][1] == 'D')
                    leftN[i][1] = '2';
                else if (leftN[i][1] == 'C')
                    leftN[i][1] = '1';
                if (leftN[i][0] == 'T')
                    leftN[i][0] = 'A';
                else if (leftN[i][0] == 'A')
                    leftN[i][0] = 'T';
                else if (leftN[i][0] == 'K')
                    leftN[i][0] = 'Q';
                else if (leftN[i][0] == 'Q')
                    leftN[i][0] = 'K';
                leftN[i][2] = '\0';
            }
            memset(ar, 0, sizeof(ar));
            memset(link, -1, sizeof(link));
            res = 0;
            for (i = 1; i <= a; i++)
            {
                for (j = 1; j <= a; j++)
                {
                    if (strcmp(leftN[i], rightN[j]) > 0)
                        ar[i][j] = 1;
                }
            }
            for (i = 1; i <= a; i++)
            {
                memset(visit, false, sizeof(visit));
                if (dfs(i))
                    res++;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
bool dfs(int f)
{
    int i, j, k;
    for (i = 1; i <= a; i++)
    {
        if (!visit[i] && ar[f][i])
        {
            visit[i] = true;
            if (link[i] == -1 || dfs(link[i]))
            {
                link[i] = f;
                return true;
            }
        }
    }
    return false;
}