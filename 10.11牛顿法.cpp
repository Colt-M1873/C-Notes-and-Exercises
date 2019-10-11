/* 170603018 �Զ���17-1 ����� */
#include<stdio.h>
#include<stdlib.h>
double fun(double x);
double funDiff1(double x);//����fun��һ�ε���
double funDiff2(double x);//����fun�Ķ��ε���
double Newton(double(*fun)(double), double(*diff1)(double), double(*diff2)(double), double x, double precision);
////*funΪָ��������ĺ���ָ��,*diff1ָ������һ�׵�����*diff2ָ����׵�����xΪ��ʼ�㣬precisionΪ����ֵ
int main()
{
	double result;
	double(*f)(double), (*d1)(double), (*d2)(double);
	f = fun;
	d1 = funDiff1;
	d2 = funDiff2;
	result = Newton(f, d1, d2, 100, 0.01);
	printf("������СֵΪ %f \n��Ӧ��xֵΪ %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 3;
}
double funDiff1(double x)//����fun��һ�׵���
{
	return 2 * x - 6;
}
double funDiff2(double x)//����fun�Ķ��׵���
{
	return 2;
}

double Newton(double(*fun)(double), double(*diff1)(double), double(*diff2)(double), double x,double precision)
{
	while ((*diff1)(x) > precision || (*diff1)(x) < precision*(-1))//�ж��Ƿ񵽴ﾫ��ֵ 
	{
		x = x - (*diff1)(x) / (*diff2)(x);
	}
	return x;
}
