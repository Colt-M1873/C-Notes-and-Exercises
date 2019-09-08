/*编写程序判断string1中是否含有string2，如果包含，则输出每个string2在string1中的首字母的位置，如果不包含输出NO*/
//遇到问题1：str2在str1末尾时识别出问题
//2：字符串出现回文或顶真情况时判断出错，这个问题相当隐蔽，不易被考虑到

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i = 0, len2, len1, pos = 0, flag = 0;
	char  str1[50], str2[50], *p1 = NULL, *p2 = NULL;
	gets_s(str1, 50);
	gets_s(str2, 50);
	p1 = str1;
	p2 = str2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	while (*p1 != '\0')
	{
		if (*p1 == str2[0])
		{
			while (*p1 == *p2&&*p1 != '\0')//其中p1!='\0'是为了防止在两个字符串均到达末尾时发生'\0'='\0'的现象导致计数错误，无法识别str2出现在str1尾部的情况
			{
				p1++;
				p2++;
				i++;
				pos++;
			}
		}
		else
		{
			p1++;
			pos++;
		}
		if (i == len2)
		{
			printf("yes %d", pos - len2);
			flag = 1;
			pos = pos - len2 + 1;//（1）
			p1 = p1 - len2 + 1;//（2）   （1），（2）这两句话是在每次识别出一个匹配str2的段落后，不直接从这个段落末尾往下判断，而是回到段落开头第二个字符再继续，防止顶真字符串的存在，例如str1=adadada str2=ada 这种情况下str1实际上包含3个str2，如果没有这两句话则会判定为两个
		}
		i = 0;
		p2 = str2;
	}
	if (!flag)
		printf("NO");
	system("pause");
}