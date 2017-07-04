//反素数的定义：对于任何正整数n，其约数个数记为f[n]，例如f[6] = 4，如果某个正整数n满足：对任意的正整
//            数i(0 < i < n)，都有f[i] < f[n]，那么称n为反素数。
//在ACM竞赛中，最常见的问题如下：
//（1）给定一个数n，求一个最小的正整数x，使得x的约数个数为n (n > 0)
//（2）求出1~n中约数个数最多的这个数


//1、
#include <iostream>  
#include <cstring>  
#include <cstdio>  
using namespace std;  
typedef long long ll;  
const ll INF = 9223372036854775807;

int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
ll RES;
void dfs(ll dept, ll tmp, ll num, ll limit)  
{  
    if(num > limit) return;
    if(num == limit && RES > tmp) 
        RES = tmp;
    for(int i = 1; i <= 63; i++)  
    {  
        if(RES / p[dept] < tmp)
            break;
        dfs(dept + 1, tmp *= p[dept], num*(i+1), limit);  
    }  
}
int main()  
{  
    ll n;
    while(cin>>n)  
    {  
        RES = INF;  
        dfs(0,1,1,n); 
        cout<<RES<<endl;  
    }  
    return 0;  
}



//2、
