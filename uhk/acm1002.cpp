#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
const int LEN = 10000;
char t[LEN + 10];
char * G_plus(char *a, char *b);
int main()
{
    int i, j, k, n, m, doudou;
    char a[LEN], b[LEN];
    while (scanf("%d", &n) != EOF)
    {
        doudou = 0;
        for (m = 1; m <= n; m++)
        {
            scanf("%s %s", a, b);
            if (doudou)
                putchar('\n');
            doudou = 1;
            printf("Case %d:\n", m);
            printf("%s + %s = %s\n", a, b, G_plus(a, b));
        }
    }
    return 0;
}
char * G_plus(char *a, char *b)
{
    int L1, L2, L3, i, j, k, u;
    char temp[LEN + 10], c[LEN + 10];
    memset(c, 48, sizeof(c));
    memset(t, 48, sizeof(t));
    //puts(a);
    //puts(b);
    L1 = strlen(a);
    L2 = strlen(b);
//不管谁长谁短一起搞，一个没了只加入另一个就行了，两个都没了结束；
    for (i = L1 - 1, j = L2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++)
    {
        if (j < 0)
        {
            u = c[k] + a[i] - '0' - '0';
            if (u >= 10)
            {
                c[k + 1] += u / 10;
                c[k] = u % 10 + '0';
            }
            else
                c[k] = u + '0';
        }
        if (i < 0)
        {
            u = c[k] + b[j] - '0' - '0';
            if (u >= 10)
            {
                c[k + 1] += u / 10;
                c[k] = u % 10 + '0';
            }
            else
                c[k] = u + '0';
        }
        if (i >= 0 && j >= 0)
        {
            u = c[k] + a[i] + b[j] - '0' - '0' - '0';
            //printf("%d\n", u);
            if (u >= 10)
            {
                c[k + 1] += u / 10;
                c[k] = u % 10 + '0';
            }
            else
            {
                c[k] = u + '0';
            }
        }
    }
    c[k+1] = '\0';
    i = strlen(c) - 1;
//去掉前导0；
    while (c[i] == '0')
        i--;
//如果结果是0，输出“0”
    if (i == -1)
        return "0";
//把反向改为正向输出
    for (j = 0; i >= 0; i--, j++)
        t[j] = c[i];
    t[j] = '\0';
    return t;
}
