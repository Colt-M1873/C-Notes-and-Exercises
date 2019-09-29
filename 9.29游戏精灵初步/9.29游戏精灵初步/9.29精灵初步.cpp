#include "acllib.h"
const int winWidth = 640, winHeight = 480;
ACL_Image img1;
const char *tom = "1.jpg";
void timerEvent(int id);
int id = 0 ,timerInterval = 50;
int x = 10, y = 10, dist = 5;
void paint();

int Setup(void)
{
	initWindow("window1", DEFAULT, DEFAULT, winWidth, winHeight);
	loadImage(tom, &img1);
	beginPaint();
	putImageScale(&img1, 0,0,100,100);
	registerTimerEvent(timerEvent);
	startTimer(id, timerInterval);
	//paint();//为什么加这一句会出错？
	endPaint();
	return 0;

}
void timerEvent(int id) {
	if (id == 0) {
		x += 5;
		y += 5;
		paint();
	}

}
void paint()
{
	beginPaint();
	putImageScale(&img1, x, y, 100, 100);
	endPaint();
	return ;

}

