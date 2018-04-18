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
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	int v;
	int next;
};
Node node[maxn];
int top[maxn];
int bot[maxn];
int tot;
void Push(int s, int v)
{
	node[tot].v = v;
	node[tot].next = top[s];
	if(bot[s] == -1)
		bot[s] = tot;
	top[s] = tot++;
}
int Pop(int s)
{
	if(bot[s] == -1)
		return -1;
	int res = node[top[s]].v;
	top[s] = node[top[s]].next;
	if(top[s] == -1)
		bot[s] = -1;
	return res;
}
void Move(int s, int t)
{
	if(bot[t] == -1)
		return;
	node[bot[t]].next = top[s];
	if(bot[s] == -1)
		bot[s] = bot[t];
	top[s] = top[t];
	top[t] = bot[t] = -1;
}
int main()
{
	int i, j, k, cas, CAS, N, Q, q, op, a,b, c;
	while(scanf("%d", &CAS) != EOF)
	{
		for(cas = CAS; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &Q);
			tot = 0;
			memset(top, -1, sizeof(top));
			memset(bot, -1, sizeof(bot));
			for(q = 1; q <= Q; q++)
			{
				scanf("%d", &op);
				if(op == 1)
				{
					scanf("%d %d", &a, &b);
					Push(a, b);
				}
				else if(op == 2)
				{
					scanf("%d", &a);
					int res = Pop(a);
					if(res != -1)
						printf("%d\n", res);
					else
						printf("EMPTY\n");
				}
				else
				{
					scanf("%d %d", &a, &b);
					Move(a, b);
				}
			}
		}
	}
	return 0;
}