#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

int ar[500][500];
int dist[500], n, m;
bool visit[500];

void dijkstra();
int main()
{
    int i, j, k, u, count;
    char ch[20];
    int temp;
    while (scanf("%d %d", &n, &m) != EOF && (n || m))
    {
        count = 1;
        for (i = 0; i <= (n + 2) * (m + 2); i++)
        {
            for (j = 0; j <= (n + 2) * (m + 2); j++)
            {
                ar[i][j] = MAX;
            }
        }
        for (i = 1; i <= 2 * n + 1; i++)
        {
            if (i % 2 == 0)
            {
                u = count;
                for (j = 1; j <= m + 1; j++)
                {
                    scanf("%d %s", &temp, ch);

                    if (temp == 0)
                    {
                        count++;
                        continue;
                    }
                    temp = 2520 / temp;
                    if (ch[0] == '*')
                    {
                        ar[count][count - m - 1] = temp;
                        ar[count - m - 1][count] = temp;
                    }
                    else if (ch[0] == 'v')
                        ar[count - m - 1][count] = temp;
                    else if (ch[0] == '^')
                        ar[count][count - m - 1] = temp;
                    count++;
                }
                count = u;
            }
            else
            {
                for (j = 1; j <= m; j++)
                {
                    scanf("%d %s", &temp, ch);

                    if (temp == 0)
                    {
                        count++;
                        continue;
                    }
                    temp = 2520 / temp;
                    if (ch[0] == '*')
                    {
                        ar[count][count + 1] = temp;
                        ar[count + 1][count] = temp;
                    }
                    else if (ch[0] == '<')
                        ar[count + 1][count] = temp;
                    else if (ch[0] == '>')
                        ar[count][count + 1] = temp;
                    count++;
                }
                count++;
            }
        }
        //printf("%d\n", count);
        dijkstra();
        if (dist[(n + 1) * (m + 1)] != MAX)
            printf("%d blips\n", dist[(n + 1) * (m + 1)]);
        else
            printf("Holiday\n");
    }
    return 0;
}
void dijkstra()
{
    int i, j, u, k, midmin;
    memset(visit, false, sizeof(visit));
    for (i = 1; i <= (n + 1) * (m + 1); i++)
        dist[i] = ar[1][i];
    visit[1] = true;
    dist[1] = 0;
    for (i = 2; i <= (n + 1) * (m + 1); i++)
    {
        midmin = MAX;
        for (j = 2; j <= (n + 1) * (m + 1); j++)
        {
            if (!visit[j] && midmin > dist[j])
            {
                midmin = dist[j];
                u = j;
            }
        }
        visit[u] = true;
        for (j = 2; j <= (n + 1) * (m + 1); j++)
        {
            if (!visit[j] && dist[j] > dist[u] + ar[u][j])
            {
                dist[j] = dist[u] + ar[u][j];
            }
        }
    }
}