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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int N;
struct Node
{
	int w;
	int s;
};
Node node[maxn];
bool comp(Node& a, Node& b)
{
	return (a.w + a.s) < (b.w + b.s);
}
int main()
{
	int i, j, k, a, b;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &node[i].w, &node[i].s);
		}
		sort(node + 1, node + 1 + N, comp);
		ll sum = 0;
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			res = max(res, sum - node[i].s);
			sum += node[i].w;
		}
		printf("%lld\n", res);
	}
	return 0;
}
//4296      贪心排序
/*题解：对于相邻放置的两块板，设两块板为i,j他们上面的重量为sum

           1) a=sum-si;b=sum+wi-sj;

           交换两个板的位置

          2)a'=sum+wj-si;b'=sum-sj;

          如果1优于2,求解得有效的条件为wj-si>wi-sj。

          所以按si+wi的和排序贪心即可。*/