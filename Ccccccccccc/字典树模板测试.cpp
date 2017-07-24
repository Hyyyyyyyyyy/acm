//1001
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100000;
struct Trie
{
	int next[maxn][2];
	int sta[maxn];
	int root;
	int CNT;
	char s[100];
	int newnode()
	{
		for (int i = 0; i < 2; i++)
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
	int insert()
	{
		int i, j, k, doudou = 0;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			if (next[now][s[i] - '0'] == -1)
			{
				if (sta[now] == 1)
				{
					doudou = 1;
				}
				next[now][s[i] - '0'] = newnode();
			}
			else
			{
				if (sta[now] == 1)
					doudou = 1;
			}
			now = next[now][s[i] - '0'];
		}
		sta[now] = 1;
		for (i = 0; i < 2; i++)
			if (next[now][i] != -1)
				doudou = 1;
		return doudou;
	}
	int search()
	{
		int i, j, k;
		int now = root;
		int L = strlen(s);
		for (i = 0; i < L; i++)
		{
			now = next[now][s[i] - '0'];
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
int main()
{
	int i, doudou = 0, cas = 0;
	trie.init();
	while (scanf("%s", trie.s) != EOF)
	{
		if (trie.s[0] == '9')
		{
			cas++;
			if (doudou == 0)
				printf("Set %d is immediately decodable\n", cas);
			else
				printf("Set %d is not immediately decodable\n", cas);
			trie.init();
			doudou = 0;
			continue;
		}
		if (trie.insert())
			doudou = 1;
		else if(doudou != 1)
			doudou = 0;
	}
	return 0;
}








//1004
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100000;
char sa[10000000];
struct Trie
{
	int next[maxn][26];
	int sta[maxn];
	char sg[maxn][20];
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
		strcpy(sg[now], sa);
	}
	void search()
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
			printf("%s", sg[now]);
		else
			printf("%s", s);
	}
};
Trie trie;
int main()
{
	int i, j, k, u, n, m, L;
	trie.init();
	scanf("%s", sa);
	while (scanf("%s", sa) != EOF && strcmp(sa, "END") != 0)
	{
		scanf("%s", trie.s);
		trie.insert();
	}
	scanf("%s", sa);
	getchar();
	while (fgets(sa, 10000000, stdin) != NULL && strcmp(sa, "END\n") != 0)
	{
		j = 0;
		L = strlen(sa);
		for (i = 0; i < L; i++)
		{
			if (isalpha(sa[i]))
			{
				trie.s[j] = sa[i];
				j++;
			}
			else
			{
				trie.s[j] = '\0';
				trie.search();
				putchar(sa[i]);
				j = 0;
			}
		}
	}
	return 0;
}









//1008
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 5000000;
struct Trie
{
	int next[maxn][26];
	int sta[maxn];
	int id[maxn];
	int num[maxn];
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
		id[CNT] = -1;
		num[CNT] = 0;
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
				id[CNT - 1] = n;
				num[CNT - 1] = 1;
			}
			now = next[now][s[i] - 'a'];
			if (id[now] != n)
			{
				num[now]++;
				id[now] = n;
			}
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
		if (now != -1)
			return num[now];
		else
			return 0;
	}
};
Trie trie;
int main()
{
	int i, j, m, n, k, u, L, count;
	char ar[30], sa[30];
	trie.init();
	scanf("%d", &n);
	for (m = 0; m < n; m++)
	{
		scanf("%s", ar);
		L = strlen(ar);
		for (i = 0; i < L; i++)
		{
			strcpy(trie.s, ar + i);
			trie.insert(m);
		}
	}
	scanf("%d", &k);
	for (u = 0; u < k; u++)
	{
		scanf("%s", trie.s);
		printf("%d\n", trie.search());
	}
	return 0;
}