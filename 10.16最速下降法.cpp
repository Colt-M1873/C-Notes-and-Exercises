/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
/*ֻҪԤ���ṩԭ�������ݶȺ�������������κ�������Сֵ��
fx������Ϊһģ�壬����Ӧ���ԸĽ���ʡ��*/
double fun(double x1, double x2);
double funGrad(double x1, double x2, double &g1, double &g2);//����fun���ݶ�
double fx(double t0, double x1, double x2, double g1, double g2);//Ӧ�Ľ���ʡ��fx
double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double(*fxt)(double, double, double, double, double), double x1, double x2, int n);

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&), (*fai)(double, double, double, double, double);
	f = fun;
	g = funGrad;
	fai = fx;
	result = GradientDescend(f, g, fai, 1, 1, 5);
	printf("������СֵΪ %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return x1 * x1 + 4 * x2*x2 + 3;
}
double funGrad(double x1, double x2, double &g1, double &g2)//����fun���ݶ�
{
	g1 = 2 * x1;//�˴�g1g2ʹ�����÷�ʽ���ݲ��������˷���ֵ����һ��������
	g2 = 8 * x2;
	return  0;
}
double fx(double t0, double x1, double x2, double g1, double g2) {
	//fxΪt�ĺ��������ڽ���һά����������ʵ�tֵ
	return (x1 + t0 * g1)*(x1 + t0 * g1) + 4 * (x2 + t0 * g2)*(x2 + t0 * g2);
}

double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double(*fxt)(double, double, double, double, double), double x1, double x2, int n)
{
	//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����(*fxt)ָ��һά����t�ĺ���ģ�壬x1,x2Ϊ��ʼ�㣬nΪ��������
	double g1, g2, t0;//t0Ϊ���Ų���
	for (int i = 0; i < n; i++)
	{
		(*Grad)(x1, x2, g1, g2);
		double t1, t2, left = -100, right = 100, precision = 0.0001;//��Щ��������һά����
		while (right - left > precision)//�˴�ʹ��0.618��һά���������t0,��ʼ����Ϊ��-100��100������Ϊ0.01
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			if ((*fxt)(t1, x1, x2, g1, g2) < (*fxt)(t2, x1, x2, g1, g2))
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//һά���������õ�t0
		x1 = x1 + t0 * g1;
		x2 = x2 + t0 * g2;//����µ�x1��x2ֵ
	}
	return (*fun)(x1, x2);
	//return t0;//���ڲ���t0���в�����

}


