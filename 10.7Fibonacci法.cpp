/*170603108 自动化17-1 杨佳男*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//此为待求取的函数
double Fibonacci(double(*fun)(double), int n, double left, double right);
//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Fibonacci(f, 6, -1, 20);
	printf("函数最小值为 %f \n对应的x值为 %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double Fibonacci(double(*fun)(double),int n, double left, double right)
{
	//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点
	double fib[50];//斐波那契数列
	double x1, x2;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int j = 0; j < n; j++)
	{
		x1 = left + fib[n - 2] / fib[n] * (right - left);
		x2 = left + fib[n - 1] / fib[n] * (right - left);
		if ((*fun)(x1) < (*fun)(x2))
			right = x2;
		else
			left = x1;
	}
	return 0.5*(left + right);//返回值为最小区间中点的x值
}
