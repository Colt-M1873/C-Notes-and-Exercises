#include<stdio.h>
#include<stdlib.h>
/*
int main()
{
	int a = 1, *p = &a, **q = &p;
	printf("q=%d\n", q);
	printf("*q=%d\n", *q);
	printf("p=%d\n", p);
	printf("*p=%d\n", *p);
	printf("**q=%d\n", **q);
	system("pause");
}
*/

int main()
{
	char str[5] = "fuck";
	char *p = str;
	printf("%c", str[1000]);
	system("pause");



}