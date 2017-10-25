#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef unsigned long long ll;
const double eps = 1e-8;
const int INF = 1e9+1;
const int maxn = 50 + 100;
int main()
{
    ll i, j, k, u, n, m, N, M;
    while(scanf("%llu %llu", &N, &M) != EOF)
    {
        printf("%llu\n", (M - N + 1) * M);
    }
    return 0;
}