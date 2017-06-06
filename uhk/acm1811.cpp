#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
const int MAXN = 10010;
vector<int>ar[MAXN * 3];
int in[MAXN], set[MAXN];
int l[MAXN], r[MAXN];
char ss[MAXN];
int N, M;
int find(int n);
int main()
{
	int i, j, k, u, a, b, c, n, m, p, e, sum, flag, doudou, t;
	char s[5];
	while (scanf("%d %d", &N, &M) != EOF)
	{
		sum = N;
		flag = 0;
		doudou = 0;
		memset(in, 0, sizeof(in));
		for (i = 0; i < N; i++)
		{
			set[i] = i; 
			ar[i].clear();
		}
		for (m = 0; m < M; m++)
		{
			scanf("%d %s %d", &a, s, &b);
			l[m] = a;
			r[m] = b;
			ss[m] = s[0];
			if (strcmp(s, "=") == 0)
			{
				a = find(a);
				b = find(b);
				if (a != b)
				{
					set[b] = a;
					sum--;
				}
			}
		}
		for (i = 0; i < M; i++)
		{
			if (ss[i] == '=')
				continue;
			else if (ss[i] == '<')
			{
				l[i] = find(l[i]);
				r[i] = find(r[i]);
				if (l[i] == r[i])
					flag = 1;
				ar[r[i]].push_back(l[i]);
				in[l[i]]++;
			}
			else if (ss[i] == '>')
			{
				l[i] = find(l[i]);
				r[i] = find(r[i]);
				if (l[i] == r[i])
					flag = 1;
				ar[l[i]].push_back(r[i]);
				in[r[i]]++;
			}
		}
		if (flag)
		{
			printf("CONFLICT\n");
		}
		else
		{
			queue<int>q;
			for (i = 0; i < N; i++)
			{
				t = find(i);
				if (in[i] == 0 && t == i)
				{
					q.push(i);
					sum--;
				}
			}
			while (!q.empty())
			{
				if (q.size() > 1)
					doudou = 1;
				u = q.front();
				q.pop();
				for (i = 0; i < ar[u].size(); i++)
				{
					in[ar[u][i]]--;
					if (in[ar[u][i]] == 0)
					{
						q.push(ar[u][i]);
						sum--;
					}
				}
			}	
			if (sum > 0)
				printf("CONFLICT\n");
			else if (doudou == 1)
				printf("UNCERTAIN\n");
			else
				printf("OK\n");
		}
	}
	return 0;
}
int find(int n)
{
	if (set[n] != n)
		set[n] = find(set[n]);
	return set[n];
}
