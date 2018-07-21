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
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
priority_queue<int>Q;
int main()
{
	int i, j, k, cas, CAS, N;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			while (!Q.empty())
				Q.pop();
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				Q.push(ar[i]);
			}
			int after;
			int now = Q.top();
			Q.pop();
			while (!Q.empty())
			{
				after = Q.top();
				Q.pop();
				if (now > after)
				{
					Q.push(now - after);
					now = after;
				}
			}
			printf("%d\n", now*N);
		}
	}
	return 0;
}

//给出一串数，让所有大数变成大数减小数的差，最后稳定时所有数相等，为所有数的最大公约数
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
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
int gcd(int x, int y)
{
	return (y == 0) ? x : gcd(y, x%y);
}
int main()
{
	int i, j, k, cas, CAS, N;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d", &N);
			int res;
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				if (i == 1)
					res = ar[1];
				else
					res = gcd(res, ar[i]);
			}
			
			printf("%d\n", res*N);
		}
	}
	return 0;
}