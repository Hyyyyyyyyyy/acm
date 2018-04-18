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
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int A[maxn];
int B[maxn];
int N;
set<int> S;
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
			scanf("%d", &A[i]);
		for (i = 1; i <= N; i++)
			scanf("%d", &B[i]);
		ll res = 0;
        ll sum = 0;
        S.clear();
        ll ans = INF;
        for(i = 1; i <= N; i++)
        {
            int t;
            res += B[i];
            sum += A[i];
            S.insert(A[i]);
            if(res <= sum)
            {
                while(res <= sum)
                {
                    t = *S.begin();
                    S.erase(t);
                    sum -= t;
                }
                S.insert(t);
                if(ans > S.size())
                    ans = S.size();
            }
        }
		if (ans != INF)
		{
			printf("%d\n", ans);
		}
		else
			printf("Game Over!\n");
	}
	return 0;
}