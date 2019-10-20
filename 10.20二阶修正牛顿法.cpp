/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
//��Ϊ��������ţ�ٷ�
/*Ԥ���ṩԭ�������ݶȺ�����Hessin������������Ԫ��������Сֵ*/
double fun(double x1, double x2);//����ĺ���
double funGrad(double x1, double x2, double &g1, double &g2);//����fun���ݶ�
double funHessin(double x1, double x2, double &h11, double &h12, double &h21, double &h22);//����fun��Hessin����
double ModifiedNewtown(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double(*Hessin)(double, double, double&, double&, double&, double&), double x1, double x2, int n);
//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����(*Hessin)ָ��Hessin����x1,x2Ϊ��ʼ�㣬nΪ��������

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&),(*h)(double, double, double&, double&, double&, double&);
	f = fun;
	g = funGrad;
	h = funHessin;//������Ӧ�ĺ���ָ��
	result = ModifiedNewtown(f, g, h, 0, 1, 2);
	printf("������СֵΪ %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return (x1 - 1)*(x1 - 1)*(x1 - 1)*(x1 - 1) +  x2*x2 ;
}
double funGrad(double x1, double x2, double &g1, double &g2)//����fun���ݶ�
{
	g1 = 4 * x1* x1* x1 - 12 * x1* x1 + 12 * x1 - 4;//�˴�g1g2ʹ�����÷�ʽ���ݲ��������˷���ֵ����һ��������
	g2 = 2 * x2;
	return  0;
}
double funHessin(double x1, double x2, double &h11, double &h12, double &h21, double &h22)//����fun��Hessin����
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
	//t0Ϊһά�����ó������Ų�����DetΪHessin���������ʽ��ֵ��invΪ�����
	for (int i = 0; i < n; i++) 
	{
		(*Grad)(x1, x2, g1, g2);
		(*Hessin)(x1, x2, h11, h12, h21, h22);
		Det = h11 * h22 - h12 * h21;
		inv11 = h22 / Det;
		inv12 = -h12 / Det;
		inv21 = -h21 / Det;
		inv22 = h11 / Det;//�����Ĳ�Ϊ�������
		double t1, t2, left = -100, right = 100, precision = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//��Щ��������һά����,x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t1�ĺ�����(t1)��x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t2�ĺ�����(t2)
		while (right - left > precision)//�˴�ʹ��0.618��һά���������t0,��ʼ����Ϊ��-100��100������Ϊ0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * (inv11*g1 + inv12 * g2);//1
			x2t1 = x2 - t1 * (inv21*g1 + inv22 * g2);//2
			x1t2 = x1 - t2 * (inv11*g1 + inv12 * g2);//3
			x2t2 = x2 - t2 * (inv21*g1 + inv22 * g2);//4�����ľ佫��Ԫ����funת��Ϊ����t��һά��������������
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)����(t1),(*fun)(x1t2, x2t2)����(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//һά���������õ�t0
		x1 = x1 - t0 * (inv11*g1 + inv12 * g2);
		x2 = x2 - t0 * (inv21*g1 + inv22 * g2);
		printf("��%d�ε����õ��ĵ�Ϊ(%f,%f)�����Ų���tΪ%f\n", i + 1, x1, x2, t0);
	}
	printf("\n��Сֵ��Ϊ(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}