#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 300;
const int MOD = 20090717;
int N, M, K;
int num[5000];
int dp[30][300][1024];
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
		sta[CNT] = 0;
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
		sta[now] |= (1 << n);
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
            sta[now] |= sta[fail[now]];
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
		int i, j, k, p;
        for(i = 0; i <= N; i++)
        {
            for(j = 0; j < CNT; j++)
            {
                for(k = 0; k < (1 << M); k++)
                {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < CNT; j++)
            {
                for(k = 0; k < (1 << M); k++)
                {
                    if(dp[i][j][k] > 0)
                    {
                        for(p = 0; p < 26; p++)
                        {
                            int newi = i+1;
                            int newj = next[j][p];
                            if(newj == -1)
                                continue;
                            int newk = (sta[newj] | k);
                            dp[newi][newj][newk] = (dp[i][j][k] + dp[newi][newj][newk]) % MOD;
                        }
                    }
                }
            }
        }
        int res = 0;
        for(i = 0; i < (1 << M); i++)
        {
            if(num[i] >= K)
            {
                for(j= 0; j < CNT; j++)
                {
                    res = (res + dp[N][j][i]) % MOD;
                }
            }
        }
        return res;
	}
};
Node AC;
int main()
{
	int i, j, k, u, n, m;
    for(i = 0; i < (1 << 10); i++)
    {
        num[i] = 0;
        for(j = 0; j < 10; j++)
        {
            if(i & (1 << j))
                num[i]++;
        }
    }
    while(scanf("%d %d %d", &N, &M, &K) != EOF && N+M+K)
    {
        AC.init();
        for(i = 0; i < M; i++)
        {
            scanf("%s", AC.s);
            AC.ac_insert(i);
        }
        AC.ac_buildfail_bfs();
        printf("%d\n", AC.ac_query());
    }
	return 0;
}