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
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 400000 + 100;
const int maxm = 5000000 + 100;
int main()
{
    int i, j, K;
    double R, r, x;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%lf", &R);
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &K);
            if(K == 1)
            {
                printf("%d .0f\n", K, 2.0*R / sqrt(3.0) - R);
            }
            else
            {
                r = 2.0*R / sqrt(3.0) - R;
                x = 0;
                for(i = 2; i <= K; i++)
                {
                    x = (sqrt((R+r)*(R+r) - R*R) - r)*(sqrt((R+r)*(R+r) - R*R) - r) / (2.0 * (sqrt((R+r)*(R+r) - R*R) - r + R));
                    r = x;
                }
                printf("%d %.0f\n", K, x);
            }
        }
    }
    return 0;
}