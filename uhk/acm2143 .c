#include <stdio.h>
int main()
{
	long long int a, b, c;
	while (scanf("%lld %lld %lld", &a, &b, &c) != EOF)
	{

		if (a + b == c || a + c == b || b + c == a || a*b == c || a*c == b || b*c == a || (a != 0 && (b%a==c || c%a==b)) || (b != 0 && (c%b==a || a%b==c)) || (c != 0 && (a%c==b || b%c==a)))
			printf("oh,lucky!\n");
		else
			printf("what a pity!\n");

	}
	return 0;
}
