/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*ֻ��Ԥ���ṩԭ�������ݶȺ������������Ԫ��������Сֵ��*/
double fun(double x1, double x2);//����ĺ���
double funGrad(double x1, double x2, double &g1, double &g2);//����fun���ݶ�
double ConjugateGradient(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision);
//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����x1,x2Ϊ��ʼ�㣬precisionΪ����ֵ

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;
	result = ConjugateGradient(f, g, 0, 0, 0.000001);
	printf("������СֵΪ %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return x1 * x1 + 2 * x2 * x2 - 2 * x1 * x2 + 2 * x2 + 2;
}

double funGrad(double x1, double x2, double &g1, double &g2)//����fun���ݶ�
{
	g1 = 2 * x1 - 2 * x2;//�˴�g1g2ʹ�����÷�ʽ���ݲ��������˷���ֵ����һ��������
	g2 = 4 * x2 - 2 * x1 + 2;
	return  0;
}

double ConjugateGradient(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision)
{
	//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����x1,x2Ϊ��ʼ�㣬precisionΪ����ֵ
	int i = 0;//�Ƶ�������
	double g1, g2, Normg, p1=0, p2=0, a=0, t0;//NormgΪ�ݶȵķ���,Pk=(p1,p2)Ϊ��������,t0Ϊһά���������Ų���
	(*Grad)(x1, x2, g1, g2);
	Normg = sqrt(g1*g1 + g2 * g2);
	while (Normg>=precision)
	{
		p1 = -g1 + a * p1;
		p2 = -g2 + a * p2;//�·������ʼʱa=0�ʳ�ʼ����Ϊ���ݶȷ���
		double t1, t2, left = -100, right = 100, precision = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//��Щ��������һά����,x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t1�ĺ�����(t1)��x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t2�ĺ�����(t2)
		while (right - left > precision)//�˴�ʹ��0.618��һά���������t0,��ʼ����Ϊ��-100��100������Ϊ0.00001
		{
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 + t1 * p1;//1
			x2t1 = x2 + t1 * p2;//2
			x1t2 = x1 + t2 * p1;//3
			x2t2 = x2 + t2 * p2;//4�����ľ佫��Ԫ����funת��Ϊ����t1��t2��һά��������������
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)����(t1),(*fun)(x1t2, x2t2)����(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//һά���������õ�t0
		x1 = x1 + t0 * p1;
		x2 = x2 + t0 * p2;//����µ�x1��x2ֵ
		printf("��%d�ε����õ��ĵ�Ϊ(%f,%f)�����Ų���tΪ%f\n", ++i, x1, x2, t0);
		(*Grad)(x1, x2, g1, g2);
		a = (g1*g1 + g2 * g2) / (Normg*Normg);
		Normg= sqrt(g1*g1 + g2 * g2);
	}
	printf("\n��Сֵ��Ϊ(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}


