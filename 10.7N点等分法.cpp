/*170603108 �Զ���17-1 �����*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);
double nDotDivide(double(*fun)(double), int n, double left, double right, double precision);

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = nDotDivide(f, 3, -1, 20, 0.01);
	printf("%f", result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double nDotDivide(double (*fun)(double), int n,double left, double right, double precision)
{
	//*funΪָ��������ĺ���ָ�룬nΪ�ȷֵ�����left rightΪ��������˵㣬precisionΪ����ֵ
	double xn[20],fmin;
	int nmin;
	while (right - left > precision)
	{
		fmin = (*fun)(left);
		nmin = 0;
		for (int i = 0; i <= n + 1; i++)
		{
			xn[i] = left + i * (right - left) / (n+1);//����xn��ǰn+2�������Ǵ洢�İ����������ڵ�ÿһ�����xֵ
			if ((*fun)(xn[i]) < fmin)
			{
				fmin = (*fun)(xn[i]);//����С����ֵ
				nmin = i;//��С����ֵ��Ӧ��xn�����±�
			}
		}
		left = xn[nmin - 1];//��������
		right = xn[nmin + 1];//
	}
	return 0.5*(left + right);//����ֵΪ��С�����е��xֵ
}