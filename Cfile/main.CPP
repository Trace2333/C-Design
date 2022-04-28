#include <pages.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <IMAGE.h>
#include <stdlib.h>
#include"./include/common.h"
#include"./include/pages.h"
#include"./include/page_yzx.h"
/*主控函数，实现页面间切换*/
void main()
{
	int SIGN=0;
    User loginuser;
    char mode = '0';
    char hz_in_ex1[45] = "\0";
	int xy[2]={0},button[3]={0};
    graphinit();
    mouseinit();
    page_yzx(&loginuser,mode);
    clrmous(MouseX,MouseY);
    pageOrigin(xy,button);
    //页面判断机制：
    //在第一次判断给予一个初始页面跳转信号，之后利用SIGN作为页面跳转的信号，执行不再主循环中进行鼠标取位置的操作
    //每一个页面内置有鼠标判断退出按钮，向一个统一的地址写入位置信息，直接用于下一次循环判断
    while(1)
    {
        //delay(50);
        newmouse(&MouseX,&MouseY,&press);
        if(SIGN==0) 
        {
            mousexy(xy,button);
        }
        if(MY&&SIGN!=1)//一定要判断sign
        {
            SIGN=1;
            clrmous(MouseX,MouseY);
			pageMy(xy,button,&loginuser);
        }
        if(STUDY&&SIGN!=2||SIGN==5)
        {
            SIGN=2;
            clrmous(MouseX,MouseY);
            SIGN = pageStu(xy,button);
            /*
            if(SIGN==5)
            {
                SIGN = pageStu(xy,button);
            }
            SIGN=2;
            */
        }
        if(EXPLORE&&SIGN!=3||SIGN==6)
        {
            SIGN=3;
            clrmous(MouseX,MouseY);
            SIGN = pageExplore(xy,button);
        }
        if(MISSION&&SIGN!=4)
        {
            SIGN=4;
            clrmous(MouseX,MouseY);
            pageMission(xy,button,&loginuser,hz_in_ex1);
        }
    }
}