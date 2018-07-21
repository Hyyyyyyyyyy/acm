#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
stack<char>S;
char s[maxn];
int main()
{
    int i, j, k, cas, CAS;
    while(scanf("%d", &CAS) != EOF)
    {
        getchar();
        for(cas = 1; cas <= CAS; cas++)
        {
            while (!S.empty())
				S.pop();
            gets(s);
            int L = strlen(s);
            for(i = 0; i < L; i++)
            {
                if(s[i] != ' ' && s[i] != ',' && s[i] != '.')
                {
                    S.push(s[i]);
                }
                else
                {
                    while(!S.empty())
                    {
                        printf("%c", S.top());
                        S.pop();
                    }
                    printf("%c", s[i]);
                }
            }
            while(!S.empty())
            {
                printf("%c", S.top());
                S.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
