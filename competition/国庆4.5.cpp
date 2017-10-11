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
typedef unsigned long long ull;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e12 + 7;
const int maxn = 5000 + 300;
char A[maxn], B[maxn];
ull xp[maxn];
ull Hash1[maxn], Hash2[maxn];
int main()
{
    int i,  j, k, n, m;
    xp[0] = 1;
    for(i = 1; i < maxn; i++)
        xp[i] = xp[i-1] * MOD;
    while(scanf("%s", A) != EOF)
    {
        scanf("%s", B);
        int LA = strlen(A);
        int LB = strlen(B);
        if(LA != LB)
        {
            printf("NO\n");
            continue;
        }
        int L = LA;
        for(i = 0; i < L; i++)
        {
            if(isupper(A[i]))
                A[i] = tolower(A[i]);
            if(isupper(B[i]))
                B[i] = tolower(B[i]);
        }
        Hash1[L] = 0;
        Hash2[L] = 0;
        for(i = L-1; i >= 0; i--)
        {
            Hash1[i] = Hash1[i+1] * MOD + B[i] - 'a' + 1;
            Hash2[i] = Hash2[i+1] * MOD + A[i] - 'a' + 1;
        }
        int res1 = -1;
        int res2 = -1;
        int res3 = -1;
        int res1l;
        int res2l;
        int res3l;
        for(i = 1; i < L-1; i++)
        {
            if(res1 != -1)
                break;
            
            for(j = i+1; j < L; j++)
            {
                if(res1 != -1)
                {
                    break;
                }
                if(Hash1[0] - Hash1[i]*xp[i] == Hash2[0] - Hash2[i]*xp[i])
                {
                    if(Hash1[i] - Hash1[j]*xp[j-i] == Hash2[i] - Hash2[j]*xp[j-i])
                    {
                        if(Hash1[j] - Hash1[L]*xp[L-j] == Hash2[j] - Hash2[L]*xp[L-j])
                        {
                            res1 = 0;
                            res1l = i;
                            res2 = i;
                            res2l = j-i;
                            res3 = j;
                            res3l = L-j;
                        }
                    }
                    if(Hash1[i] - Hash1[j]*xp[j-i] == Hash2[j] - Hash2[L]*xp[L-j])
                    {
                        if(Hash1[j] - Hash1[L]*xp[L-j] == Hash2[i] - Hash2[j]*xp[j-i])
                        {
                            res1 = 0;
                            res1l = i;
                            res2 = j;
                            res2l = L-j;
                            res3 = i;
                            res3l = j-i;
                        }
                    }
                }
                if(Hash1[0] - Hash1[i]*xp[i] == Hash2[i] - Hash2[j]*xp[j-i])
                {
                    if(Hash1[i] - Hash1[j]*xp[j-i] == Hash2[0] - Hash2[i]*xp[i])
                    {
                        if(Hash1[j] - Hash1[L]*xp[L-j] == Hash2[j] - Hash2[L]*xp[L-j])
                        {
                            res1 = i;
                            res1l = j-i;
                            res2 = 0;
                            res2l = i;
                            res3 = j;
                            res3l = L-j;
                        }
                    }
                    if(Hash1[i] - Hash1[j]*xp[j-i] == Hash2[j] - Hash2[L]*xp[L-j])
                    {
                        if(Hash1[j] - Hash1[L]*xp[L-j] == Hash2[0] - Hash2[i]*xp[i])
                        {
                            res1 = i;
                            res1l = j-i;
                            res2 = j;
                            res2l = L-j;
                            res3 = 0;
                            res3l = i;
                        }
                    }
                }
                if()
            }
            
        }
    }
}