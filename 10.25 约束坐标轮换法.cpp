/*170603108 �Զ���17-1 �����*/
#include <stdio.h>
#include <stdlib.h>
//��ΪԼ�������ֻ���
/*Ԥ���ṩԭ������Լ���������������Ԫ��������Сֵ*/
//�����ƣ�ֻ�ܵ������Σ�ԭ��δ֪����ȱ�ٸ��������ݣ�����ֻ��������������������
double fun(double x1, double x2);//����ĺ���
double Restriction(double x1, double x2);//Լ������
double UnivariationSearch(double(*fun)(double, double), double(*Restriction)(double, double), double x1, double x2, double t0, double precision);
//(*fun)Ϊָ���������ָ�룬(*Restriction)ָ��Լ������������x1,x2Ϊ��ʼ�㣬t0Ϊ��ʼ������precisionΪ����

int main()
{
	double result;
	double(*f)(double, double), (*res)(double, double);
	f = fun;
	res = Restriction;//������Ӧ�ĺ���ָ��
	result = UnivariationSearch(f, res, 1, 1, 0.5, 0.1);
	printf("������СֵΪ %f", result);
	system("pause");
}

double fun(double x1, double x2)//����⺯��
{
	return x1 * x1 + 2 * x2*x2 - 4 * x1 - 8 * x2 + 15;
}
double Restriction(double x1, double x2)//Լ������
{
	double g1, g2, g3;
	g1 = 9 - x1 * x1 - x2 * x2;
	g2 = x1;
	g3 = x2;
	if (g1 >= 0 && g2 >= 0 && g3 >= 0)
		return  1;
	else
		return 0;
}

double UnivariationSearch(double(*fun)(double, double), double(*Restriction)(double, double), double x1, double x2, double t0, double precision)
{
	//(*fun)Ϊָ���������ָ�룬(*Restriction)ָ��Լ������������x1,x2Ϊ��ʼ�㣬t0Ϊ��ʼ������precisionΪ����
	double  t;
	int i=0, j=0;//���ڼ���
	if ((*Restriction)(x1, x2)) {
		while (t0 >= precision) {
			if ((*fun)(x1 + t0, x2) < (*fun)(x1, x2) && (*Restriction)(x1 + t0, x2)) {
				//�˴�if��Ϊ�ж��ܷ�����x1����������һ��
				t = t0;
				while ((*fun)(x1 + 2 * t, x2) < (*fun)(x1 + t, x2) && (*Restriction)(x1 + 2 * t, x2)) {
					t = 2 * t;//����x1�����ߵ���������
				}
				x1 += t;
				++i;
				printf("��x1�����%d�ε����õ��ĵ�Ϊ(%f,%f)�����Ų���tΪ%f\n", i, x1, x2, t);
			}
			else if ((*fun)(x1, x2 + t0) < (*fun)(x1, x2) && (*Restriction)(x1, x2 + t0)) {
				//�˴�if��Ϊ�ж��ܷ�����x2����������һ��
				t = t0;
				while ((*fun)(x1, x2 + 2 * t) < (*fun)(x1, x2 + t) && (*Restriction)(x1, x2 + 2 * t)) {
					t = 2 * t;//����x2�����ߵ���������
				}
				x2 += t;
				++j;
				printf("��x2�����%d�ε����õ��ĵ�Ϊ(%f,%f)�����Ų���tΪ%f\n", j, x1, x2, t);
			}
			else {//�����������������ǰ��
				t0 = t0 / 2;
			}
		}
	}
	else{
		printf("��ʼ����Ч");
	}
	printf("\n��Сֵ��Ϊ(%f,%f)\n", x1, x2);
	return (*fun)(x1, x2);
}