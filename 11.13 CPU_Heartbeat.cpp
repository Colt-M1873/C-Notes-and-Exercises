#include <iostream>
#include <windows.h>
#include <cmath>

#define PI 3.1415926535
using namespace std;
const double _1000MILLI = 1000;
void per_second_cpu(__int64 start_time, double busy_time_rate) {
	start_time = GetTickCount();
	while ((GetTickCount() - start_time) <= busy_time_rate * _1000MILLI) {}
	Sleep((1.0 - busy_time_rate) * _1000MILLI);
}
void line_cpu(double busy_time_rate) {
	__int64 start_time = NULL;
	while (true) {
		per_second_cpu(start_time, busy_time_rate);
	}
}
void sin_cpu() {
	__int64 start_time = NULL;
	while (true) {
		int t = 15;
		double busy_time_rate = NULL;
		for (int i = 0; i < t; ++i) {
			if (i == 5)
				busy_time_rate = 0.9;
			else if (i == 7)
				busy_time_rate = 0;
			else
				busy_time_rate = 0.4;//*sin(i * 2 / (t * 1.0) * PI) / 2.0 +0.5;
			per_second_cpu(start_time, busy_time_rate);
		}
	}
}
DWORD WINAPI handle_line(LPVOID lpParameter) {
	line_cpu(*(double*)lpParameter);
	return 0;
}
DWORD WINAPI handle_sin(LPVOID lpParameter) {
	sin_cpu();
	return 0;
}
void begin_line(double busy_time_rate) {
	SetProcessAffinityMask(GetCurrentProcess(), 255);
	for (int i = 0; i < 7; ++i) {
		HANDLE handleProcess = CreateThread(NULL, 0, handle_line, &busy_time_rate, 0, NULL);
		CloseHandle(handleProcess);
	}
	line_cpu(busy_time_rate);
}
void begin_sin() {
	SetProcessAffinityMask(GetCurrentProcess(), 255);
	for (int i = 0; i < 7; ++i) {
		HANDLE handleProcess = CreateThread(NULL, 0, handle_sin, NULL, 0, NULL);
		CloseHandle(handleProcess);
	}
	sin_cpu();
}
int main() {
	//    double busy_time_rate=0.5;
	//    begin_line(busy_time_rate);
	begin_sin();
	return 0;
}