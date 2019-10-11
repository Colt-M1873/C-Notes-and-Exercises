/* 170603018 自动化17-1 杨佳男 */
#include<stdio.h>
#include<stdlib.h>
double fun(double x);
double funDiff1(double x);//函数fun的一次导数
double funDiff2(double x);//函数fun的二次导数
double Newton(double(*fun)(double), double(*diff1)(double), double(*diff2)(double), double x, double precision);
////*fun为指向待求函数的函数指针,*diff1指向函数的一阶导数，*diff2指向二阶导数，x为初始点，precision为精度值
int main()
{
	double result;
	double(*f)(double), (*d1)(double), (*d2)(double);
	f = fun;
	d1 = funDiff1;
	d2 = funDiff2;
	result = Newton(f, d1, d2, 100, 0.01);
	printf("函数最小值为 %f \n对应的x值为 %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 3;
}
double funDiff1(double x)//函数fun的一阶导数
{
	return 2 * x - 6;
}
double funDiff2(double x)//函数fun的二阶导数
{
	return 2;
}

double Newton(double(*fun)(double), double(*diff1)(double), double(*diff2)(double), double x,double precision)
{
	while ((*diff1)(x) > precision || (*diff1)(x) < precision*(-1))//判断是否到达精度值 
	{
		x = x - (*diff1)(x) / (*diff2)(x);
	}
	return x;
}
