#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 210 * 500;
int N;
struct Node
{
	int fail[maxn];
	int next[maxn][128];
	int sta[maxn];
	int root;
	int CNT;
	int stack[501];
	int top;
	char ss[10010];
	int newNode()
	{
		int i;
		for (i = 0; i < 128; i++)
			next[CNT][i] = -1;
		fail[CNT] = -1;
		sta[CNT] = 0;
		return CNT++;
	}
	void init()
	{
		CNT = 0;
		root = newNode();
	}
	void ac_insert(int n)
	{
		int i, j, k;
		int now = root;
		int L = strlen(ss);
		for (i = 0; i < L; i++)
		{
			if (next[now][ss[i]] == -1)
			{
				next[now][ss[i]] = newNode();
			}
			now = next[now][ss[i]];
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
		top = 0;
		int now = root;
		int L = strlen(ss);
		for (i = 0; i < L; i++)
		{
			now = next[now][ss[i]];
			int temp = now;
			while (temp != -1)
			{
				if (sta[temp])
					stack[++top] = sta[temp];
				temp = fail[temp];
			}
		}
	}
};
Node AC;
int main()
{
	int i, j, k, u, n, m, cnt;
	while (scanf("%d", &N) != EOF)
	{
		AC.init();
		for (i = 1; i <= N; i++)
		{
			scanf("%s", AC.ss);
			AC.ac_insert(i);
		}
		AC.ac_buildfail_bfs();
		scanf("%d", &N);
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%s", AC.ss);
			AC.ac_query();
			if (AC.top > 0)
			{
				sort(AC.stack + 1, AC.stack + 1 + AC.top);
				printf("web %d: ", i);
				for (j = 1; j <= AC.top; j++)
				{
					if (j != 1)
						putchar(' ');
					printf("%d", AC.stack[j]);
				}
				putchar('\n');
				cnt++;
			}
		}
		printf("total: %d\n", cnt);
	}
	return 0;
}