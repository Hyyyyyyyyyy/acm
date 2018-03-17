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
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const ll maxn = 1000 + 100;
const ll maxm = 1000000 + 100;
ll Len[maxn];
int main()
{
    int i, j, k, n1, n2, n3, n4, cas = 1;
    while(scanf("%d %d %d %d", &Len[1], &Len[2], &Len[3], &Len[4]) != EOF)
    {
        sort(Len+1, Len+5);
        int res = Len[3] + Len[4];
        printf("Case %d: %d\n",cas++, res);
    }
    return 0;
}