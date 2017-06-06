#include <stdio.h>
int ndigit(long long int a,int b);
int main()
{
    long long int n;
    int k;

    scanf("%lld %d", &n, &k);
    if (ndigit(n, k) == 0)
    	printf("error\n");
   	else
    	printf("%d\n", ndigit(n, k));
    return 0;
}

int ndigit(long long int a,int b)
{
	int count, ar[1000];
	long long int i, u, temp;
 	if (b != 0 && b != 1 && b != 2 && b != 3 && b != 4 && b != 5 && b != 6 && b != 7 && b != 8 && b != 9)
        return 0;
    else
    {
        count = 0;
        i = 0;
        temp = a;
        while (a > 0)
        {
            ar[i] = a % 10;
            a = a / 10;
            i++;
        }
        for (u = 0; u < i; u++)
        {
            if(ar[u] == b)
                count++;
        }
        return count;
    }
}
