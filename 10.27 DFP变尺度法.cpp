/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//��ΪDFP��߶ȷ�,Ԥ���ṩԭ�������ݶȺ������������Ԫ��������Сֵ
double fun(double x1, double x2);//����ĺ���
double funGrad(double x1, double x2, double &g1, double &g2);//����fun���ݶ�
double DFP(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision);
//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����x1,x2Ϊ��ʼ�㣬precisionΪ����

int main()
{
	double result;
	double(*f)(double, double), (*g)(double, double, double&, double&);
	f = fun;
	g = funGrad;//������Ӧ�ĺ���ָ��
	result = DFP(f, g, 20, 11, 0.0000000001);
	printf("������СֵΪ %f", result);
	system("pause");
}

double fun(double x1, double x2)
{
	return (x1 - 1)*(x1 - 1)*(x1 - 1)*(x1 - 1) + x2 * x2;
}
double funGrad(double x1, double x2, double &g1, double &g2)//����fun���ݶ�
{
	g1 = 4 * x1* x1* x1 - 12 * x1* x1 + 12 * x1 - 4;//�˴�g1g2ʹ�����÷�ʽ���ݲ��������˷���ֵ����һ��������
	g2 = 2 * x2;
	return  0;
}

double DFP(double(*fun)(double, double), double(*Grad)(double, double, double&, double&), double x1, double x2, double precision)
{
	//(*fun)Ϊָ���������ָ�룬(*Grad)ָ����������ݶȺ�����x1,x2Ϊ��ʼ�㣬precisionΪ����
	double g1, g2, t0, dx1, dx2, dg1, dg2, g1last, g2last;//g1,g2Ϊ�ݶȣ�t0Ϊһά�����ó������Ų���,dx1,dx2Ϊ��x��dg1��dg2Ϊ��g, g1last,g2last�洢��һ�ε�g���ڼ��㦤g
	double h11 = 1, h12 = 0, h21 = 0, h22 = 1;//h11,h12,h21,h22Ϊ����H������ĸ�Ԫ�أ���ʼΪ��λ����
	int i = 0;//������
	(*Grad)(x1, x2, g1, g2);
	while (1) {//�˴���Ϊ����Ϊ�˼�С�����������������жϷ��ڴ˴������g1 g2���㾫��Ҫ��֮���ٶ����һ��H����
		double t1, t2, left = -100, right = 100, prec = 0.00001, x1t1, x2t1, x1t2, x2t2;
		//��Щ��������һά����,x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t1�ĺ�����(t1)��x1t1,x2t1�ڴ��ص�fun��ʱ�ɵõ�����t2�ĺ�����(t2)
		while (right - left > prec) {//�˴�ʹ��0.618��һά���������t0,��ʼ����Ϊ��-100��100������Ϊ0.00001
			t1 = left + 0.382 * (right - left);
			t2 = left + 0.618 * (right - left);
			x1t1 = x1 - t1 * (h11*g1 + h12 * g2);//1
			x2t1 = x2 - t1 * (h21*g1 + h22 * g2);//2
			x1t2 = x1 - t2 * (h11*g1 + h12 * g2);//3
			x2t2 = x2 - t2 * (h21*g1 + h22 * g2);//4�����ľ佫��Ԫ����funת��Ϊ����t��һά��������������
			if ((*fun)(x1t1, x2t1) < (*fun)(x1t2, x2t2))//(*fun)(x1t1, x2t1)����(t1),(*fun)(x1t2, x2t2)����(t2)
				right = t2;
			else
				left = t1;
		}
		t0 = 0.5*(left + right);//һά���������õ�t0
		x1 = x1 - t0 * (h11*g1 + h12 * g2);
		x2 = x2 - t0 * (h21*g1 + h22 * g2);
		g1last = g1;
		g2last = g2;
		i++;
		printf("��%d�ε����õ��ĵ�Ϊ(%f,%f)�����Ų���tΪ%f\n", i, x1, x2, t0);
		(*Grad)(x1, x2, g1, g2);
		if (sqrt(g1*g1 + g2 * g2) < precision)		{//��ѭ����ֹ�������ڴ˴��ɼ�С��������һ��g1 g2����Ҫ����������ֹѭ������������һ����H����ĸ�������
			break;
		}
		dx1 = -t0 * (h11*g1 + h12 * g2);
		dx2 = -t0 * (h21*g1 + h22 * g2);//��x
		dg1 = g1 - g1last;
		dg2 = g2 - g2last;//��g
		h11 = h11 + dx1 * dx1 / (dx1*dg1 + dx2 * dg2) - (h11*h11*dg1*dg1 + h12 * h11*dg1*dg2 + h11 * h21*dg1*dg2 + h12 * h21*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h12 = h12 + dx1 * dx2 / (dx1*dg1 + dx2 * dg2) - (h11*h12*dg1*dg1 + h12 * h12*dg1*dg2 + h11 * h22*dg1*dg2 + h12 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h21 = h21 + dx1 * dx2 / (dx1*dg1 + dx2 * dg2) - (h11*h21*dg1*dg1 + h11 * h22*dg1*dg2 + h21 * h21*dg1*dg2 + h21 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		h22 = h22 + dx2 * dx2 / (dx1*dg1 + dx2 * dg2) - (h12*h21*dg1*dg1 + h12 * h22*dg1*dg2 + h21 * h22*dg1*dg2 + h22 * h22*dg2*dg2) / (dg1*dg1*h11 + dg1 * dg2*h21 + dg1 * dg2*h12 + dg2 * dg2*h22);
		//���ӵ�H������ʽ
	}
	printf("\n��Сֵ��Ϊ(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}