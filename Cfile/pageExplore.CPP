#include <stdio.h>
#include <dos.h>
#include <pages.h>
#include <IMAGE.h>
#include <graphics.h>
#include <stdlib.h>
int pageExplore(int *xy,int *button)
{
    int signExp = 0;
	mousehide();
    setfillstyle(1,WHITE);
	bar(151,120,639,479);//把右边的内容先清空
    bar(151,0,580,120);
	bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
    bar(38,310,102,342);//左边的点击框bar出来，再重新把字写上去
	hz32(38,310,0xCCBD,WHITE);
    hz32(70,310,0xCBF7,WHITE);
	mousevisiual();
    hz32(160,20,0xCCBD,BLACK);//绘制左上角的大字
    hz32(200,20,0xCBF7,BLACK);
    setfillstyle(1,BLUE);
    bar(152,112,608,464);
    signExp = scrollBarForExplore(xy,button);
    if(signExp == 1) return 6;
    else return 3;
}