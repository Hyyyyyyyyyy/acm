#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 10000;
struct Node
{
	char s[1010];
	int w;
};
Node node[1010];
struct Trie
{
	int next[maxn][26];
	vector<int>G[maxn];
	int root;
	int CNT;
	char s[100];
	int newnode()
	{
		for (int i = 0; i < 26; i++)
		{
			next[CNT][i] = -1;
		}
		G[CNT].clear();
		return CNT++;
	}
	void init()
	{
		CNT = 0;
		root = newnode();
	}
	void insert(int n)
	{
		int i, j, k;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			if (next[now][s[i] - 'a'] == -1)
			{
				next[now][s[i] - 'a'] = newnode();
				G[next[now][s[i] - 'a']].push_back(n);
			}
			else
			{
				G[next[now][s[i] - 'a']].push_back(n);
			}
			now = next[now][s[i] - 'a'];
		}
	}
	int search(int n)
	{
		int i, j, k;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			now = next[now][s[i] - 'a'];
			if (now == -1)
				break;
		}
		if (now != -1)
		{
			int num = 0;
			for (i = 0; i < G[now].size(); i++)
				if (node[G[now][i]].w <= node[n].w)
					num++;
			return num;
		}
		else
			return 0;
	}
};
Trie trie;
int main()
{
	int i, j, k, u, n, m, N, Q, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			trie.init();
			for (i = 1; i <= N; i++)
			{
				scanf("%s%d", node[i].s, &node[i].w);
				int L = strlen(node[i].s);
				reverse(node[i].s, node[i].s + L);
				strcpy(trie.s, node[i].s);
				trie.insert(i);
			}
			scanf("%d", &Q);
			for (i = 1; i <= Q; i++)
			{
				scanf("%d", &a);
				if (a == 2)
				{
					scanf("%d", &b);
					strcpy(trie.s, node[b].s);
					printf("%d\n", trie.search(b));
				}
				else
				{
					scanf("%d %d", &b, &c);
					node[b].w = c;
				}
			}
		}
	}
	return 0;
}