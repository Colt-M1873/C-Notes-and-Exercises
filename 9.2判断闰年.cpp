/*输入一个1900-2200之间的年份，
判断这一年是不是闰年,是闰年输出yes,不是则输出no
闰年判断条件：
1、能整除4且不能整除100 
2、能整除400
如果输入不合法，输出error*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year, check;
	check = scanf_s("%d", &year);
	if (check == 1 && year >= 1900 && year <= 2200)
	{
		if (((year % 100) && (!(year % 4))) ||(!(year % 400)))
			printf("yes");
		else
			printf("no");
	}
	else
		printf("error");
	system("pause");
}