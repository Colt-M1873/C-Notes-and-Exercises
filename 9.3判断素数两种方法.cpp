/*写出100以内所有素数*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, c,flag=0;
	for (i = 2; i <= 100; i++)
	{
		for (c = 2; c < i; c++)
		{
			if (i%c == 0)
				flag = 1;
		}
		if (flag == 0)
			printf("%d ", i);
		else
			flag = 0;
	}
//	system("pause");
}
//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int flag[100] = { 0 }, i = 2, c = 0;
//	for (i = 2; i < 10; i++)
//	{
//		if (flag[i] == 0)
//		{
//			for (c = i * 2; c <= 100; c += i)
//			{
//				flag[c] = 1;
//			}
//		}	
//	}
//	for (i = 2; i < 100; i++)
//	{
//		if (flag[i] == 0)
//			printf("%d ", i);
//	}
//}
