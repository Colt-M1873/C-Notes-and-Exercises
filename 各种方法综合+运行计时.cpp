/*170603108 自动化17-1 杨佳男*/
//失败，调用time库无法计算1毫秒以下的时间
//该程序为四种求极值方法的综合，并且加入运行计时可显示各种方法计算消耗的时间
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
double fun(double x);//此为待求取的函数

double Half(double(*fun)(double), double left, double right, double precision, double lastLength);
//二分法：*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,
//precision为精度值ε，lastLength为最终区间长度,lastLength的值需大于precision

double nDotDivide(double(*fun)(double), int n, double left, double right, double precision);
//N点等分法：*fun为指向待求函数的函数指针，n为等分点数，left right为搜索区间端点，precision为精度值

double Fibonacci(double(*fun)(double), int n, double left, double right);
//斐波那契法：*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点

double Golden(double(*fun)(double), double left, double right, double precision);
//0.618法：*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,precision为精度值

int main()
{
	clock_t startHalf, endHalf, startnDot, endnDot, startFib, endFib, startGold, endGold;
	double resultHalf, resultnDot, resultFib, resultGold;
	double(*f)(double);
	f = fun;
	startHalf = clock();//执行到这一句前程序运行的时间
	resultHalf = Half(f, -1, 20, 0.001, 0.01);
	endHalf = clock();
	printf("二分法：\n函数最小值为 %f \n对应的x值为 %f\n运行时间为%f\n", fun(resultHalf), resultHalf, (double)(endHalf - startHalf)/* / CLOCKS_PER_SEC*/);

	startnDot = clock();
	resultnDot = nDotDivide(f, 3, -1, 20, 0.01);
	endnDot = clock();
	printf("\nN点等分法：\n函数最小值为 %f \n对应的x值为 %f\n运行时间为%f\n", fun(resultnDot), resultnDot, (double)(endnDot - startnDot));

	startFib = clock();
	resultFib = Fibonacci(f, 46, -1, 20);
	endFib = clock();
	printf("\n斐波那契法：\n函数最小值为 %f \n对应的x值为 %f\n运行时间为%f\n", fun(resultFib), resultFib, (double)(endFib - startHalf));

	startGold = clock();
	resultGold = Golden(f, -1, 20, 0.00003);
	endGold = clock();
	printf("\n0.618法：\n函数最小值为 %f \n对应的x值为 %f\n运行时间为%f\n", fun(resultGold), resultGold, (double)(endGold - startGold));

	system("pause");
}

double fun(double x)
{
	return x * x - 6 * x + 9;
}


double Half(double(*fun)(double), double left, double right, double precision, double lastLength)
{
	//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,precision为精度值ε，lastLength为最终区间长度
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
	//*fun为指向待求函数的函数指针，n为等分点数，left right为搜索区间端点，precision为精度值
	double xn[20], fmin;
	int nmin;
	while (right - left > precision)
	{
		fmin = (*fun)(left);
		nmin = 0;
		for (int i = 0; i <= n + 1; i++)
		{
			xn[i] = left + i * (right - left) / (n + 1);//现在xn中前n+2个数就是存储的包括两端在内的每一个点的x值
			if ((*fun)(xn[i]) < fmin)
			{
				fmin = (*fun)(xn[i]);//找最小函数值
				nmin = i;//最小函数值对应的xn数组下标
			}
		}
		left = xn[nmin - 1];//更新区间
		right = xn[nmin + 1];//
	}
	return 0.5*(left + right);//返回值为最小区间中点的x值
}

double Fibonacci(double(*fun)(double), int n, double left, double right)
{
	//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点
	double fib[50];//斐波那契数列
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
	return 0.5*(left + right);//返回值为最小区间中点的x值
}

double Golden(double(*fun)(double), double left, double right, double precision)
{
	//*fun为指向待求函数的函数指针,n为计算轮次，left right 为区间端点,precision为精度值
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

