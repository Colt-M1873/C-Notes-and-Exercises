#include "acllib.h"
const int winWidth = 640, winHeight = 480;
ACL_Image img1;
const char *tom = "1.jpg";
void timerEvent(int id);
int id = 0 ,timerInterval = 5;
int x = 0, y = 0, distx = 5, disty = 5;
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
		
		if (!(x >= 0 && x <= winWidth - 100)) 
			distx *= -1;
		if(!(y >= 0 && y <= winHeight - 100))
			disty *= -1;
			
			/*else
			dist = -5;*/
		x += distx;
		y += disty;
		paint();
	}

}
void paint()
{
	beginPaint();
	clearDevice();
	putImageScale(&img1, x, y, 100, 100);
	endPaint();
	return ;

}

