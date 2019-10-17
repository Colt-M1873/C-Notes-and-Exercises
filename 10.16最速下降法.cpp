/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
/*ֻ��Ԥ���ṩԭ�������ݶȺ�������������κ�������Сֵ��*/
double fun(double x1, double x2);//����ĺ���
double funGrad(double x1, double x2, double &g1, double &g2);//����fun���ݶ�
double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&),double x1, double x2, int n);
//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����(*fxt)ָ��һά����t�ĺ���ģ�壬x1,x2Ϊ��ʼ�㣬nΪ��������

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;
	result = GradientDescend(f, g, 1, 1, 5);
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

double GradientDescend(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, int n)
{
	//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����(*fxt)ָ��һά����t�ĺ���ģ�壬x1,x2Ϊ��ʼ�㣬nΪ��������
	double g1, g2, t0;//t0Ϊ���Ų���
	for (int i = 0; i < n; i++)
	{
		(*Grad)(x1, x2, g1, g2);
		double t1, t2, left = -100, right = 100, precision = 0.00001,x1t1, x2t1, x1t2, x2t2;
		//��Щ��������һά����,x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t1�ĺ�����x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t2�ĺ���
		while (right - left > precision)//�˴�ʹ��0.618��һά���������t0,��ʼ����Ϊ��-100��100������Ϊ0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * g1;
			x2t1 = x2 - t1 * g2;
			x1t2 = x1 - t2 * g1;
			x2t2 = x2 - t2 * g2;//���ľ佫��Ԫ����funת��Ϊ����t1��t2��һά��������������
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//һά���������õ�t0
		x1 = x1 - t0 * g1;
		x2 = x2 - t0 * g2;//����µ�x1��x2ֵ
	}
	return (*fun)(x1, x2);
	//return t0;//���ڲ���t0���в�����
}


