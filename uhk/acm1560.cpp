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
const int maxn = 10;
const int maxm = 1000000 + 100;
char dir[4] = {'A', 'C', 'G', 'T'};
struct Node
{
    int L;
    char s[maxn];
};
Node node[maxn];
int N, res;
int suc[maxn];
int getH()
{
    int i, j;
    int cnt = 0;
    for(i = 1; i <= N; i++)
    {
        cnt = max(cnt, node[i].L - suc[i]);
    }
    return cnt;
}
int Select(int val)
{
    int i, j;
    int cnt = 0;
    for(i = 1; i <= N; i++)
    {
        if(node[i].s[suc[i]] == dir[val])
            cnt++;
    }
    return cnt;
}
bool IDA_dfs(int dep)
{
    if(dep + getH() > res)
        return false;
    if(dep == res)
    {
        if(getH() == 0)
            return true;
        return false;
    }
    int i, j;
    int temp_suc[10];
    memcpy(temp_suc, suc, sizeof(temp_suc));
    for(i = 0; i < 4; i++)
    {
        if(Select(i) == 0)
            continue;
        if(IDA_dfs(dep+1))
            return true;
        memcpy(suc, temp_suc, sizeof(suc));
    }
    return false;
}
int main()
{
    int i, j, k, CAS, cas;
    while(scanf("%d", &CAS) != EOF)
    {
        for(cas = 1; cas <= CAS; cas++)
        {
            scanf("%d", &N);
            for(i = 1; i <= N; i++)
                scanf("%s", node[i].s), node[i].L = strlen(node[i].s);
            memset(suc, 0, sizeof(suc));
            for(res = getH(); ; res++)
            {
                if(IDA_dfs(0))
                    break;
            }
            printf("%d\n", res);
        }
    }
}