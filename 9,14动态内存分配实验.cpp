//���к�ɿ����ڴ�ʹ�������ܳ������ߵľ����
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
int main() {
	int a, *p, i;
	while (1)
	{
		system("pause");
		for (i = 0; i <= 12;i++)
		{
			Sleep(800);
			p = (int *)malloc(i * 100000000);
			Sleep(800);
			free(p);
		}
	}
}