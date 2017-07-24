#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct point
{
    int x,y;
};
struct vec
{
    int x,y;
};
bool intersect(point v1,point v2,point v3,point v4)
{
    int d = (v4.y-v3.y)*(v2.x-v1.x)-(v4.x-v3.x)*(v2.y-v1.y);
    int u = (v4.x-v3.x)*(v1.y-v3.y)-(v4.y-v3.y)*(v1.x-v3.x);
    int v = (v2.x-v1.x)*(v1.y-v3.y)-(v2.y-v1.y)*(v1.x-v3.x);
    if(d<0)
    {
        u*=-1; d*=-1; v*=-1;
    }
    return (0<=u && u<=d)&&(0<=v && v<=d);
}
int cross(vec v1,vec v2)
{
    return (v1.x*v2.y -v1.y*v2.x);
}
vec setvec(point f,point t)
{
    vec temp={t.x-f.x,t.y-f.y};
    return temp;
}
bool leftside(point f,point t,point p)
{
    vec ft={t.x-f.x,t.y-f.y};
    vec fp={p.x-f.x,p.y-f.y};
    return (cross(ft,fp)<0);
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        point tra[2][3];
        for(int i=0;i<3;++i)
            scanf("%d%d",&tra[0][i].x,&tra[0][i].y);
        for(int i=0;i<3;++i) 
            scanf("%d%d",&tra[1][i].x,&tra[1][i].y);
        bool not_intersect=1;
        for(int i=0;i<3 && not_intersect;++i)
            for(int j=0;j<3 && not_intersect;++j)
                if(intersect(tra[0][i],tra[0][(i+1)%3],tra[1][j],tra[1][(j+1)%3]))
                    not_intersect=0;
        if(!not_intersect)
        {
            printf("intersect\n");
            continue;
        }
        bool inside[2]={1,1};
        for (int i = 0; i < 2; ++i)
        {
            if(leftside(tra[i][0],tra[i][1],tra[i][2]))
            {
                for(int j=0;j<3;++j)
                    for(int k=0;k<3;++k)
                        if(!leftside(tra[i][j],tra[i][(j+1)%3],tra[!i][k]))
                            inside[i]=0;
            }
            else
            {
                for(int j=2;j>=0;--j)
                    for(int k=0;k<3;++k)
                        if(!leftside(tra[i][j],tra[i][(j+2)%3],tra[!i][k]))
                            inside[i]=0;           
            }
        }
        if(inside[0] || inside[1])
            printf("contain\n");
        else 
            printf("disjoint\n");
    }  
}
