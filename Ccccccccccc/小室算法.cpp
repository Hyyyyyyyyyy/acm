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
const ll MOD = 1e18;
const int maxn = 2000000 + 100;
const int M = 1000000 + 10;
int res[maxn];
int top;
struct Node
{
	int id;
	int val;
	Node(int a, int b) : id(a), val(b) {}
	bool operator < (const Node &p)
	{
		return id > p.id;
	}
};
vector<Node>G[maxn];
int MAX;
void dfs(int n, int pos)
{
	if (top > M)
		return;
	res[top++] = n;
	int i, j;
	for (i = 0; i < G[n].size(); i++)
	{
		if (G[n][i].id < pos)
			break;
		dfs(G[n][i].val, G[n][i].id);
	}
}
int main()
{
	int i, j, k, u, n, m, N, L, R, a, b;
	scanf("%d %d %d", &N, &L, &R);
	{
		MAX = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &a, &b);
			if (MAX < b)
				MAX = b;
			G[a].push_back(Node(i, b));
		}
		for (i = 0; i <= MAX; i++)
		{
			if (G[i].size())
				sort(G[i].begin(), G[i].end());
		}
		top = 0;
		int count;
		dfs(0, 0);
		//for (i = 0; i < top; i++)
		//	printf("%d ", res[i]);
		for (i = L % top, count = 1; count <= R - L; count++)
		{
			if (i == top)
			{
				i = 0;
			}
			if (count == 1)
				printf("%d", res[i]);
			else
				printf(" %d", res[i]);
			i++;
		}
		putchar('\n');
	}
	return 0;
}