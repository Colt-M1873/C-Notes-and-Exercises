/*��д�����ж�string1���Ƿ���string2����������������ÿ��string2��string1�е�����ĸ��λ�ã�������������NO*/
//��������1��str2��str1ĩβʱʶ�������
//2���ַ������ֻ��Ļ������ʱ�жϳ�����������൱���Σ����ױ����ǵ�

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
			while (*p1 == *p2&&*p1 != '\0')//����p1!='\0'��Ϊ�˷�ֹ�������ַ���������ĩβʱ����'\0'='\0'�������¼��������޷�ʶ��str2������str1β�������
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
			pos = pos - len2 + 1;//��1��
			p1 = p1 - len2 + 1;//��2��   ��1������2�������仰����ÿ��ʶ���һ��ƥ��str2�Ķ���󣬲�ֱ�Ӵ��������ĩβ�����жϣ����ǻص����俪ͷ�ڶ����ַ��ټ�������ֹ�����ַ����Ĵ��ڣ�����str1=adadada str2=ada ���������str1ʵ���ϰ���3��str2�����û�������仰����ж�Ϊ����
		}
		i = 0;
		p2 = str2;
	}
	if (!flag)
		printf("NO");
	system("pause");
}