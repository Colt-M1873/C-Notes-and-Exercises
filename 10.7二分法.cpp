/*170603108 �Զ���17-1 �����*/
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//��Ϊ����ȡ�ĺ���
double Half(double(*fun)(double), double left, double right, double precision, double lastLength);
//*funΪָ��������ĺ���ָ��,nΪ�����ִΣ�left right Ϊ����˵�,
//precisionΪ����ֵ�ţ�lastLengthΪ�������䳤��,lastLength��ֵ�����precision

int main()
{
	double result;
	double(*f)(double);
	f = fun;
	result = Half(f, -1, 10, 0.01, 0.1);
	printf("������СֵΪ %f \n��Ӧ��xֵΪ %f", fun(result), result);
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