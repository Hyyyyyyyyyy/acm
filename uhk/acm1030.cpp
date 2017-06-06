#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define max 10010
int main()
{
   int n,m,dn,dm,lm,ln,rn,rm,sum;
   while(~scanf("%d%d",&m,&n))
   {
       dn=sqrt(n-1)+1;
       dm=sqrt(m-1)+1;
       ln=(n-(dn-1)*(dn-1)+1)/2;
       lm=(m-(dm-1)*(dm-1)+1)/2;
       rn=(dn*dn-n)/2+1;
       rm=(dm*dm-m)/2+1;
       sum=abs(dn-dm)+abs(ln-lm)+abs(rn-rm);
       printf("%d\n",sum);
   }
    return 0;
}
