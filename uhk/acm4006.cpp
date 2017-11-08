#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e10;
const ll INF = 1e18;
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 500000 + 100;
struct comp
{
    bool operator () (const int a, const int b) const
    {
        return a > b;
    }
};
priority_queue<int, vector<int>, comp > Q;
char s[10];
int main()
{
    int i, j, k, N, K, a, b;
    while (scanf("%d %d", &N, &K) != EOF)
    {
        while (!Q.empty())
            Q.pop();
        for (i = 1; i <= N; i++)
        {
            scanf("%s", s);
            if (s[0] == 'I')
            {
                scanf("%d", &a);
                Q.push(a);
                if (Q.size() > K)
                    Q.pop();
            }
            if (s[0] == 'Q')
            {
                printf("%d\n", Q.top());
            }
        }
    }
    return 0;
}