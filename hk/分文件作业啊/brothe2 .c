#include "headmark.h"
void weekth(int b)
{
	int n, count = 0, S, r;
	char ar[7][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	char (*p)[10];

	p = ar;
		for (n = 1; n <= b; n++)
		{
			if (leapyear(b))
				count++;
		}
	S = b * 365 + count;
	r = S % 7;
	printf("Uh~It is week %s!\n", *(p+r));

	return;
}
