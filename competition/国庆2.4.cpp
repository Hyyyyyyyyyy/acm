#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 10000+100;
vector<Node>G[maxn];
struct Node
{
    ll x;
    ll y;
    ll id;
};
Node ar[maxn];
int main()
{
    ll i, j, k, n, m, a, b;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld", &N);
            for(i = 1; i <= N; i++)
            {
                G[i].clear();
            }
            for(i = 1; i <= N; i++)
            {
                scanf("%lld %lld", &ar[i].x, &ar[i].y);
                ar[i].id = i;
                if()
            }
        }
    }
}