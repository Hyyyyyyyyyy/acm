#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int MAX = 100000000;
struct node
{
	int id;
	int loty;
	int abty;
	bool operator < (const node &p) const
	{
		return abty > p.abty;
	}
};
node edge[50000 * 4];
int Max[50000 * 4], Id[50000 * 4];
int res[50000 * 4], L[50000 * 4], R[50000 * 4], tot;
map<int, int>q;
vector<int>G[50000 * 4];
void update(int root, int begin, int end, int index, int id, int val);
int query(int root, int begin, int end, int b, int e);
void pushup(int root);
void dfs(int n);
int main()
{
	int i, j, k, u, n, m, a, b, c, N, M;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			q.clear();
			scanf("%d %d", &N, &M);
			for (i = 0; i <= N; i++)
				G[i].clear();

			for (u = 1; u < N; u++)
			{
				scanf("%d %d %d", &a, &edge[u].loty, &edge[u].abty);
				G[a].push_back(u);
				edge[u].id = u;
				q[edge[u].loty] = u;
			}
			sort(edge + 1, edge + N);
			tot = 0;
			dfs(0);
			memset(Max, -1, sizeof(Max));
			memset(res, -1, sizeof(res));
			memset(Id, -1, sizeof(Id));
			for (int i = 1, j; i<N; i = j) 
			{
				j = i;
				while (j<N && edge[j].abty == edge[i].abty)
				{
					int id = edge[j].id;
					int lo = query(1, 0, tot-1, L[id] + 1, R[id] - 1);
					res[id] = lo == -1 ? -1 : q[lo];
					j++;
				}
				j = i;
				while (j<N && edge[j].abty == edge[i].abty)
				{
					int id = edge[j].id;
					update(1, 0, tot-1, L[id], id, edge[j].loty);
					j++;
				}
			}
			for (u = 1; u <= M; u++)
			{
				scanf("%d", &a);
				printf("%d\n", res[a]);
			}
		}
	}
	return 0;
}
void dfs(int n)
{
	L[n] = tot++;
	for (int i = 0; i < G[n].size(); i++)
	{
		dfs(G[n][i]);
	}
	R[n] = tot;
}
int query(int root, int begin, int end, int b, int e)
{
	if (b > e)
		return -1;
	if (begin >= b && end <= e)
		return Max[root];
	int mid = (begin + end) / 2;
	int ans = -1;
	if (b <= mid)
		ans = max(ans, query(root * 2, begin, mid, b, e));
	if (e > mid)
		ans = max(ans, query(root * 2 + 1, mid + 1, end, b, e));
	return ans;
}
void update(int root, int begin, int end, int index, int id, int val)
{
	if (begin == end)
	{
		Id[root] = id;
		Max[root] = val;
	}
	else
	{
		int mid = (begin + end) / 2;
		if (index <= mid)
		{
			update(root * 2, begin, mid, index, id, val);
		}
		else
			update(root * 2 + 1, mid + 1, end, index, id, val);
		pushup(root);
	}
}
void pushup(int root)
{
	if (Max[root * 2] > Max[root * 2 + 1])
	{
		Max[root] = Max[root * 2];
		Id[root] = Id[root * 2];
	}
	else
	{
		Max[root] = Max[root * 2 + 1];
		Id[root] = Id[root * 2 + 1];
	}
}