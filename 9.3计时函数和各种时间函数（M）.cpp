//在time.h中
//
//clock_t 是存储处理器时间的类型，类型为unsigned long，可用于计算程序运行时间
//time_t  是存储日历时间的类型，表示从某一时间点（1970年1月1日）之后到现在经过的秒数。
//struct tm  是用来保存时间和日期的结构*
//struct tm
//{
//int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
//int tm_min;  /*分钟，0-59*/
//int tm_hour; /*小时， 0-23*/
//int tm_mday; /*日，即一个月中的第几天，1-31*/
//int tm_mon;  /*月， 从一月算起，0-11*/  1 + p->tm_mon;
//int tm_year;  /*年， 从1900至今已经多少年*/  1900＋ p->tm_year;
//int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
//int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
//int tm_isdst; /*日光节约时间的旗标*/
//}; 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	clock_t starttime, endtime;
	double totaltime1, totaltime2, totaltime;
	system("pause");
	starttime = clock(); //	clock_t clock(void) 返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。为了获取 CPU 所使用的秒数，您需要除以 CLOCKS_PER_SEC。
	printf("starttime\n");
	time_t time1 = NULL, time2 = NULL;
	time1 = time(&time1);//time函数用于获取1970.01.01至今的秒数
	printf("%d\n", time1);
	char time1string[26];
	ctime_s(time1string, sizeof time1string, &time1);//ctime_s()用于将time_t格式的时间转化为字符串格式的时间，三个参数分别位待传入的字符串数组，字符串长度和待转换的时间
	printf("%s\n", time1string);
	struct tm tm1, tm2;
	gmtime_s(&tm1, &time1);//将time_t格式的时间转化为struct tm表示的UTC时间;
	localtime_s(&tm2, &time1);//将time_t格式的时间转化为struct tm表示的当前时区的时间;
	char tm1string[26], tm2string[26];
	asctime_s(tm1string, sizeof tm1string, &tm1);//asctime_s的作用为将struct tm时间转换为字符串表示的时间
	asctime_s(tm2string, sizeof tm2string, &tm2);
	printf("%s\n", tm1string);
	printf("%s\n", tm2string);
	system("pause");
	printf("endtime\n");
	time2 = time(&time2);//time函数用于获取1970.01.01至今的秒数
	printf("%d\n", time2);

	endtime = clock();
	totaltime1 = (double)starttime / CLOCKS_PER_SEC;
	totaltime2 = (double)endtime / CLOCKS_PER_SEC;
	totaltime = (double)(endtime - starttime) / CLOCKS_PER_SEC;//此处计算从starttime开始的时间并处以CLOCKS_PER_SEC即每秒钟的时钟计时单元（clock ticks）个数，并转换为double类型
	printf("程序从开始运行到starttime的时间为%f秒\n", totaltime1);
	printf("程序从开始运行到endtime的时间为%f秒\n", totaltime2);
	printf("从starttime开始到endtime的运行时间为%f秒\n", totaltime);
	system("pause");
};