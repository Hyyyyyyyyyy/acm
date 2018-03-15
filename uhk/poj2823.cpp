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
int res1[maxn];
int res2[maxn];
int main()
{
	int i, j, k, N, K;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		while (!Q1.empty())  Q1.pop_front();
		while (!Q2.empty())  Q2.pop_front();
		int now = 1;
		int top = 1;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			while (!Q1.empty() && ar[Q1.back()] < ar[i])
				Q1.pop_back();
			Q1.push_back(i);
			while (!Q2.empty() && ar[Q2.back()] > ar[i])
				Q2.pop_back();
			Q2.push_back(i);
			while (i - Q1.front() + 1 > K)
			{
				Q1.pop_front();
			}
			while (i - Q2.front() + 1 > K)
			{
				Q2.pop_front();
			}
			if (i >= K)
			{
				res1[top] = ar[Q1.front()];
				res2[top++] = ar[Q2.front()];
			}
		}
		for (i = 1; i < top; i++)
		{
			if (i > 1)
				printf(" ");
			printf("%d", res2[i]);
		}
		putchar('\n');
		for (i = 1; i < top; i++)
		{
			if (i > 1)
				printf(" ");
			printf("%d", res1[i]);
		}
		putchar('\n');
	}
	return 0;
}