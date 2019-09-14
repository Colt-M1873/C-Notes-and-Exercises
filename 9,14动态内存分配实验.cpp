//运行后可看到内存使用曲线跑出逐渐升高的锯齿形
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