#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 100000 + 100;
struct Trie
{
	int next[maxn][26];
	int sta[maxn];
	int root;
	int CNT;
	char s[100];
	int newnode()
	{
		for (int i = 0; i < 26; i++)
		{
			next[CNT][i] = -1;
		}
		sta[CNT] = 0;
		return CNT++;
	}
	void init()
	{
		CNT = 0;
		root = newnode();
	}
	void insert()
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
		sta[now] = 1;
	}
	int search()
	{
		int i, j, k;
		int doudou = 1;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			now = next[now][s[i] - 'a'];
			if (now == -1)
			{
				break;
			}
		}
		if (now != -1)
			return 1;
		else
			return 0;
	}
};
Trie trie;
//??????trie.init()
//???????s[]??
char S[maxn][500];
int dp[maxn];
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int i, j, k, u, n, m, q, Q, x, y, N;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			trie.init();
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%s", S[i]);
				strcpy(trie.s, S[i]);
				trie.insert();
			}
			scanf("%d", &Q);
			for (q = 1; q <= Q; q++)
			{
				scanf("%d %d", &x, &y);
				memset(dp, 0, sizeof(dp));
				int L1 = strlen(S[x]);
				int L2 = strlen(S[y]);
				int L = min(L1, L2);
				dp[0] = (S[x][0] == S[y][0] ? 1 : 0);
				for (i = 1; i < L; i++)
				{
					if (S[x][i] == S[y][i])
						dp[i] = dp[i - 1] + 1;
					else
						dp[i] = 0;
				}
				int Max = 0;
				for (i = 0; i < L; i++)
				{
					memcpy(trie.s, S[x] + i - dp[i] + 1, dp[i]);
					trie.s[dp[i]] = '\0';
					if (trie.search())
					{
						Max = max(Max, dp[i]);
					}
				}
				printf("%d\n", Max);
			}
		}
	}
	return 0;
}