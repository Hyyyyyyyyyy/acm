#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 51 * 1001;
int N;
struct Node
{
	int fail[maxn];
	int next[maxn][128];
	int sta[maxn];
	int num[1010];
	int root;
	int CNT;
	char s[60];
	char ss[2000010];
	int newnode()
	{
		for (int i = 0; i < 128; i++)
			next[CNT][i] = -1;
		fail[CNT] = -1;
		sta[CNT] = 0;
		return CNT++;
	}
	void init()
	{
		CNT = 0;
		root = newnode();
		memset(num, 0, sizeof(num));
	}
	void ac_insert(int n)
	{
		int i, j, k;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			if (next[now][s[i]] == -1)
			{
				next[now][s[i]] = newnode();
			}
			now = next[now][s[i]];
		}
		sta[now] = n;
	}
	void ac_buildfail_bfs()
	{
		int i, j;
		int now = root;
		queue<int>q;
		for (i = 0; i < 128; i++)
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
			for (i = 0; i < 128; i++)
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
		int i, j;
		int res = 0;
		int now = root;
		int L = strlen(ss);
		for (i = 0; i < L; i++)
		{
			now = next[now][ss[i]];
			int temp = now;
			while (temp != -1)
			{
				if (sta[temp])
				{
					num[sta[temp]]++;
				}
				temp = fail[temp];
			}
		}
	}
};
Node AC;
char ar[1001][60];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &N) != EOF)
	{
		AC.init();
		for (i = 1; i <= N; i++)
		{
			scanf("%s", AC.s);
			strcpy(ar[i], AC.s);
			AC.ac_insert(i);
		}
		AC.ac_buildfail_bfs();
		scanf("%s", AC.ss);
		AC.ac_query();
		for (i = 1; i <= N; i++)
		{
			if (AC.num[i])
			{
				printf("%s: %d\n", ar[i], AC.num[i]);
			}
		}
	}
	return 0;
}