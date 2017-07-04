#include <iostream>  
#include <cstring>  
#include <cstdio>  
using namespace std;  
typedef long long ll; 
const ll maxn = 50000;
int euler[maxn+10];
void getEuler()
{
    memset(euler, 0, sizeof(euler));
    euler[1] = 1;
    for(int i = 2; i <= maxn; i++)
    {
        if(!euler[i])
        {
            for(int j = i; j <= maxn; j += i)
            {
                if(!euler[j])
                {
                    euler[j] = j;
                }
                euler[j] = euler[j] / i * (i-1);
            }
        }
    }
}