/*����Ϸ����һ��ͭ��װ���ϣ���������(���A��B��C)����A�����¶��ϡ��ɴ�С��˳�����n������(����ͼ)����Ϸ��Ŀ�꣺��A���ϵĽ���ȫ���Ƶ�C���ϣ����Ա���ԭ��˳����á���������ÿ��ֻ���ƶ�һ�����ӣ��������ƶ��������������϶�ʼ�ձ��ִ������£�С�����ϣ��������������ӿ�������A��B��C��һ���ϡ�*/
/* ����ȴ��ƶ���Բ�̸���n�����ÿһ�����ܹ���Ҫ�ƶ��Ĵ���*/
/*
�ݹ�ĵ䷶���ҵ����ɣ��Ѵ����⿴��������С�����ĵ���
��˼��Ϊ����a��b�ƶ�n��Բ�̵�����ֽ�Ϊ��
1����a���Ӱ�n-1��Բ���ƶ���c�����ϣ�
2����a�����һ��Բ���ƶ���b�����ϣ�
3����c�ϵ�n-1��Բ���ƶ���b
��ƺ�����Ϊint Hanoi(int n,char a,char b,char c);����n��Բ�̴�����1�ƶ�������2���м��������3
*/
#include<stdio.h>
#include<stdlib.h>

void Hanoi(int n, char a, char b, char c);
void Move(char a, char b);
static int sum = 0;//static�����˸�ȫ�ֱ������������ڴ��ļ��ڲ�

int main()
{
	int n;
	while (true)
	{
		sum = 0;
		printf("Input:");
		scanf_s("%d", &n);
		Hanoi(n, 'a', 'b', 'c');
		printf("Total move:%d\n", sum);
		system("pause");
	}
}

void Hanoi(int n, char a, char b, char c) {
	if (n > 1)
	{
		Hanoi(n - 1, a, c, b);//��һ��
		Move(a, b);//�ڶ���
		Hanoi(n - 1, c, b, a);//������
	}
	else if (n == 1)
		Move(a, b);
}

void Move(char a, char b)
{
	printf("%c -> %c\n", a, b);
	sum++;
}