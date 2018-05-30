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
struct Node
{
	int L;
	int W;
};
Node A[maxn], B[maxn];
bool comp(Node& a, Node& b)
{
	return a.L < b.L;
}
multiset<int> S;
multiset<int>::iterator it;
int main()
{
	int i, j, k, cas, CAS, a, b, N;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			S.clear();
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &A[i].L, &A[i].W);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &B[i].L, &B[i].W);
			}
			sort(A + 1, A + 1 + N, comp);
			sort(B + 1, B + 1 + N, comp);
			int res = 0;
			j = 1;
			for (i = 1; i <= N; i++)
			{
				while (j <= N && B[j].L <= A[i].L)
				{
					S.insert(B[j].W);
					j++;
				}
				it = S.upper_bound(A[i].W);
				if (S.size() <= 0 || it == S.begin())
					continue;
				it--;
				if (A[i].W >= (*it))
				{
					res++;
					S.erase(it);
				}
				
			}
			printf("%d\n", res);
		}
	}
	return 0;
}