#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <pages.h>
#include <IMAGE.h>
int pageStu(int *xy,int *button)
{
    //mousehide();
    clrmous(MouseX,MouseY);
    //newmouse(&MouseX,&MouseY,&press);
    int signStu=0;
    setfillstyle(1,WHITE);
	bar(151,120,639,479);//把右边的内容先清空
    bar(151,0,580,120);
    bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
	bar(38,242,102,274);//左边的点击框bar出来，再重新把字写上去
    hz32(38,242,0xCABE,WHITE);
    hz32(70,242,0xBDCC,WHITE);
    //mousevisiual();
    //绘制左上角的学习两个字
    hz32(160,20,0xCABE,BLACK);
	hz32(200,20,0xBDCC,BLACK);
    //要安装滑动栏
    //Y=110为内容最高分界线
    setfillstyle(1,BLUE);
    bar(152,112,608,464);
    signStu = scrollBar(xy,button);
    if(signStu == 1) return 5;
    else return 2;
}