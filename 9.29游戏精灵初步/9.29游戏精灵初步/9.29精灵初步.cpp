#include "acllib.h"
const int winWidth = 640, winHeight = 480;
int Setup(void)
{
	initWindow("window1", DEFAULT, DEFAULT, winWidth, winHeight);
	return 0;
}