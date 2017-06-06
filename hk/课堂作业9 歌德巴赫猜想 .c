#include <stdio.h>
#include <stdbool.h>
int main()
{
    int num, snum, i, u;
    bool doudou;

    for (num = 6;; num = num + 2)
    {
    	for (snum = 2; snum <= (num / 2); snum++)
    	{
        	for (i = 2, doudou = 1; (i * i)  <= snum; i++)
            	if(snum % i == 0)
            		doudou = 0;
                	break;
        	if (doudou)
        	{
				for (u = 2; (u * u) <= (num - snum); u++)
					if((num - snum) % u == 0)
						doudou = 0;
						break;
        	
				if (doudou)
					break;
        	}
   		}
   		if (doudou)
   			printf("%d is right!\n", num);
		else
		{
			printf("%d Bingo!\n", num);
			exit(0);
		}
    }
    return 0;
}
