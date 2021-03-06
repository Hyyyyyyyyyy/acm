#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int INF = 2147483640;
const int maxn = 20010;
const int maxm = 200100;
struct ISAP
{
	struct Edge
	{
		int to;
		int next;
		int cap;
		int flow;
	};
	Edge edge[maxm];
	int tol;
	int head[maxn];
	int gap[maxn];
	int dep[maxn];
	int cur[maxn];
	int S[maxn];
	int start;
	int end;
	int N;
	int M;
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v, int w, int rw = 0)
	{
		edge[tol].to = v;
		edge[tol].cap = w;
		edge[tol].flow = 0;
		edge[tol].next = head[u];
		head[u] = tol++;
		edge[tol].to = u;
		edge[tol].cap = rw;
		edge[tol].flow = 0;
		edge[tol].next = head[v];
		head[v] = tol++;
	}
	void bfs()
	{
		int i, j;
		queue<int>q;
		memset(dep, -1, sizeof(dep));
		memset(gap, 0, sizeof(gap));
		gap[0] = 1;
		dep[end] = 0;
		q.push(end);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (i = head[u]; i != -1; i = edge[i].next)
			{
				int v = edge[i].to;
				if (dep[v] != -1)
					continue;
				dep[v] = dep[u] + 1;
				gap[dep[v]]++;
				q.push(v);
			}
		}
	}
	int max_flow()
	{
		int i, j;
		bfs();
		memcpy(cur, head, sizeof(head));
		int top = 0;
		int u = start;
		int ans = 0;
		while (dep[start] < N)
		{
			if (u == end)
			{
				int Min = INF;
				int inser;
				for (i = 0; i < top; i++)
				{
					if (Min > edge[S[i]].cap - edge[S[i]].flow)
					{
						Min = edge[S[i]].cap - edge[S[i]].flow;
						inser = i;
					}
				}
				for (i = 0; i < top; i++)
				{
					edge[S[i]].flow += Min;
					edge[S[i] ^ 1].flow -= Min;
				}
				ans += Min;
				top = inser;
				u = edge[S[top] ^ 1].to;
				continue;
			}
			bool flag = false;
			int v;
			for (i = cur[u]; i != -1; i = edge[i].next)
			{
				v = edge[i].to;
				if (edge[i].cap - edge[i].flow && dep[v] == dep[u] - 1)
				{
					flag = true;
					cur[u] = i;
					break;
				}
			}
			if (flag)
			{
				S[top++] = cur[u];
				u = v;
				continue;
			}
			int Min = N;
			for (i = head[u]; i != -1; i = edge[i].next)
			{
				if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
				{
					Min = dep[edge[i].to];
					cur[u] = i;
				}
			}
			gap[dep[u]]--;
			if (!gap[dep[u]])
				return ans;
			dep[u] = Min + 1;
			gap[dep[u]]++;
			if (u != start)
				u = edge[S[--top] ^ 1].to;
		}
		return ans;
	}
};
ISAP isap;
//注意要给 isap.start  isap.end  isap.N(包括源点和汇点) 赋值！和 初始化isap.init()
//双向边直接addedge两次就行了
//maxm是边数的2倍！   数组开小了会TLE
char s[110][110][110];  //输入
int num[21000];         //记录白格数，减下界时用到
int lx[110][110];       //行号
int ly[110][110];       //列号
int id[110][110];       //每个格子的标号
int N, M;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%s", s[i][j]);
			}
		}
		isap.init();
		int tt = 0;
		memset(num, 0, sizeof(num));
		memset(lx, 0, sizeof(lx));
		memset(ly, 0, sizeof(ly));
		memset(id, 0, sizeof(id));
		//标号
		for (i = 0; i < N; i++)      //给有白色的行标号
		{
			for (j = 0; j < M; j++)
			{
				if (strcmp(s[i][j], ".......") != 0)
					continue;
				if (j == 0 || lx[i][j - 1] == 0)   //每行最左列为新的号
					lx[i][j] = ++tt;
				else
					lx[i][j] = lx[i][j - 1];
				num[lx[i][j]]++;                //记录改行有多少的白格，之后减下界时要用（此题是++，因为下界是1）
			}
		}
		for (j = 0; j < M; j++)      //给有白色的列标号
		{
			for (i = 0; i < N; i++)
			{
				if (strcmp(s[i][j], ".......") != 0)
					continue;
				if (i == 0 || ly[i - 1][j] == 0)       //每列最上为新的号
					ly[i][j] = ++tt;
				else
					ly[i][j] = ly[i - 1][j];
				num[ly[i][j]]++;
			}
		}
		isap.start = 0;
		isap.end = tt + 1;
		isap.N = tt + 2;
		//行列加边
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (strcmp(s[i][j], ".......") == 0)
				{
					isap.addedge(lx[i][j], ly[i][j], 8);
					id[i][j] = isap.tol - 2;              //记录该点的号
				}
			}
		}
		//起点，终点加边
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (s[i][j][3] != '\\')
					continue;
				if (s[i][j][0] != 'X')
				{
					int tmp = (s[i][j][0] - '0') * 100 + (s[i][j][1] - '0') * 10 + s[i][j][2] - '0';
					if (ly[i + 1][j] != 0)
						isap.addedge(ly[i + 1][j], isap.end, tmp - num[ly[i + 1][j]]);
				}
				if (s[i][j][4] != 'X')
				{
					int tmp = (s[i][j][4] - '0') * 100 + (s[i][j][5] - '0') * 10 + s[i][j][6] - '0';
					if (lx[i][j + 1] != 0)
						isap.addedge(isap.start, lx[i][j + 1], tmp - num[lx[i][j + 1]]);
				}
			}
		}
		isap.max_flow();
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (j > 0)
				{
					printf(" ");
				}
				if (strcmp(s[i][j], ".......") != 0)
				{
					printf("_");
				}
				else
				{
					printf("%c", '0' + isap.edge[id[i][j]].flow + 1);
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
