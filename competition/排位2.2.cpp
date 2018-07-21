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
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	int time;
	int val;
};
Node ar[10];
int N, M;
bool comp1(Node a, Node b)
{
	return a.time < b.time;
}
bool comp2(Node a, Node b)
{
	return a.val > b.val;
}
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i].time);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i].val);
			}
			int T = M;
			sort(ar + 1, ar + 1 + N, comp1);
			i = 1;
			int res1 = 0;
			while (M - ar[i].time >= 0)
			{
				res1 += ar[i].val;
				M -= ar[i].time;
				i++;
			}
			int res2 = 0;
			sort(ar + 1, ar + 1 + N, comp2);
			i = 1;
			M = T;
			while (M - ar[i].time >= 0)
			{
				res2 += ar[i].val;
				M -= ar[i].time;
				i++;
			}
			if (res1 > res2)
			{
				printf("A\n");
			}
			else if (res1 < res2)
			{
				printf("B\n");
			}
			else
				printf("SAME\n");
		}
	}
	return 0;
}