/*题目内容：
回文测试：输入一30个字符以内的字符串，判断是否为回文；如果是，则打印"true"；否则打印"false"。像"aba"这样的从左往右读与从右往左读一致就是回文。
输入样例1：
ayzya
输出样例1：
true
输入样例2：
ayzy
输出样例2：
false*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str1[30];
	int i = 0, j = 0,flag=1;
	gets_s(str1,30);
//	for (i = 0; str1[i] != '\0'; i++);//此方法与下文的strlen()函数功能相同，均为计算有效字符长度，只是不需要调用string.h库
	i = strlen(str1);
//	printf("%d",i);//此时i为输入字符的个数
	i -= 1;//此时i为字符数组最后一位的下标
	//如果输入字符个数为奇数，如5个，则现在i=4，i/2=2，下文的j<i/2正好忽略对称中心的那个字符，只计算前两个和后两个
	//如果输入有偶数个数，如6个，则现在i=5，i/2=2.5，以此为分界，正好计算第0，1，2前三位和3，4，5后三位
	for (j = 0; j < i / 2; j++)
	{
		if (str1[j] != str1[i - j])
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		printf("true");
	else
		printf("false");
	system("pause");
}