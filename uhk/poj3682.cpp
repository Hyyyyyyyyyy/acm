#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	
	double p,k;
	while (scanf("%lf", &k) != EOF && (k))
	{
		scanf("%lf", &p);
		printf("%.3f %.3f\n", k / p, k*(k+1)/ (p*p) - k/p);
	}
	return 0;
}
