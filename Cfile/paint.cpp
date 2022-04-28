#include"./include/paint.h"
#include"./include/common.h"
/*
******************************************
paint.CPP
用来绘制图形，包括按键框
void light_button(int x1,int y1,int x2,int y2,int color)
void blink(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int color1,int color2)
void circle_bar(int x1,int y1,int x2,int y2,int color)
void circle_bar(int x1,int y1,int x2,int y2,int color)
输入参数：x,y为坐标，color为颜色
******************************************
*/
void light_button(int x1,int y1,int x2,int y2,int color)
{
    setcolor(color);
    setlinestyle(SOLID_LINE,0,3);
    rectangle(x1,y1,x2,y2);
}

void blink(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax,int color1,int color2)
{
    while(!bioskey(1))
    {
        //newmouse(&MouseX,&MouseY,&press);
        setcolor(color1);
        setlinestyle(SOLID_LINE,0,1);
        line(x1,y1,x2,y2);
        delay(90);
        setcolor(color2);
        setlinestyle(SOLID_LINE,0,1);
        line(x1,y1,x2,y2);
        delay(90);
        /*if(mouse_press(xmin,ymin,xmax,ymax)==4)
        {
                delay(9);
                setcolor(color2);
                setlinestyle(SOLID_LINE,0,1);
                line(x1,y1,x2,y2);
                break;
        }*/
    }
    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0,1);
    line(x1,y1,x2,y2);
    delay(90);
}

void circle_bar(int x1,int y1,int x2,int y2,int color)
{
	int w=x2-x1,h=y2-y1;
	setcolor(color);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    ellipse(5+x1,10+y1,90,180,5,10);
    line(0+x1,10+y1,0+x1,10+h-20+y1);
    ellipse(5+x1,10+h-20+y1,180,270,5,10);
    line(5+x1,0+y1,5+w-10+x1,0+y1);
    ellipse(5+w-10+x1+1,10+y1,0,90,5,10);
    line(w+x1,10+y1,w+x1,y2-10);
    ellipse(w-5+x1+1,10+h-20+y1,270,360,5,10);
    line(5+x1,h+y1,5+w-10+x1,h+y1);
}

void circle_bar_2(int x1,int y1,int x2,int y2,int color)
{
    int w=x2-x1,h=y2-y1;
    setfillstyle(1,color);
    sector(5+x1,10+y1,90,180,5,10);
    sector(5+x1,10+h-20+y1,180,270,5,10);
    sector(5+w-10+x1+1,10+y1,0,90,5,10);
    sector(w-5+x1+1,10+h-20+y1,270,360,5,10);
    bar(x1,y1+9,x2,y2-9);
    bar(x1+4,y1,x2-4,y2);
}