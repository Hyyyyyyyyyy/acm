#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const int maxn = 50000 + 100;
int A[maxn], B[maxn];
int main()
{
    int i, j, k, u, n, m, N, M, Q, K;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &N, &M, &Q);
            for(i = 1; i <= N; i++)
            {
                scanf("%d", &A[i]);
            }
            for(i = 1; i <= M; i++)
            {
                scanf("%d", &B[i]);
            }
        }
    }
    return 0;
}