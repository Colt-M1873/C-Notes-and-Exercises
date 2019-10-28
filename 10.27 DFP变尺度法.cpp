/*170603108 自动化17-1 杨佳男*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//此为DFP变尺度法,预先提供原函数和梯度函数就能求出二元函数的最小值
double fun(double x1, double x2);//待解的函数
double funGrad(double x1, double x2, double &g1, double &g2);//函数fun的梯度
double DFP(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision);
//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，x1,x2为初始点，precision为精度

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;//定义相应的函数指针
	result = DFP(f, g, 20, 11, 0.0000000001);
	printf("函数最小值为 %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return (x1 - 1)*(x1 - 1)*(x1 - 1)*(x1 - 1) + x2 * x2;
}
double funGrad(double x1, double x2, double &g1, double &g2)//函数fun的梯度
{
	g1 = 4 * x1* x1* x1 - 12 * x1* x1 + 12 * x1 - 4;//此处g1g2使用引用方式传递参数避免了返回值仅有一个的问题
	g2 = 2 * x2;
	return  0;
}

double DFP(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision)
{
	//(*fun)为指向待求函数的指针，(*Grad)指向待求函数的梯度函数，x1,x2为初始点，precision为精度
	double g1, g2, t0, dx1, dx2, dg1, dg2, g1last, g2last;//g1,g2为梯度，t0为一维搜索得出的最优步长,dx1,dx2为Δx，dg1，dg2为Δg, g1last,g2last存储上一次的g用于计算Δg
	double h11 = 1, h12 = 0, h21 = 0, h22 = 1;//h11,h12,h21,h22为构成H矩阵的四个元素，初始为单位矩阵
	int i = 0;//计数器
	(*Grad)(x1, x2, g1, g2);
	while (1) {//此处恒为真是为了减小运算量，若将精度判断放在此处则会在g1 g2满足精度要求之后再多计算一次H矩阵
		double t1, t2, left = -100, right = 100, prec = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//这些数据用于一维搜索,x1t1,x2t1在代回到fun中时可得到关于t1的函数φ(t1)，x1t1,x2t1在代回到fun中时可得到关于t2的函数φ(t2)
		while (right - left > prec) {//此处使用0.618法一维搜索求合适t0,初始区间为（-100，100）精度为0.00001
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * (h11*g1 + h12 * g2);//1
			x2t1 = x2 - t1 * (h21*g1 + h22 * g2);//2
			x1t2 = x1 - t2 * (h11*g1 + h12 * g2);//3
			x2t2 = x2 - t2 * (h21*g1 + h22 * g2);//4、这四句将二元函数fun转换为关于t的一维函数，便于搜索
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)即φ(t1),(*fun)(x1t2, x2t2)即φ(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//一维搜索结束得到t0
		x1 = x1 - t0 * (h11*g1 + h12 * g2);
		x2 = x2 - t0 * (h21*g1 + h22 * g2);
		g1last = g1;
		g2last = g2;
		i++;
		printf("第%d次迭代得到的点为(%f,%f)，最优步长t为%f\n", i, x1, x2, t0);
		(*Grad)(x1, x2, g1, g2);
		if (sqrt(g1*g1 + g2 * g2) < precision)		{//将循环终止条件放在此处可减小运算量，一旦g1 g2符合要求则立即终止循环，不进行下一步对H矩阵的复杂运算
			break;
		}
		dx1 = -t0 * (h11*g1 + h12 * g2);
		dx2 = -t0 * (h21*g1 + h22 * g2);//Δx
		dg1 = g1 - g1last;
		dg2 = g2 - g2last;//Δg
		h11 = h11 + dx1 * dx1 / (dx1*dg1 + dx2 * dg2) - (h11*h11*dg1*dg1 + h12 * h11*dg1*dg2 + h11 * h21*dg1*dg2 + h12 * h21*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h12 = h12 + dx1 * dx2 / (dx1*dg1 + dx2 * dg2) - (h11*h12*dg1*dg1 + h12 * h12*dg1*dg2 + h11 * h22*dg1*dg2 + h12 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h21 = h21 + dx1 * dx2 / (dx1*dg1 + dx2 * dg2) - (h11*h21*dg1*dg1 + h11 * h22*dg1*dg2 + h21 * h21*dg1*dg2 + h21 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h22 = h22 + dx2 * dx2 / (dx1*dg1 + dx2 * dg2) - (h12*h21*dg1*dg1 + h12 * h22*dg1*dg2 + h21 * h22*dg1*dg2 + h22 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		//复杂的H迭代公式
	}
	printf("\n最小值点为(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}