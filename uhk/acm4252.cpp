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
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
stack<int>S;
int main()
{
	int i, j, k, N, cas = 1;
	while (scanf("%d", &N) != EOF)
	{
		int res = 0;
		while (!S.empty())
			S.pop();
        for(i = 1; i <= N; i++)
            scanf("%d", &ar[i]);
		for (i = 1; i <= N; i++)
		{
            if(S.empty())
            {
                S.push(ar[i]);
                continue;
            }
            if(!S.empty() && ar[i] > S.top())
            {
                S.push(ar[i]);
                continue;
            }
            if(ar[i] < S.top())
            {
                while(!S.empty() && ar[i] < S.top())
                {
                    res++;
                    S.pop();
                }
                S.push(ar[i]);
            }
            if(ar[i] == S.top())
            {
                while(!S.empty() && ar[i] == S.top())
                    S.pop();
                S.push(ar[i]);
                continue;
            }
        }
        while(!S.empty())
        {
            if(S.top())
                res++;
            S.pop();
        }
		printf("Case %d: %d\n", cas++, res);
    }
	return 0;
}
