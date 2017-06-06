#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
    int i, j, k, n, m ,N, M, a, b, c, cas = 1, doudou = 0, flag = 0, sum = 0, count = 0, set[100010], ar[100010], from[100010], max = 0, min = 100010;
    memset(ar, 0, sizeof(ar));
    memset(from, 0, sizeof(from));
    for(i = 0; i <= 100000; i++)
        set[i] = i;
    while(scanf("%d%d", &a, &b) != EOF && (a != -1 || b != -1))
    {
        if(a == 0 && b == 0)
        {
            for(i = min; i <= max; i++)
            {
                if(ar[i] && from[i] != 1)
                {
                	if(from[i] == 0)
                		flag++;
               		else
               			doudou = 1;
                }
                if(ar[i])
                    count++;
            }
            if(count == 0)
                printf("Case %d is a tree.\n", cas++);
            else if(flag == 1 && !doudou && sum == count-1)
                printf("Case %d is a tree.\n", cas++);
            else
                printf("Case %d is not a tree.\n", cas++);
            memset(ar, 0, sizeof(ar));
            memset(from, 0, sizeof(from));
            for(i = 0; i <= 100000; i++)
                set[i] = i;
            max = 0;
            min = 100010;
            count = 0;
            sum = 0;
            doudou = 0;
            flag = 0;
            continue;
        }
        ar[a] = 1;
        ar[b] = 1;
        from[b]++;
        if(max < a)
    		max = a;
   		if(max < b)
   			max = b;
		if(min > a)
			min = a;
		if(min > b)
			min = b;
        while(a != set[a])
            a = set[a];
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