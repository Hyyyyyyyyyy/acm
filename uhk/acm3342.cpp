#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000000;
const int MAXN = 110;
vector<int>G[500];
int in[MAXN];
int N, M, Sum;
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF && (N || M))
	{
		memset(in, 0, sizeof(in));
		Sum = N;
		for (i = 0; i < 500; i++)
			G[i].clear();
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			in[b]++;
		}
		queue<int>q;
		for (i = 0; i < N; i++)
		{
			if (in[i] == 0)
			{
				q.push(i);
				Sum--;
			}
		}
		while (!q.empty())
		{
			u = q.front();
			q.pop();
			for (i = 0; i < G[u].size(); i++)
			{
				in[G[u][i]]--;
				if (in[G[u][i]] == 0)
				{
					Sum--;
					q.push(G[u][i]);
				}
			}
		}
		if (Sum == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
