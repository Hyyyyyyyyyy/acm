#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

#define MAXN 550
char show[10][30];
int match[10];
void getmatch()
{
    memset(match,0,sizeof(match));
    match[0]+=1;
    match[0]+=1<<1;
    match[0]+=1<<2;
    match[0]+=1<<4;
    match[0]+=1<<5;
    match[0]+=1<<6;
    match[1]+=1<<2;
    match[1]+=1<<5;
    match[2]+=1;
    match[2]+=1<<2;
    match[2]+=1<<3;
    match[2]+=1<<4;
    match[2]+=1<<6;
    match[3]+=1;
    match[3]+=1<<2;
    match[3]+=1<<3;
    match[3]+=1<<5;
    match[3]+=1<<6;
    match[4]+=1<<1;
    match[4]+=1<<2;
    match[4]+=1<<3;
    match[4]+=1<<5;
    match[5]+=1<<0;
    match[5]+=1<<1;
    match[5]+=1<<3;
    match[5]+=1<<5;
    match[5]+=1<<6;
    match[6]+=1<<0;
    match[6]+=1<<1;
    match[6]+=1<<3;
    match[6]+=1<<4;
    match[6]+=1<<5;
    match[6]+=1<<6;
    match[7]+=1<<0;
    match[7]+=1<<2;
    match[7]+=1<<5;
    match[8]+=1<<0;
    match[8]+=1<<1;
    match[8]+=1<<2;
    match[8]+=1<<3;
    match[8]+=1<<4;
    match[8]+=1<<5;
    match[8]+=1<<6;
    match[9]+=1<<0;
    match[9]+=1<<1;
    match[9]+=1<<2;
    match[9]+=1<<3;
    match[9]+=1<<5;
    match[9]+=1<<6;
}
int main(int argc, char const *argv[])
{
    int t;
    getmatch();
    while(cin>>t)
    {
        int ans[4];
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<7;++i)
            scanf("%s",show[i]);
        int po=0;
        for(int i=0;i<21;i+=5,po++)
        {
            int cur=0;
            if(show[0][i+1]=='X')
                cur+=1<<0;
            if(show[1][i]=='X')
                cur+=1<<1;
            if(show[1][i+3]=='X')
                cur+=1<<2;
            if(show[3][i+1]=='X')
                cur+=1<<3;
            if(show[4][i]=='X')
                cur+=1<<4;
            if(show[4][i+3]=='X')
                cur+=1<<5;
            if(show[6][i+1]=='X')
                cur+=1<<6;
            for(int j=0;j<=9;++j)
                if(cur==match[j])
                {   ans[po]=j;
                    break;
                }
            if(i==5)
                i+=2;
        }
        printf("%d%d:%d%d\n",ans[0],ans[1],ans[2],ans[3]);
    }
    return 0;
}
