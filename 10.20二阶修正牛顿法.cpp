/*170603108 自动化17-1 杨佳男*/
#include <stdio.h>
#include <stdlib.h>
//此为二阶修正牛顿法
/*预先提供原函数、梯度函数和Hessin矩阵就能求出二元函数的最小值*/
double fun(double x1, double x2);//待解的函数
double funGrad(double x1, double x2, double &g1, double &g2);//函数fun的梯度
double funHessin(double x1, double x2, double &h11, double &h12, double &h21, double &h22);//函数fun的Hessin矩阵
double ModifiedNewtown(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double(*Hessin)(double, double, double&, double&, double&, double&), double x1, double x2, int n);
//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，(*Hessin)指向Hessin矩阵，x1,x2为初始点，n为迭代次数

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&),(*h)(double, double, double&, double&, double&, double&);
	f = fun;
	g = funGrad;
	h = funHessin;//定义相应的函数指针
	result = ModifiedNewtown(f, g, h, 0, 1, 2);
	printf("函数最小值为 %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return (x1 - 1)*(x1 - 1)*(x1 - 1)*(x1 - 1) +  x2*x2 ;
}
double funGrad(double x1, double x2, double &g1, double &g2)//函数fun的梯度
{
	g1 = 4 * x1* x1* x1 - 12 * x1* x1 + 12 * x1 - 4;//此处g1g2使用引用方式传递参数避免了返回值仅有一个的问题
	g2 = 2 * x2;
	return  0;
}
double funHessin(double x1, double x2, double &h11, double &h12, double &h21, double &h22)//函数fun的Hessin矩阵
{
	h11 = 12 * (x1 - 1)*(x1 - 1);
	h12 = 0;
	h21 = 0;
	h22 = 2;
	return 0;
}

double ModifiedNewtown(double (*fun)(double, double), double(*Grad)(double, double, double&, double&), double(*Hessin)(double, double, double&, double&, double&, double&), double x1, double x2, int n)
{
	double g1, g2,t0, h11, h12, h21, h22,Det, inv11, inv12, inv21, inv22;
	//t0为一维搜索得出的最优步长，Det为Hessin矩阵的行列式的值，inv为逆矩阵
	for (int i = 0; i < n; i++) 
	{
		(*Grad)(x1, x2, g1, g2);
		(*Hessin)(x1, x2, h11, h12, h21, h22);
		Det = h11 * h22 - h12 * h21;
		inv11 = h22 / Det;
		inv12 = -h12 / Det;
		inv21 = -h21 / Det;
		inv22 = h11 / Det;//以上四步为求逆矩阵
		double t1, t2, left = -100, right = 100, precision = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//这些数据用于一维搜索,x1t1,x2t1在代回到fun中时可得到关于t1的函数φ(t1)，x1t1,x2t1在代回到fun中时可得到关于t2的函数φ(t2)
		while (right - left > precision)//此处使用0.618法一维搜索求合适t0,初始区间为（-100，100）精度为0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * (inv11*g1 + inv12 * g2);//1
			x2t1 = x2 - t1 * (inv21*g1 + inv22 * g2);//2
			x1t2 = x1 - t2 * (inv11*g1 + inv12 * g2);//3
			x2t2 = x2 - t2 * (inv21*g1 + inv22 * g2);//4、这四句将二元函数fun转换为关于t的一维函数，便于搜索
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)即φ(t1),(*fun)(x1t2, x2t2)即φ(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//一维搜索结束得到t0
		x1 = x1 - t0 * (inv11*g1 + inv12 * g2);
		x2 = x2 - t0 * (inv21*g1 + inv22 * g2);
		printf("第%d次迭代得到的点为(%f,%f)，最优步长t为%f\n", i + 1, x1, x2, t0);
	}
	printf("\n最小值点为(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}