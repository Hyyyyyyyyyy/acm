#include<stdio.h>
#include<math.h>
void main()
{
	double x1,x2,x3,a;
	printf("please input your number:");
	scanf("%lf",&a);
	x2=a;
	while(fabs(x1-x2)>1.0e-20)
	{
		x1=x2;
		x2=2/3.0*x1+a/(3.0*pow(x1,2.0));
	}
	printf("%.10lf\n",x2);
	x3=pow(a,1.0/3);
	printf("%.10lf\n",x3);
}