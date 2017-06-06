#include <stdio.h>
void F(int n);
int main()
{
	int i, a;
	scanf("%d", &a);
    if (a >= 0 && a <= 6)
        F(a);
    else
        printf("Are you kidding?\n");
    
    return 0;
}

void F(int n)
{

    char ar[7][3]={ "日", "一", "二", "三", "四", "五", "六" };
	printf("星期%s", ar[n]);
	
	return;
}
