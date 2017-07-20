#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 300010;
int N;
struct Node
{
	int fail[maxn];
	int next[maxn][26];
	int sta[maxn];
	int root;
	int CNT;
	char s[100];
	char ss[1000010];
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
			if (next[now][s[i] - 'a'] == -1)
			{
				next[now][s[i] - 'a'] = newnode();
			}
			now = next[now][s[i] - 'a'];
		}
		sta[now]++;
	}
	void ac_buildfail_bfs()
	{
		int i, j;
		int now = root;
		queue<int>q;
		for (i = 0; i < 26; i++)
		{
			if (next[root][i] != -1)
			{
				fail[next[root][i]] = root;
				q.push(next[root][i]);
			}
		}
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			for (i = 0; i < MAX; i++)
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
			}
		}
	}
	int ac_query()
	{
		int i, j;
		int res = 0;
		int now = root;
		int L = strlen(ss);
		for (i = 0; i < L; i++)
		{
			while (next[now][ss[i] - 'a'] == -1 && now != root)
				now = fail[now];
			now = next[now][ss[i] - 'a'];
			if (now == -1)
				now = root;
			int temp = now;
			while (temp != root)
			{
				res += sta[temp];
				sta[temp] = 0;
				temp = fail[temp];
			}
		}
		return res;
	}
};
Node AC;
int main()
{
	int i, j, k, u, n, m;
    scanf("%d", &N);
    AC.init();
    for (i = 1; i <= N; i++)
    {
        scanf("%s", AC.s);
        AC.ac_insert();
    }
    AC.ac_buildfail_bfs();
    scanf("%s", AC.ss);
    printf("%d\n", AC.ac_query());
	return 0;
}