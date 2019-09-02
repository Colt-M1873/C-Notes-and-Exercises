/*一只公鸡值5钱，
一只母鸡值3钱，
三只小鸡值1钱，
现在用百钱买百鸡，
请问公鸡、母鸡、小鸡各多少只？
列举所有可能,从公鸡数目小到大排列,公鸡相同则按照母鸡递增顺序，公鸡母鸡都相同，则按照小鸡递增顺序
输出结果:
a,b,c
d,e,f
.....
(a,d...对应公鸡数量,b,e...对应母鸡数量,c,f...对应小鸡数量)*/
#include<stdio.h>
#include<stdlib.h>
int main()
{    //一个单位的chick表示三只小鸡
	int cock = 0, hen = 0, chick = 0,  total = 0;
	float totalp = 0;
	totalp = cock * 5 + hen * 3 + chick * 1;
	total = cock + hen + chick*3;
	for (cock = 0; cock <= 20; cock++)
	{
		for (hen = 0; hen<= 34; hen++)
		{
			for (chick = 0; chick<= 100; chick++)
			{
				total = cock + hen + chick*3;
				totalp = cock * 5 + hen * 3 + chick * 1;
				if (total == 100 && totalp == 100)
				{
					printf("%d,%d,%d\n", cock, hen, chick * 3);
					break;//此处添加一句break后，分析报告中程序运行时间减小到了之前的5/7，OJ上占用内存从之前的372k减小到256k
				}
			}
		}
	}
//	system("pause");
}