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
const ll MOD = 1e7 + 7;
const ll maxn = 100000 + 100;
const ll maxm = 1000000 + 100;
struct Node
{
    char s[3];
    int x;
};
Node node[maxn];
int N, M;
int cmp(Node& a, Node& b)
{
    return b.s[0] - a.s[0];
}
int main()
{
    int CAS, cas, i, j, k;
    while(scanf("%d", &CAS) != EOF)
    {
        for(cas = 1; cas <= CAS; cas++)
        {
            scanf("%d %d", &N, &M);
            for(i = 1; i <= N; i++)
            {
                scanf("%s", node[i].s);
                if(node[i].s[0] == 'C')
                    node[i].s[0] = 'B';
                if(node[i].s[0] == 'B')
                    node[i].s[0] = 'C';
                if(node[i].s[0] != 'W')
                {
                    scanf("%d", &node[i].x);
                }
            }
            int doudou = 0;
            int flag = 0;
            ll res = 0;
            for(i = 1; i <= N; i++)
            {
                doudou = 0;
                if(node[i].s[0] == 'W')
                    continue;
                if(i+1 <= N && node[i+1].s[0] == 'W')
                {
                    doudou = 1;
                }
                if(i == 1 && doudou)
                {
                    res++;
                }
                if(doudou)
                {
                    flag = 1;
                    if(i+2 <= N)
                    {
                        if(cmp(node[i], node[i+2]) == 1)
                            res += M-node[i].x + node[i+2].x-1;
                        else if(cmp(node[i], node[i+2]) == 2)
                            res += M-node[i].x + M + node[i+2].x-1;
                        else
                        {
                            res += node[i+2].x - node[i].x - 1;
                        }
                    }
                }
            }
            node[N+1].s[0] = 'D';
            node[N+1].x = M;
            if(node[N].s[0] == 'W')
            {
                if(cmp(node[N-1], node[N+1]) == 1)
                    res += M-node[N-1].x + node[N+1].x-1;
                else if(cmp(node[N-1], node[N+1]) == 2)
                    res += M-node[N-1].x + M + node[N+1].x-1;
                else
                {
                    res += node[N+1].x - node[N-1].x - 1;
                }
            }
            node[0].s[0] = 'B';
            node[0].x = 1;
            if(!flag)
            {
                if(node[1].s[0] == 'B' && node[1].x == 1)
                {
                    res++;
                }
                else
                {
                    if(cmp(node[0], node[1]) == 1)
                        res += M-node[0].x + node[1].x-1;
                    else if(cmp(node[0], node[1]) == 2)
                        res += M-node[0].x + M + node[1].x-1;
                    else
                    {
                        res += node[1].x - node[0].x - 1;
                    }
                }
                for(i = 1; i < N; i++)
                {
                    if(cmp(node[i], node[i+1]) == 1)
                        res += M-node[i].x + node[i+1].x-1;
                    else if(cmp(node[i], node[i+1]) == 2)
                        res += M-node[i].x + M + node[i+1].x-1;
                    else
                    {
                        res += node[i+1].x - node[i].x - 1;
                    }
                }
                if(cmp(node[N], node[N+1]) == 1)
                    res += M-node[N].x + node[N+1].x-1;
                else if(cmp(node[N], node[N+1]) == 2)
                    res += M-node[N].x + M + node[N+1].x-1;
                else
                {
                    res += node[N+1].x - node[N].x - 1;
                }
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}