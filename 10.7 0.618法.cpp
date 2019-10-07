/*170603108 自动化17-1 杨佳男*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//此为待求取的函数
double Golden(double(*fun)(double), double left, double right, double precision);
//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,precision为精度值

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Golden(f, -1, 10, 0.003);
	printf("函数最小值为 %f \n对应的x值为 %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double Golden(double(*fun)(double), double left, double right, double precision)
{
	//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,precision为精度值
	double x1, x2;
	while (right - left > precision)
	{
		x1 = left + 0.382 * (right - left);
		x2 = left + 0.618 * (right - left);
		if ((*fun)(x1) < (*fun)(x2))
			right = x2;
		else
			left = x1;
	}
	return 0.5*(left + right);
}