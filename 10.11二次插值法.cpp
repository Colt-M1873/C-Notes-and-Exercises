# include <stdio.h>
#include <stdlib.h>
double fun(double x);
double Interpolation(double(*f)(double), double left, double right, double precision);
int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Interpolation(f, -1, 20, 0.01);
	printf("函数最小值为 %f \n对应的x值为 %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 3;
}

double Interpolation(double(*f)(double), double left, double right, double precision)
{
	int flag=0;
	double x1, x2, x3, xp, f1, f2, f3, fp,xplast=NULL;
	x2 = 0.5*(right - left);
	x1 = left, x3 = right;

	while (flag==0) {
		f1 = (*f)(x1);
		f2 = (*f)(x2);
		f3 = (*f)(x3);
		xp = 0.5*((x1*x1 - x2 * x2)*f3 + (x2*x2 - x3 * x3)*f1 + (x3* x3 - x1 * x1)*f2) / ((x1 - x2)*f3 + (x2 - x3)*f1 + (x3 - x1)*f2);
		fp = (*f)(xp);
		if (x2 < xp&&f2 < fp) {
			x3 = xp;
		}
		else if (x2< xp&&f2>fp) {
			x1 = x2;
			x2 = xp;
		}
		else if (x2 > xp&&f2 > fp) {
			x3 = x2;
			x2 = xp;
		}
		else if (x2 > xp&&f2 < fp) {
			x1 = xp;
		}
		if (xp - xplast < precision || xplast - xp < precision)//判断是否到达精度值
			flag = 1;
		else
			xplast = xp;
	}

	return xp;

}


