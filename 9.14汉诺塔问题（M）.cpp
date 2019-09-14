/*该游戏是在一块铜板装置上，有三根杆(编号A、B、C)，在A杆自下而上、由大到小按顺序放置n个金盘(如下图)。游戏的目标：把A杆上的金盘全部移到C杆上，并仍保持原有顺序叠好。操作规则：每次只能移动一个盘子，并且在移动过程中三根杆上都始终保持大盘在下，小盘在上，操作过程中盘子可以置于A、B、C任一杆上。*/
/* 输入等待移动的圆盘个数n，输出每一步和总共需要移动的次数*/
/*
递归的典范，找到规律，把大问题看成无数个小操作的叠加
其思想为将从a到b移动n个圆盘的问题分解为：
1、从a柱子把n-1个圆盘移动到c柱子上，
2、把a上最后一个圆盘移动到b柱子上，
3、把c上的n-1个圆盘移动回b
设计函数即为int Hanoi(int n,char a,char b,char c);即把n个圆盘从柱子1移动到柱子2，中间借助柱子3
*/
#include<stdio.h>
#include<stdlib.h>

void Hanoi(int n, char a, char b, char c);
void Move(char a, char b);
static int sum = 0;//static限制了该全局变量的作用域在此文件内部

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
		Hanoi(n - 1, a, c, b);//第一步
		Move(a, b);//第二步
		Hanoi(n - 1, c, b, a);//第三步
	}
	else if (n == 1)
		Move(a, b);
}

void Move(char a, char b)
{
	printf("%c -> %c\n", a, b);
	sum++;
}