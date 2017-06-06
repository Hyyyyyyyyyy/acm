#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000000;
struct point
{
    int a;
    int b;
    double c;
};
bool comp(const point &a, const point &b)
{
    return a.c > b.c;
}

int main()
{
    int i, j, k, u, n, m;
    double sum;
    point ar[100010];
    while (scanf("%d %d", &n, &m) != EOF && (n != -1 || m != -1))
    {
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d", &ar[i].a, &ar[i].b);
            if (ar[i].b == 0)
                ar[i].c = MAX;
            else
                ar[i].c = (double)ar[i].a / (double)ar[i].b;
        }
        sort(ar + 1, ar + 1 + m, comp);
        //for (i = 1; i <= m; i++)
        //{
        //    printf("%.3lf ", ar[i].c);
        //}
        //putchar('\n');
        i = 1;
        sum = 0.0;
        while (n >= ar[i].b && i <= m)
        {
            sum += (double)ar[i].a;
            n -= ar[i].b;
            i++;
        }
        if(i <= m)
            sum += ar[i].c * (double)n;
        printf("%.3lf\n", sum);
    }
    return 0;
}