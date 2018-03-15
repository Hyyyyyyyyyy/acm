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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
deque<int> Q1;  //最大值
deque<int> Q2;  //最小值
int ar[maxn];
int main()
{
	int i, j, k, N, M, K;
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		while (!Q1.empty())  Q1.pop_front();
		while (!Q2.empty())  Q2.pop_front();
		int now = 1;
		int res = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			while (!Q1.empty() && ar[Q1.back()] < ar[i])
				Q1.pop_back();
			Q1.push_back(i);
			while (!Q2.empty() && ar[Q2.back()] > ar[i])
				Q2.pop_back();
			Q2.push_back(i);
			while (!Q1.empty() && !Q2.empty() && ar[Q1.front()] - ar[Q2.front()] > K)
			{
				if (Q1.front() > Q2.front())
				{
					now = Q2.front() + 1;
					Q2.pop_front();
				}
				else
				{
					now = Q1.front() + 1;
					Q1.pop_front();
				}
			}
			if (!Q1.empty() && !Q2.empty() && ar[Q1.front()] - ar[Q2.front()] >= M)
			{
				if (res < i - now + 1)
					res = i - now + 1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}