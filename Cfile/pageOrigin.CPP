#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <pages.h>
#include"./include/common.h"
/*
*******************************************************
pageOrigin.CPP
参数:鼠标坐标数组和鼠标按键数组
显示初始页状态,只用来绘制左边栏和一个Welcome
*******************************************************
*/
void pageOrigin(int *xy,int *button)
{
    clrmous(MouseX,MouseY);
    mousexy(xy,button);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(1,CYAN);
    bar(0,0,150,479);
	int poly1[8]={0,0,150,0,150,479,0,479};
	fillpoly(4,poly1);
    setcolor(WHITE);
    line(0,120,150,120);
    pageSign(11,174,0);
    pageSign(11,242,1);
    pageSign(11,310,2);
    pageSign(11,378,3);
    //Welcome
    hz32(300,60,0xBBB6,GREEN);
    hz32(332,60,0xD3AD,GREEN);
    hz32(364,60,0xCAB9,GREEN);
    hz32(396,60,0xD3C3,GREEN);
    //MY
    hz32(38,174,0xCED2,WHITE);
    hz32(70,174,0xB5C4,WHITE);
    //STUDY
    hz32(38,242,0xCABE,WHITE);
    hz32(70,242,0xBDCC,WHITE);
    //EXPLORE
    hz32(38,310,0xCCBD,WHITE);
    hz32(70,310,0xCBF7,WHITE);
    //MISSION
    hz32(38,378,0xC8CE,WHITE);
	hz32(70,378,0xCEF1,WHITE);
    pageSign(0,10,4);
    setfillstyle(1,RED);
    bar(580,0,639,40);
    hz16(590,15,0xCDCB,BLACK);
    hz16(610,15,0xB3F6,BLACK);
}