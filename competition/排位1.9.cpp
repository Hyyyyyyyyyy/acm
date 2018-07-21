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
const int maxn = 10 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	int t;
	double p;
	double c;
	int id;
};
Node ar[maxn];
bool comp(Node a, Node b)
{
	double x1 = a.p*(double)a.t + (1.0 - a.p) * ((double)a.t + (double)b.t);
	double x2 = b.p*(double)b.t + (1.0 - b.p) * ((double)a.t + (double)b.t);
	if (fabs(x1 - x2) > eps)
		return x1 < x2;
	return a.id < b.id;
}
int main()
{
	int i, j, k, N, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i].t);
				ar[i].id = i;
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%lf", &ar[i].p);
			}
			sort(ar + 1, ar + 1 + N, comp);
			for (i = 1; i <= N; i++)
			{
				if (i != 1)
					printf(" ");
				printf("%d", ar[i].id);
			}
			printf("\n");
		}
	}
	return 0;
}
//考虑两个的时候如何排序，只需比较 p1*t1 + (1-p1)*(t1+t2) 和 p2*t2 + (1-p2)*(t1+t2) 即可，那么就按这个排序
//很多贪心都是这样做的