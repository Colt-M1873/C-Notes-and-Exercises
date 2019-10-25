/*170603108 自动化17-1 杨佳男*/
#include <stdio.h>
#include <stdlib.h>
//此为约束坐标轮换法
/*预先提供原函数和约束条件就能求出二元函数的最小值*/
//待完善，只能迭代两次（原因未知）且缺少负方向内容，坐标只能沿着两个正方向增长
double fun(double x1, double x2);//待解的函数
double Restriction(double x1, double x2);//约束条件
double UnivariationSearch(double(*fun)(double, double), double(*Restriction)(double, double), double x1, double x2, double t0, double precision);
//(*fun)为指向待求函数的指针，(*Restriction)指向约束条件函数，x1,x2为初始点，t0为初始步长，precision为精度

int main()
{
	double result;
	double(*f)(double, double), (*res)(double, double);
	f = fun;
	res = Restriction;//定义相应的函数指针
	result = UnivariationSearch(f, res, 1, 1, 0.5, 0.1);
	printf("函数最小值为 %f", result);
	system("pause");
}

double fun(double x1, double x2)//待求解函数
{
	return x1 * x1 + 2 * x2*x2 - 4 * x1 - 8 * x2 + 15;
}
double Restriction(double x1, double x2)//约束条件
{
	double g1, g2, g3;
	g1 = 9 - x1 * x1 - x2 * x2;
	g2 = x1;
	g3 = x2;
	if (g1 >= 0 && g2 >= 0 && g3 >= 0)
		return  1;
	else
		return 0;
}

double UnivariationSearch(double(*fun)(double, double), double(*Restriction)(double, double), double x1, double x2, double t0, double precision)
{
	//(*fun)为指向待求函数的指针，(*Restriction)指向约束条件函数，x1,x2为初始点，t0为初始步长，precision为精度
	double  t;
	int i=0, j=0;//用于计数
	if ((*Restriction)(x1, x2)) {
		while (t0 >= precision) {
			if ((*fun)(x1 + t0, x2) < (*fun)(x1, x2) && (*Restriction)(x1 + t0, x2)) {
				//此处if是为判断能否沿着x1方向迈出第一步
				t = t0;
				while ((*fun)(x1 + 2 * t, x2) < (*fun)(x1 + t, x2) && (*Restriction)(x1 + 2 * t, x2)) {
					t = 2 * t;//沿着x1方向走到不能再走
				}
				x1 += t;
				++i;
				printf("沿x1方向第%d次迭代得到的点为(%f,%f)，最优步长t为%f\n", i, x1, x2, t);
			}
			else if ((*fun)(x1, x2 + t0) < (*fun)(x1, x2) && (*Restriction)(x1, x2 + t0)) {
				//此处if是为判断能否沿着x2方向迈出第一步
				t = t0;
				while ((*fun)(x1, x2 + 2 * t) < (*fun)(x1, x2 + t) && (*Restriction)(x1, x2 + 2 * t)) {
					t = 2 * t;//沿着x2方向走到不能再走
				}
				x2 += t;
				++j;
				printf("沿x2方向第%d次迭代得到的点为(%f,%f)，最优步长t为%f\n", j, x1, x2, t);
			}
			else {//若两个方向均不能再前进
				t0 = t0 / 2;
			}
		}
	}
	else{
		printf("初始点无效");
	}
	printf("\n最小值点为(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}