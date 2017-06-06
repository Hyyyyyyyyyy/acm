#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int i, j, k, u, n, m, max, L1, L2;
    char s1[1000], s2[1000];
    int ar[1000][1000];
    while (scanf("%s %s", s1+1, s2+1) != EOF)
    {
        L1 = strlen(s1+1);
        L2 = strlen(s2+1);
        for (i = 0; i <= L1; i++)
        {
            for (j = 0; j <= L2; j++)
            {
                if (i == 0 || j == 0)
                {
                    ar[i][j] = 0;
                    continue;
                }
                if (s1[i] != s2[j])
                {
                    ar[i][j] = (ar[i - 1][j] > ar[i][j - 1]) ? ar[i - 1][j] : ar[i][j - 1];
                }
                if (s1[i] == s2[j])
                    ar[i][j] = ar[i - 1][j - 1] + 1;
            }
        }
        printf("%d\n", ar[L1][L2]);
    }
    return 0;
}