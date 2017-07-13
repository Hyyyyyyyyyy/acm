#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1010;
const int M = 35;
typedef long long LL;
int dp[N][N][M], sa[N][N];
char ar[N][N];
int n, m, q;
int main()
{
    while (scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        int d = sqrt(double(n));
        for (int i = 1; i<= n; ++i)
            scanf("%s", ar[i]+1);
        for (int i = 1; i<= n; ++i)
        {
            for (int j = 1; j<= m; ++j)
            {
                sa[i][j] = sa[i][j-1] + (ar[i][j]=='X');
            }
        }
        int* p;
        int kk;
        for (int i = 1; i<= n; ++i)
        {
            for (int j = 1; j<= m; ++j)
            {
                for (int k = 1; k<= d; ++k)
                {
                    kk = k * 2;
                    p = &dp[i][j][k];
                    *p = (ar[i][j]=='X');
                    if (i > k)
                    {
                        if (j>k)
                        {
                            *p += dp[i-k][j-k][k] + sa[i-k][j] - sa[i-k][j-k];
                        }
                        else
                        {
                            *p += sa[i-k][j];
                            if (i > kk) *p += dp[i-kk][j][k] + sa[i-kk][j-1];
                        }
                        if (j+k <= m)
                        {
                            *p += dp[i-k][j+k][k] + sa[i-k][j+k-1] - sa[i-k][j];
                        }
                        else
                        {
                            *p += sa[i-k][m] - sa[i-k][j];
                            if (i > kk) *p += dp[i-kk][j][k] + sa[i-kk][m] - sa[i-kk][j];
                        }
                        if (i > kk) *p -= dp[i-kk][j][k];
                    }
                }
            }
        }
        for (int i = 0; i< q; ++i)
        {
            int r, c, w, res;
            scanf("%d%d%d", &r, &c, &w);
            if (w > d)
            {
                res = 0;
                for (int j = r, lf=c, rt=c; j >0; j-=w, lf=max(lf-w,1), rt=min(m,rt+w))
                    res +=  sa[j][rt]-sa[j][lf-1];
                printf("%d\n", res);
            }
            else
                printf("%d\n", dp[r][c][w]);
        }
    }
    return 0;
}
