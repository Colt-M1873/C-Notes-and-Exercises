/*只改变指针的指向，不改变原变量存储的位置*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
		int a, b, *p1 = &a, *p2 = &b, *p3 = NULL;
		scanf_s("%d %d", &a, &b);
		if (a > b)
		{
			p3 = p1;
			p1 = p2;
			p2 = p3;
		}
		printf("%d %d", *p1, *p2);
	system("pause");
}