#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
const int MOD = 1000000007;
const int LEN = 10000;
char t[LEN + 10];
typedef long long ll;
char * G_plus(char *a, char *b);
ll bigDivision(char *src, int num, char sign);
char ar[200];
char sa[200];
int main()
{
    ll i, j, k, u, n, m, L, res, a, b, l;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%s", ar);
            if(strcmp(ar, "1") == 0)
            {
                printf("1\n");
                continue;
            }
            else if(strcmp(ar, "2") == 0)
            {
                printf("3\n");
                continue;
            }
            else
            {
                memset(sa, 0, sizeof(sa));
                sa[0] = '1';
                sa[1] = '\0';
                while(strcmp(ar, sa))
                {
                    G_plus(sa, "1");
                    L = strlen(sa) - 1;
                    if((sa[L] - '0') % 2 == 0)
                    {
                        res = (res % MOD + bigDivision(sa, MOD, '%')) % MOD;
                    }
                    else
                    {
                        res = (2 * res) % MOD;
                    }
                }
                printf("%lld\n", res);
            }
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
                c[k + 1] += 1;
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
                c[k + 1] += 1;
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
                c[k + 1] += 1;
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





ll bigDivision(char *src, int num, char sign) {
	int i, j;
	long long rem = 0; // 存放新余数 
	long long prem = 0; // 原余数
	char  res[10000] = "";
	bool flag = true;
	int k = 0;
	for (i = 0; i< strlen(src); ++i) {

		rem = prem * 10/*向后退一位*/ + src[i] - '0';
		if (rem / num >0 || rem == 0) {

			res[k++] = rem / num + '0';
			prem = rem %num;
			flag = false;
		}
		else {

			prem = rem;
			if (!flag)
				res[k++] = '0';
		}
	}

	if (sign == '%') {
        return prem;
	}
}