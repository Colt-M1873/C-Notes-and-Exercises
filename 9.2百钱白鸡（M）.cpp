/*һֻ����ֵ5Ǯ��
һֻĸ��ֵ3Ǯ��
��ֻС��ֵ1Ǯ��
�����ð�Ǯ��ټ���
���ʹ�����ĸ����С��������ֻ��
�о����п���,�ӹ�����ĿС��������,������ͬ����ĸ������˳�򣬹���ĸ������ͬ������С������˳��
������:
a,b,c
d,e,f
.....
(a,d...��Ӧ��������,b,e...��Ӧĸ������,c,f...��ӦС������)*/
#include<stdio.h>
#include<stdlib.h>
int main()
{    //һ����λ��chick��ʾ��ֻС��
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
					break;//�˴����һ��break�󣬷��������г�������ʱ���С����֮ǰ��5/7��OJ��ռ���ڴ��֮ǰ��372k��С��256k
				}
			}
		}
	}
//	system("pause");
}