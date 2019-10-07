/*170603108 �Զ���17-1 �����*/
//ʧ�ܣ�����time���޷�����1�������µ�ʱ��
//�ó���Ϊ������ֵ�������ۺϣ����Ҽ������м�ʱ����ʾ���ַ����������ĵ�ʱ��
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//��Ϊ����ȡ�ĺ���

double Half(double(*fun)(double), double left, double right, double precision, double lastLength);
//���ַ���*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,
//precisionΪ����ֵ�ţ�lastLengthΪ�������䳤��,lastLength��ֵ�����precision

double nDotDivide(double(*fun)(double), int n, double left, double right, double precision);
//N��ȷַ���*funΪָ��������ĺ���ָ�룬nΪ�ȷֵ�����left rightΪ��������˵㣬precisionΪ����ֵ

double Fibonacci(double(*fun)(double), int n, double left, double right);
//쳲���������*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�

double Golden(double(*fun)(double), double left, double right, double precision);
//0.618����*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,precisionΪ����ֵ

int main()
{
	clock_t startHalf, endHalf, startnDot, endnDot, startFib, endFib, startGold, endGold;
	double resultHalf, resultnDot, resultFib, resultGold;
	double(*f)(double);
	f = fun;
	startHalf = clock();//ִ�е���һ��ǰ�������е�ʱ��
	resultHalf = Half(f, -1, 20, 0.001, 0.01);
	endHalf = clock();
	printf("���ַ���\n������СֵΪ %f \n��Ӧ��xֵΪ %f\n����ʱ��Ϊ%f\n", fun(resultHalf), resultHalf, (double)(endHalf - startHalf)/* / CLOCKS_PER_SEC*/);

	startnDot = clock();
	resultnDot = nDotDivide(f, 3, -1, 20, 0.01);
	endnDot = clock();
	printf("\nN��ȷַ���\n������СֵΪ %f \n��Ӧ��xֵΪ %f\n����ʱ��Ϊ%f\n", fun(resultnDot), resultnDot, (double)(endnDot - startnDot));

	startFib = clock();
	resultFib = Fibonacci(f, 46, -1, 20);
	endFib = clock();
	printf("\n쳲���������\n������СֵΪ %f \n��Ӧ��xֵΪ %f\n����ʱ��Ϊ%f\n", fun(resultFib), resultFib, (double)(endFib - startHalf));

	startGold = clock();
	resultGold = Golden(f, -1, 20, 0.00003);
	endGold = clock();
	printf("\n0.618����\n������СֵΪ %f \n��Ӧ��xֵΪ %f\n����ʱ��Ϊ%f\n", fun(resultGold), resultGold, (double)(endGold - startGold));

	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}


double Half(double(*fun)(double), double left, double right, double precision, double lastLength)
{
	//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,precisionΪ����ֵ�ţ�lastLengthΪ�������䳤��
	double middle, x1, x2;
	while (right - left > lastLength)
	{
		middle = 0.5*(right + left);
		x1 = middle - 0.5*precision;
		x2 = middle + 0.5*precision;
		if ((*fun)(x1) < (*fun)(x2))
			right = x2;
		else
			left = x1;
	}
	return 0.5*(left + right);
}

double nDotDivide(double(*fun)(double), int n, double left, double right, double precision)
{
	//*funΪָ��������ĺ���ָ�룬nΪ�ȷֵ�����left rightΪ��������˵㣬precisionΪ����ֵ
	double xn[20], fmin;
	int nmin;
	while (right - left > precision)
	{
		fmin = (*fun)(left);
		nmin = 0;
		for (int i = 0; i <= n + 1; i++)
		{
			xn[i] = left + i * (right - left) / (n + 1);//����xn��ǰn+2�������Ǵ洢�İ����������ڵ�ÿһ�����xֵ
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

double Fibonacci(double(*fun)(double), int n, double left, double right)
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

