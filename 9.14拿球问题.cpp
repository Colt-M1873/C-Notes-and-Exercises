//�൱��Ȥ���ټ���Ǯ�ļ򻯰棬��3��5��6��ȡ8����Ҫ�����б��к���Ͱ����г��������

#include<stdlib.h>
#include<stdio.h>
int main() {
	int white, red, black;
	for (red = 1; red <= 3; red++)
	{
		for (white = 1; white <= 5; white++)
		{
			for (black = 0; black <= 6; black++)
			{
				if (black + white + red == 8)
					printf("red %d  white %d  black %d \n", red, white, black);
				else
				{
					continue;
				}
			}

		}
	}
	system("pause");
}