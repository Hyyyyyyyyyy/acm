#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 5000 + 100;
const int maxm = 1000000 + 100;
int N;
struct Trie
{
	int next[maxn][26];
	int sta[maxn];
	int root;
	int CNT;
	char s[50];
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
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			now = next[now][s[i] - 'a'];
			if (now == -1)
				break;
		}
		if (now != -1 && sta[now])
			return 1;
		else
			return 0;
	}
};
Trie trie;
//别忘了初始化trie.init()
//插入和查询都用s[]数组

char res[50];
char S[110][50];
bool dfs(int u, int dep, int D)
{
	int i, j, k;
	if (dep > D)
		return false;
	if (dep == D)
	{
		for (i = 0; i < 26; i++)
		{
			if (trie.next[u][i] == -1)
			{
				res[dep] = 'a' + i;
				res[dep + 1] = 0;
				return true;
			}
		}
		return false;
	}
	for (i = 0; i < 26; i++)
	{
		res[dep] = 'a' + i;
		if (dfs(trie.next[u][i], dep + 1, D))
			return true;
	}
    return false;
}
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			trie.init();
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%s", S[i]);
			}
			int doudou = 0;
			for (i = 1; i <= 31; i++)
			{
				trie.init();
				for (j = 1; j <= N; j++)
				{
					int L = strlen(S[j]);
					for (int p = 0; p <= L - i; p++)
					{
						for (int q = 0; q < i; q++)
						{
							trie.s[q] = S[j][q + p];
						}
						trie.s[i] = 0;
						trie.insert();
					}
				}
				if (dfs(0, 1, i))
				{
					doudou = 1;
					break;
				}
				if (doudou)
					break;
			}
			puts(res + 1);
		}
	}
	return 0;
}
//构造的名字最多3位
//26*26*26 > 30*100