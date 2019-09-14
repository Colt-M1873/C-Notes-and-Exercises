//相当无趣，百鸡百钱的简化版，红3白5黑6，取8个，要求其中必有红球和白球，列出所有情况

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