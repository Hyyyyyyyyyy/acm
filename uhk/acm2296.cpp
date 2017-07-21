#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 110*11;
const int INF = 2e10;
int N, M;
int ar[maxn];
int dp[60][maxn];
char ss[60][maxn][60];
bool comp(char *s1, char *s2)
{
    int L1 = strlen(s1);
    int L2 = strlen(s2);
    if(L1 != L2)
        return L1 < L2;
    else
        return strcmp(s1, s2) < 0;
}
struct Node
{
	int fail[maxn];
	int next[maxn][26];
	int sta[maxn];
	int root;
	int CNT;
	char s[100];
	int newnode()
	{
		for(int i = 0; i < 26; i++)
			next[CNT][i] = -1;
		fail[CNT] = -1;
		sta[CNT] = -1;
		return CNT++;
	}
	void init()
	{
		CNT = 0;
		root = newnode();
	}
	void ac_insert(int n)
	{
		int i, j, k;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			if (next[now][s[i] - 'a'] == -1)
			{
				next[now][s[i] - 'a'] = newnode();
			}
			now = next[now][s[i] - 'a'];
		}
		sta[now] = n;
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
	void ac_query()
	{
		int i, j, k, p;
        char res[60];
        char t[60];
        for(i = 0; i <= N; i++)
        {
            for(j = 0; j < CNT; j++)
                dp[i][j] = -INF;
        }
        dp[0][0] = 0;
        strcpy(ss[0][0], "");
        strcpy(res, "");
        int MAX = 0;
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < CNT; j++)
            {
                if(dp[i][j] >= 0)
                {
                    strcpy(t, ss[i][j]);
                    int L = strlen(t);
                    for(k = 0; k < 26; k++)
                    {
                        t[L] = k + 'a';
                        t[L+1] = '\0';
                        int tt = dp[i][j];
                        if(sta[next[j][k]] != -1)
                        	tt += ar[sta[next[j][k]]];
                        if(dp[i+1][next[j][k]] < tt || (dp[i+1][next[j][k]] == tt && comp(t, ss[i+1][next[j][k]])))
                        {
                            dp[i+1][next[j][k]] = tt;
                            strcpy(ss[i+1][next[j][k]], t);
                            if(MAX < tt || (MAX == tt && comp(t, res)))
                            {
                                MAX = tt;
                                strcpy(res, t);
                            }
                        }
                    }
                }
            }
        }
        printf("%s\n", res);
	}
};
Node AC;
int main()
{
	int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &N, &M);
            AC.init();
            for(i = 0; i < M; i++)
            {
                scanf("%s", AC.s);
                AC.ac_insert(i);
            }
            AC.ac_buildfail_bfs();
            for(i = 0; i < M; i++)
                scanf("%d", &ar[i]);
            AC.ac_query();
        }
    }
	return 0;
}