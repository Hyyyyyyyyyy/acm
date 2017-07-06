#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 220;
const double eps = 1.0e-9;
int zushu, var;
double a[maxn][maxn], x[maxn];
int Gauss()
{
    int i, j, k, u, col, max_r;
    for (k = 1, col = 1; k <= zushu && col <= var; k++, col++)
    {
        max_r = k;
        for (i = k + 1; i <= zushu; i++)
        {
            if (fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        }
        if (fabs(a[max_r][col]) < eps)
            return 0;
        if (k != max_r)
        {
            for (j = col; j <= var; j++)
                swap(a[k][j], a[max_r][j]);
            swap(x[k], x[max_r]);
        }
        x[k] /= a[k][col];
        for (j = col + 1; j <= var; j++)
            a[k][j] /= a[k][col];
        a[k][col] = 1;
        for (i = 1; i <= zushu; i++)
        {
            if (i != k)
            {
                x[i] -= x[k] * a[i][col];
                for (j = col + 1; j <= var; j++)
                    a[i][j] -= a[k][j] * a[i][col];
                a[i][col] = 0;
            }
        }
    }
    return 1;
}