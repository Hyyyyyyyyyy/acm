#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int Mainl, Assl;
int Next[500010];
char ar[500010], sa[500010];
int pos1[500010], pos2[500010];
int val[30], sum[500010];
int KMP(char *s, char *t);
void Cal_Next(char *s);
int main()
{
    int i, j, k1, k2, n, m, temp, max;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            for (i = 0; i < 26; i++)
                scanf("%d", &val[i]);
            scanf("%s", ar);
            Mainl = strlen(ar);
            sum[0] = 0;
            for (i = 0; i < Mainl; i++)
            {
                sa[i] = ar[Mainl - i - 1];
                sum[i + 1] = sum[i] + val[ar[i] - 'a'];
            }
            Cal_Next(ar);
            k1 = KMP(ar, sa);
            while (k1)
            {
                pos1[k1] = m;
                k1 = Next[k1];
            }
            Cal_Next(sa);
            k2 = KMP(sa, ar);
            while (k2)
            {
                pos2[k2] = m;
                k2 = Next[k2];
            }
            max = -MAX;
            for (i = 1; i < Mainl; i++)
            {
                temp = 0;
                if (pos1[i] == m)
                    temp += sum[i];
                if (pos2[Mainl - i] == m)
                    temp += sum[Mainl] - sum[i];
                if (temp > max)
                    max = temp;
            }
            printf("%d\n", max);
        }
    }
    return 0;
}
void Cal_Next(char *s)
{
    int i = -1, j = 0, L;
    Next[0] = -1;
    while (j < Mainl)
    {
        if (i == -1 || s[i] == s[j])
            Next[++j] = ++i;
        else
            i = Next[i];
    }
}

int KMP(char *s, char *t)
{
    int i = 0, j = 0;
    while (i < Mainl && j < Mainl)
    {
        if (i == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            i = Next[i];
    }
    return i;
}