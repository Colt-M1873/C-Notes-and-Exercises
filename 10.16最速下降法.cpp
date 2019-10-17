/*170603108 自动化17-1 杨佳男*/
#include <stdio.h>
#include <stdlib.h>
/*只需预先提供原函数和梯度函数就能求出二次函数的最小值，*/
double fun(double x1, double x2);//待解的函数
double funGrad(double x1, double x2, double &g1, double &g2);//函数fun的梯度
double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&),double x1, double x2, int n);
//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，(*fxt)指向一维搜索t的函数模板，x1,x2为初始点，n为迭代次数

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;
	result = GradientDescend(f, g, 1, 1, 5);
	printf("函数最小值为 %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return x1 * x1 + 4 * x2*x2 + 3;
}

double funGrad(double x1, double x2, double &g1, double &g2)//函数fun的梯度
{
	g1 = 2 * x1;//此处g1g2使用引用方式传递参数避免了返回值仅有一个的问题
	g2 = 8 * x2;
	return  0;
}

double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, int n)
{
	//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，(*fxt)指向一维搜索t的函数模板，x1,x2为初始点，n为迭代次数
	double g1, g2, t0;//t0为最优步长
	for (int i = 0; i < n; i++)
	{
		(*Grad)(x1, x2, g1, g2);
		double t1, t2, left = -100, right = 100, precision = 0.00001,x1t1, x2t1, x1t2, x2t2;
		//这些数据用于一维搜索,x1t1,x2t1在代回到fun中时可得到关于t1的函数，x1t1,x2t1在代回到fun中时可得到关于t2的函数
		while (right - left > precision)//此处使用0.618法一维搜索求合适t0,初始区间为（-100，100）精度为0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * g1;
			x2t1 = x2 - t1 * g2;
			x1t2 = x1 - t2 * g1;
			x2t2 = x2 - t2 * g2;//这四句将二元函数fun转换为关于t1和t2的一维函数，便于搜索
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//一维搜索结束得到t0
		x1 = x1 - t0 * g1;
		x2 = x2 - t0 * g2;//获得新的x1，x2值
	}
	return (*fun)(x1, x2);
	//return t0;//用于测试t0，尚不完善
}


