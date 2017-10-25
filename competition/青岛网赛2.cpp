#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;
const int maxn = 200000;
int N;
struct Node
{
	int mark[maxn];
    int fail[maxn];
    int next[maxn][26];
    int sta[maxn];
    int root;
    int CNT;
    char s[100];
    char ss[1000010];
    int newnode()
    {
        for (int i = 0; i < 26; i++)
            next[CNT][i] = -1;
        fail[CNT] = -1;
		sta[CNT] = 0;
		mark[CNT] = 0;
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
    int ac_query()
    {
        int i, j;
        int res = 0;
        int now = root;
        int L = strlen(ss);
        for (j = 0; j < L; j++)
        {
            now = next[now][ss[j] - 'a'];
            int temp = now;
            while (temp != -1 && mark[temp] == 0)
            {
                res += sta[temp];
				sta[temp] = 0;
				mark[temp] = 1;
                temp = fail[temp];
            }
        }
        return (res == N ? true : false);
    }
};
Node AC;
//若把MAX直接改为数字，会快50ms
//next数组别忘了改范围，默认26
char ar[100100];
int main()
{
    int i, j, k, u, n, m;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &N);
            AC.init();
            int Max = 0;
            int Maxi;
            for (i = 1; i <= N; i++)
            {
                scanf("%s", AC.s);
                int L = strlen(AC.s);
                if (Max < L)
                {
                    Max = L;
                    Maxi = i;
                    strcpy(ar, AC.s);
                }
                AC.ac_insert();
            }
            AC.ac_buildfail_bfs();
            strcpy(AC.ss, ar);
            if (AC.ac_query())
            {
                printf("%s\n", ar);
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}










#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Trie
{
	int next[maxn][26];
	int sta[maxn];
	int root;
	int CNT;
	char s[100010];
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
		memset(next, -1, sizeof(next));
		memset(sta, 0, sizeof(sta));
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
int N;
char ar[100010];
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext()      //有优化
{
	int i, j, k;
	int L = strlen(former);
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < L && j < L)
	{
		if (j == -1 || former[i] == former[j])
		{
			i++;
			j++;
			//优化
			if (former[i] == former[j])
				Next[i] = Next[j];
			else
				Next[i] = j;
			//如果不要优化，这样：
			//Next[i] = j;
		}
		else
			j = Next[j];
	}
}
int KMP()       //返回目标串在主串中出现的次数
{
	int i, j;
	GETnext();
	int L1 = strlen(former);
	int L2 = strlen(latter);
	i = 0;
	j = 0;
	int res = 0;
	while (i < L2)
	{
		if (j == -1 || latter[i] == former[j])
		{
			if (j == L1 - 1)
			{
				res++;
				j = -1;
			}
			i++;
			j++;
		}
		else
			j = Next[j];
	}
	return res;
}
bool dfs(int now, int dep)
{
	int i, j, k;
	for (i = 0; i < 26; i++)
	{
		if (trie.next[now][i] == -1)
			continue;
		int t = trie.next[now][i];
		former[dep] = 'a' + i;
		if (trie.sta[t] == 1)
		{
			former[dep+1] = '\0';
			if (!KMP())
			{
				return false;
			}
		}
		if (!dfs(t, dep + 1))
			return false;
	}
	return true;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			trie.init();
			int Max = 0;
			int Maxi;
			for (i = 1; i <= N; i++)
			{
				scanf("%s", trie.s);
				int L = strlen(trie.s);
				if (Max < L)
				{
					Max = L;
					Maxi = i;
					strcpy(ar, trie.s);
				}
				trie.insert();
			}
			strcpy(latter, ar);
			if (dfs(0, 0))
			{
				printf("%s\n", ar);
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}










#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
char ar[maxn];
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext(int n)      //有优化
{
	int i, j, k;
	int L = strlen(former);
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < L && j < L)
	{
		if (j == -1 || former[i] == former[j])
		{
			i++;
			j++;
			//优化
			if (former[i] == former[j])
				Next[i] = Next[j];
			else
				Next[i] = j;
			//如果不要优化，这样：
			//Next[i] = j;
		}
		else
			j = Next[j];
	}
}
int KMP(int n)       //返回目标串在主串中出现的次数
{
	int i, j;
	GETnext(n);
	int L1 = strlen(former);
	int L2 = strlen(latter);
	i = 0;
	j = 0;
	int res = 0;
	while (i < L2)
	{
		if (j == -1 || latter[i] == former[j])
		{
			if (j == L1 - 1)
			{
				return true;
			}
			i++;
			j++;
		}
		else
			j = Next[j];
	}
	return false;
}
int N;
int Maxi;
int Max;
int pos[maxn], Len[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			Max = 0;
			int B = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%s", &ar[B]);
				int L = strlen(&ar[B]);
				pos[i] = B;
				Len[i] = L;
				if (Max < L)
				{
					Max = L;
					Maxi = i;
				}
				B += L;
			}
			memcpy(latter, ar + pos[Maxi], Len[Maxi]);
			latter[Len[Maxi]] = '\0';
			bool doudou = true;
			for (i = 1; i <= N; i++)
			{
				if (i == Maxi)
					continue;
				memcpy(former, ar + pos[i], Len[i]);
				former[Len[i]] = '\0';
				if (!KMP(i))
				{
					doudou = false;
					break;
				}
			}
			if (doudou)
			{
				for (i = 0; i < Len[Maxi]; i++)
					printf("%c", ar[i + pos[Maxi]]);
				putchar('\n');
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}
