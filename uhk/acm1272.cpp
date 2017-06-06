#include <cstdio>
#include <cstring>
int main()
{
    int i, j, k, a, b, c, p, q, set[100010], N, M, doudou = 0, sum = 0, max = 0, ar[100010], min = 100010, count = 0;
    for(i = 0; i <= 100000; i++)
    	set[i] = i;
   	memset(ar, 0, sizeof(ar));
    while(scanf("%d%d", &a, &b) != EOF && (a != -1 || b != -1))
    {
        if(a == 0 && b == 0)
        {
        	count = 0;
        	for(i = min; i <= max; i++)
        		if(ar[i])
        			count++;
			if(count == 0)        //这个是最坑的！！!!
				printf("Yes\n");
            else if(!doudou && sum == count-1)
                printf("Yes\n");
            else
                printf("No\n");
            doudou = 0;
            max = 0;
            sum = 0;
            min = 100010;
            memset(ar, 0, sizeof(ar));
            for(i = 0; i <= 100000; i++)
    			set[i] = i;
 			continue;
        }
       	ar[a] = 1;
    	ar[b] = 1;
    	if(max < a)
    		max = a;
   		if(max < b)
   			max = b;
		if(min > a)
			min = a;
		if(min > b)
			min = b;
        while(a!=set[a])
            a=  set[a];
        while(b != set[b])
            b = set[b];
        if(a != b)
        {
        	set[b] = a;
        	sum++;
        }
        else
            doudou = 1;
    }
    return 0;
}