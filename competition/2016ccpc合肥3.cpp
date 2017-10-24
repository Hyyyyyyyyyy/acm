#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 2020;
int N, M;
char s[maxn][maxn];
int IN[maxn];
vector<int>G[maxn];
queue<int>Q;
int main()
{
	int i, j, k, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(IN, 0, sizeof(IN));
			scanf("%d", &N);
			for (i = 0; i <= N; i++)
				G[i].clear();
			while (!Q.empty())
				Q.pop();
			for (i = 1; i <= N; i++)
			{
				scanf("%s", s[i] + 1);
				for (j = 1; j <= N; j++)
				{
					if (s[i][j] == 'P')
					{
						G[i].push_back(j);
						IN[j]++;
					}
					if (s[i][j] == 'Q')
					{
						G[i].push_back(j);
						IN[j]++;
					}
				}
			}
			int sum = N;
			for (i = 1; i <= N; i++)
			{
				if (!IN[i])
				{
					Q.push(i);
					sum--;
				}
			}
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop();
				for (i = 0; i < G[u].size(); i++)
				{
					IN[G[u][i]]--;
					if (IN[G[u][i]] == 0)
					{
						sum--;
						Q.push(G[u][i]);
					}
				}
			}
			
			if (sum == 0)
			{
				sum = N;
				memset(IN, 0, sizeof(IN));
				for (i = 0; i <= N; i++)
					G[i].clear();
				while (!Q.empty())
					Q.pop();
				for (i = 1; i <= N; i++)
				{
					for (j = 1; j <= N; j++)
					{
						if (s[i][j] == 'P')
						{
							G[i].push_back(j);
							IN[j]++;
						}
						if (s[i][j] == 'Q')
						{
							G[j].push_back(i);
							IN[i]++;
						}
					}
				}
				for (i = 1; i <= N; i++)
				{
					if (!IN[i])
					{
						Q.push(i);
						sum--;
					}
				}
				while (!Q.empty())
				{
					int u = Q.front();
					Q.pop();
					for (i = 0; i < G[u].size(); i++)
					{
						IN[G[u][i]]--;
						if (IN[G[u][i]] == 0)
						{
							sum--;
							Q.push(G[u][i]);
						}
					}
				}
				if (sum == 0)
				{
					printf("T\n");
				}
				else
				{
					printf("N\n");
				}
			}
			else
				printf("N\n");
		}
	}
	return 0;
}