#include <stdio.h>
int main()
{
    int a, b, c;
    int * qa, * qb;

	qa = &a;
	qb = &b;
    scanf("%d %d", &*qa, &*qb);

    qa = (a > b) ? &b:&a;
    qb = (a > b) ? &a:&b;
    
    printf("max = %d min = %d\n", *qb, *qa);

    return 0;
}
