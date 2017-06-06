#include<cstdio>
#include<algorithm>
using namespace std;


struct point
{
	int x;
	int index;
};
point a[50];

bool cmp(point a,point b)
{
	return a.x<b.x;
}
int main()
{
	sort(a,a+50,cmp);
}
