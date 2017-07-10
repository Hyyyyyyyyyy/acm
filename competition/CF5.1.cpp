#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    long long n, m, a, b, i, j;
    while(scanf("%I64d %I64d", &n, &m) != EOF)
    {
        long long t = n / 2;
        a = t / (m+1);
        b = t/(m+1)*m;
        printf("%I64d %I64d %I64d\n", a, b, n - a - b);
    }
    return 0;
}