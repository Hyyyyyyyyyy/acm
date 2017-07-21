#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 1010;
const int INF = 1e10;
int N;
int dp[2100][maxn];
struct Node
{
    int fail[maxn];
    int next[maxn][26];
    int sta[maxn];
    int root;
    int CNT;
    char s[100];
    char ss[2100];
    int newnode()
    {
        for(int i = 0; i < 26; i++)
            next[CNT][i] = -1;
        fail[CNT] = -1;
        sta[CNT] = 0;
        return CNT++;
    }
    void init()
    {
        CNT = 0;
        root = newnode();
    }
    void ac_insert()
    {
        int i, j, k;
        int now = root;
        int L = strlen(s);
        for (i = 0; i < L; i++)
        {
            if (next[now][s[i] - 'A'] == -1)
            {
                next[now][s[i] - 'A'] = newnode();
            }
            now = next[now][s[i] - 'A'];
        }
        sta[now] = 1;
    }
    void ac_buildfail_bfs()
    {
        int i, j;
        int now = root;
        queue<int>q;
        for (i = 0; i < 26; i++)
        {
            if (next[root][i] == -1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            if(sta[fail[now]])
                sta[now] = 1;
            for (i = 0; i < 26; i++)
            {
                if (next[now][i] != -1)
                {
                    int temp = fail[now];
                    while (temp != -1)
                    {
                        if (next[temp][i] != -1)
                        {
                            fail[next[now][i]] = next[temp][i];
                            break;
                        }
                        temp = fail[temp];
                    }
                    if (temp == -1)
                    {
                        fail[next[now][i]] = root;
                    }
                    q.push(next[now][i]);
                }
                else
                {
                    next[now][i] = next[fail[now]][i];
                }
            }
        }
    }
    int ac_query()
    {
        int i, j, k;
        int now = root;
        int L = strlen(ss);
        for(i = 0; i <= L; i++)
        {
            for(j = 0; j <= CNT; j++)
            {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for(i = 0; i < L; i++)
        {
            for(j = 0; j < CNT; j++)
            {
                if(dp[i][j] < INF)
                {
                    for(k = 0; k < 26; k++)
                    {
                        if(k == 0 || k == 2 || k == 6 || k == 19)
                        {
                            if(sta[next[j][k]])
                                continue;
                            dp[i+1][next[j][k]] = min(dp[i+1][next[j][k]], k == ss[i] - 'A' ? dp[i][j] : dp[i][j]+1);
                        }
                    }
                }
            }
        }
        int res = INF;
        for(i = 0; i < CNT; i++)
        {
            res = min(res, dp[L][i]);
        }
        return res == INF ? -1 : res;
    }
};
Node AC;
int main()
{
    int i, j, k, u, n, m, cas = 1;
    while(scanf("%d", &N) != EOF && N)
    {
        AC.init();
        for(i = 0; i < N; i++)
        {
            scanf("%s", AC.s);
            AC.ac_insert();
        }
        AC.ac_buildfail_bfs();
        scanf("%s", AC.ss);
        printf("Case %d: %d\n", cas++, AC.ac_query());
    }
    return 0;
}