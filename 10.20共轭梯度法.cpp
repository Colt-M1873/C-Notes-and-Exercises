/*170603108 自动化17-1 杨佳男*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*只需预先提供原函数和梯度函数就能求出二元函数的最小值，*/
double fun(double x1, double x2);//待解的函数
double funGrad(double x1, double x2, double &g1, double &g2);//函数fun的梯度
double ConjugateGradient(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision);
//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，x1,x2为初始点，precision为精度值

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;
	result = ConjugateGradient(f, g, 0, 0, 0.000001);
	printf("函数最小值为 %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return x1 * x1 + 2 * x2 * x2 - 2 * x1 * x2 + 2 * x2 + 2;
}

double funGrad(double x1, double x2, double &g1, double &g2)//函数fun的梯度
{
	g1 = 2 * x1 - 2 * x2;//此处g1g2使用引用方式传递参数避免了返回值仅有一个的问题
	g2 = 4 * x2 - 2 * x1 + 2;
	return  0;
}

double ConjugateGradient(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision)
{
	//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，x1,x2为初始点，precision为精度值
	int i = 0;//计迭代次数
	double g1, g2, Normg, p1=0, p2=0, a=0, t0;//Normg为梯度的范数,Pk=(p1,p2)为搜索方向,t0为一维搜索的最优步长
	(*Grad)(x1, x2, g1, g2);
	Normg = sqrt(g1*g1 + g2 * g2);
	while (Normg>=precision)
	{
		p1 = -g1 + a * p1;
		p2 = -g2 + a * p2;//新方向，因初始时a=0故初始方向即为负梯度方向
		double t1, t2, left = -100, right = 100, precision = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//这些数据用于一维搜索,x1t1,x2t1在代回到fun中时可得到关于t1的函数φ(t1)，x1t1,x2t1在代回到fun中时可得到关于t2的函数φ(t2)
		while (right - left > precision)//此处使用0.618法一维搜索求合适t0,初始区间为（-100，100）精度为0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 + t1 * p1;//1
			x2t1 = x2 + t1 * p2;//2
			x1t2 = x1 + t2 * p1;//3
			x2t2 = x2 + t2 * p2;//4、这四句将二元函数fun转换为关于t1和t2的一维函数，便于搜索
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)即φ(t1),(*fun)(x1t2, x2t2)即φ(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//一维搜索结束得到t0
		x1 = x1 + t0 * p1;
		x2 = x2 + t0 * p2;//获得新的x1，x2值
		printf("第%d次迭代得到的点为(%f,%f)，最优步长t为%f\n", ++i, x1, x2, t0);
		(*Grad)(x1, x2, g1, g2);
		a = (g1*g1 + g2 * g2) / (Normg*Normg);
		Normg= sqrt(g1*g1 + g2 * g2);
	}
	printf("\n最小值点为(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}


