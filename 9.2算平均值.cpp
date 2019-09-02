// 9.2算平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
//#include <stdlib>


int main()
{
	float tdapple = 2, money, total = 2;
	int day = 1, inputday;
	scanf_s("%d",&inputday);
	while (day<inputday)
	{
		day++;
		tdapple = tdapple * 2;
		total = total + tdapple;
	}
	money = total * 0.8 ;
	std::cout << money ;
	system("pause");
}

