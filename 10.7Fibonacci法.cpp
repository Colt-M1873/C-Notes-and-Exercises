/*170603108 �Զ���17-1 �����*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//��Ϊ����ȡ�ĺ���
double Fibonacci(double(*fun)(double), int n, double left, double right);
//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Fibonacci(f, 6, -1, 20);
	printf("������СֵΪ %f \n��Ӧ��xֵΪ %f", fun(result), result);
	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}

double Fibonacci(double(*fun)(double),int n, double left, double right)
{
	//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�
	double fib[50];//쳲���������
	double x1, x2;
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int j = 0; j < n; j++)
	{
		x1 = left + fib[n - 2] / fib[n] * (right - left);
		x2 = left + fib[n - 1] / fib[n] * (right - left);
		if ((*fun)(x1) < (*fun)(x2))
			right = x2;
		else
			left = x1;
	}
	return 0.5*(left + right);//����ֵΪ��С�����е��xֵ
}
