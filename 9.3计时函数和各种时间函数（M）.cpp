//��time.h��
//
//clock_t �Ǵ洢������ʱ������ͣ�����Ϊunsigned long�������ڼ����������ʱ��
//time_t  �Ǵ洢����ʱ������ͣ���ʾ��ĳһʱ��㣨1970��1��1�գ�֮�����ھ�����������
//struct tm  ����������ʱ������ڵĽṹ*
//struct tm
//{
//int tm_sec;  /*�룬������Χ0-59�� ��������61*/
//int tm_min;  /*���ӣ�0-59*/
//int tm_hour; /*Сʱ�� 0-23*/
//int tm_mday; /*�գ���һ�����еĵڼ��죬1-31*/
//int tm_mon;  /*�£� ��һ������0-11*/  1 + p->tm_mon;
//int tm_year;  /*�꣬ ��1900�����Ѿ�������*/  1900�� p->tm_year;
//int tm_wday; /*���ڣ�һ���еĵڼ��죬 ������������0-6*/
//int tm_yday; /*�ӽ���1��1�յ�Ŀǰ����������Χ0-365*/
//int tm_isdst; /*�չ��Լʱ������*/
//}; 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	clock_t starttime, endtime;
	double totaltime1, totaltime2, totaltime;
	system("pause");
	starttime = clock(); //	clock_t clock(void) ���س���ִ����һ��Ϊ����Ŀ�ͷ����������ʱ����ʹ�õ�ʱ�䡣Ϊ�˻�ȡ CPU ��ʹ�õ�����������Ҫ���� CLOCKS_PER_SEC��
	printf("starttime\n");
	time_t time1 = NULL, time2 = NULL;
	time1 = time(&time1);//time�������ڻ�ȡ1970.01.01���������
	printf("%d\n", time1);
	char time1string[26];
	ctime_s(time1string, sizeof time1string, &time1);//ctime_s()���ڽ�time_t��ʽ��ʱ��ת��Ϊ�ַ�����ʽ��ʱ�䣬���������ֱ�λ��������ַ������飬�ַ������Ⱥʹ�ת����ʱ��
	printf("%s\n", time1string);
	struct tm tm1, tm2;
	gmtime_s(&tm1, &time1);//��time_t��ʽ��ʱ��ת��Ϊstruct tm��ʾ��UTCʱ��;
	localtime_s(&tm2, &time1);//��time_t��ʽ��ʱ��ת��Ϊstruct tm��ʾ�ĵ�ǰʱ����ʱ��;
	char tm1string[26], tm2string[26];
	asctime_s(tm1string, sizeof tm1string, &tm1);//asctime_s������Ϊ��struct tmʱ��ת��Ϊ�ַ�����ʾ��ʱ��
	asctime_s(tm2string, sizeof tm2string, &tm2);
	printf("%s\n", tm1string);
	printf("%s\n", tm2string);
	system("pause");
	printf("endtime\n");
	time2 = time(&time2);//time�������ڻ�ȡ1970.01.01���������
	printf("%d\n", time2);

	endtime = clock();
	totaltime1 = (double)starttime / CLOCKS_PER_SEC;
	totaltime2 = (double)endtime / CLOCKS_PER_SEC;
	totaltime = (double)(endtime - starttime) / CLOCKS_PER_SEC;//�˴������starttime��ʼ��ʱ�䲢����CLOCKS_PER_SEC��ÿ���ӵ�ʱ�Ӽ�ʱ��Ԫ��clock ticks����������ת��Ϊdouble����
	printf("����ӿ�ʼ���е�starttime��ʱ��Ϊ%f��\n", totaltime1);
	printf("����ӿ�ʼ���е�endtime��ʱ��Ϊ%f��\n", totaltime2);
	printf("��starttime��ʼ��endtime������ʱ��Ϊ%f��\n", totaltime);
	system("pause");
};