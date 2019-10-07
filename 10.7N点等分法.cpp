/*170603108 自动化17-1 杨佳男*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);
double nDotDivide(double(*fun)(double), int n, double left, double right, double precision);

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = nDotDivide(f, 3, -1, 20, 0.01);
	printf("%f", result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double nDotDivide(double (*fun)(double), int n,double left, double right, double precision)
{
	//*fun为指向待求函数的函数指针，n为等分点数，left right为搜索区间端点，precision为精度值
	double xn[20],fmin;
	int nmin;
	while (right - left > precision)
	{
		fmin = (*fun)(left);
		nmin = 0;
		for (int i = 0; i <= n + 1; i++)
		{
			xn[i] = left + i * (right - left) / (n+1);//现在xn中前n+2个数就是存储的包括两端在内的每一个点的x值
			if ((*fun)(xn[i]) < fmin)
			{
				fmin = (*fun)(xn[i]);//找最小函数值
				nmin = i;//最小函数值对应的xn数组下标
			}
		}
		left = xn[nmin - 1];//更新区间
		right = xn[nmin + 1];//
	}
	return 0.5*(left + right);//返回值为最小区间中点的x值
}