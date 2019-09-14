#include<stdio.h>
#include<stdlib.h>
int factorial(int a);
int main() {
	while (true)
	{
		int a, b;
		scanf_s("%d", &a);
		printf("%d\n", factorial(a));
	}	
}
int factorial(int a) {
	if (a == 1 || a == 0)
		return 1;
	else
		return a * factorial(a - 1);
}




