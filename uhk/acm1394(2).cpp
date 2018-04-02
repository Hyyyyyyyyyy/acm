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
	int num;
	int id;
};
Node ar[maxn];
int Bit[maxn];
void Add(int x, int val)
{
	for (int i = x; i <= N; i += (i & -i))
		Bit[i] += val;
}
int Sum(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= (i & -i))
	{
		res += Bit[i];
	}
	return res;
}
bool comp(const Node& a, const Node& b)
{
	return a.num > b.num;
}
bool comp2(const Node& a, const Node& b)
{
	return a.id < b.id;
}
int main()
{
	int i, j, k, n;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i].num);
			ar[i].id = i;
		}
		sort(ar + 1, ar + 1 + N, comp);
		memset(Bit, 0, sizeof(Bit));
		int num = 0;
		foR(i = 1; i <= N; i++)
		{
			Add(ar[i].id, 1);
			num += Sum(ar[i].id-1);
			//printf("%d\n", res[ar[i].id]);
		}
		//printf("%d\n", res[0]);
		sort(ar + 1, ar + 1 + N, comp2);
		int ans = num;
		for (i = 1; i <= N; i++)
		{
			num = num + (N - ar[i].num - 1) - ar[i].num;
			//printf("%d\n", res[0]);
			ans = min(ans, num);
		}
		printf("%d\n", ans);
	}
	return 0;
}
