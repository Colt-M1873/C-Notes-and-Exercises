/*����һ��1900-2200֮�����ݣ�
�ж���һ���ǲ�������,���������yes,���������no
�����ж�������
1��������4�Ҳ�������100 
2��������400
������벻�Ϸ������error*/

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