/*170603108 �Զ���17-1 �����*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//��Ϊ����ȡ�ĺ���
double Golden(double(*fun)(double), double left, double right, double precision);
//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,precisionΪ����ֵ

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Golden(f, -1, 10, 0.003);
	printf("������СֵΪ %f \n��Ӧ��xֵΪ %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double Golden(double(*fun)(double), double left, double right, double precision)
{
	//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,precisionΪ����ֵ
	double x1, x2;
	while (right - left > precision)
	{
		x1 = left + 0.382 * (right - left);
		x2 = left + 0.618 * (right - left);
		if ((*fun)(x1) < (*fun)(x2))
			right = x2;
		else
			left = x1;
	}
	return 0.5*(left + right);
}