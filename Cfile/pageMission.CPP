#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <pages.h>
#include <stdlib.h>
#include <IMAGE.h>
#include"./include/common.h"
#include"./include/input.h"
/*---------------------------------------------------------------
函数名：int pageMission(int *xy,int *button,User *loginuser,char *hz_in_ex1)
函数功能：用于任务页面的绘制以及功能实现
相关功能：首页展示教师发布的任务与推荐的任务，第二页用于每日计划确定是否完成
形参：int *xy,int *button,User *loginuser,char *hz_in_ex1（鼠标相关参数与用户信息及输入的汉字用于查询）
返回值：page
---------------------------------------------------------------*/
int pageMission(int *xy,int *button,User *loginuser,char *hz_in_ex1)
{
	mousehide();
    FILE *fp = NULL;
	int change = 2;
    int choose[6] = {0,0,0,0,0,0};
    char title[30] = ".//user//";
    char end[10] = ".bin";
    strcat(title,loginuser->uname);
    strcat(title,end);
    int i=0,j=0;
    char mission[8][31] = {"\0","\0","\0","\0","\0","\0","\0","\0"};
    setfillstyle(1,WHITE);
	bar(151,120,639,479);
    bar(151,0,580,120);
    bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
	bar(38,378,102,410);
	hz32(38,378,0xC8CE,WHITE);
	hz32(70,378,0xCEF1,WHITE);
	mousevisiual();
    hz32(160,20,0xC8CE,BLACK);
    hz32(200,20,0xCEF1,BLACK);
    hz16sChanged(160,110,"任务",1);
    hz16sChanged(210,110,"计划",1);
    if((fp=fopen(".\\user\\mission.bin","rb")) == NULL)
    {
        printf("error open\n");
        exit(1);
    }
    for(i=0;i<8;i++)
    {
        fread(&mission[i],31,1,fp);
    }
    fclose(fp);
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        mousexy(xy,button);
        if(MY||STUDY||EXPLORE)
        {
            clrmous(MouseX,MouseY);
            setfillstyle(1,CYAN);
            bar(38,378,102,410);
            hz32(38,378,0xC8CE,WHITE);
	        hz32(70,378,0xCEF1,WHITE);
			return 1;
        }
        if((xy[0]>160&&xy[0]<192&&xy[1]>110&&xy[1]<126&&button[0]==1)||change == 0)
        {
            clrmous(MouseX,MouseY);
            change = 0;
            setfillstyle(1,WHITE);
            bar(151,130,640,480);
            setcolor(CYAN);
            line(160,128,192,128);line(160,129,192,129);
            setcolor(WHITE);
            line(210,128,242,128);line(210,129,242,129);
            setcolor(1);
            rectangle(160,130,470,298);
            rectangle(160,302,470,478);
            for(i=0;i<8;i++)
            {
                hz16sChanged(165,131+i*18,mission[i],1);
            }
            hz16sChanged(165,307,"每日晨跑三十分钟",1);
            hz16sChanged(165,337,"散步一公里",1);
            hz16sChanged(165,367,"跳绳两百次",1);
            hz16sChanged(165,397,"开合跳三十次",1);
            hz16sChanged(165,427,"原地高抬腿一分钟",1);
            hz16sChanged(165,457,"深蹲六分钟",1);
            while(1)
            {
                newmouse(&MouseX,&MouseY,&press);
                mousexy(xy,button);
                if(xy[0]>210&&xy[0]<242&&xy[1]>110&&xy[1]<126&&button[0]==1)
                {
                    change = 1;
                    break;
                }
                if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
                {
                    exit(0);
                }
                if(MY||STUDY||EXPLORE)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,CYAN);
                    bar(38,378,102,410);
                    hz32(38,378,0xC8CE,WHITE);
                    hz32(70,378,0xCEF1,WHITE);
                    return 1;
                }
            }
        }
        if((xy[0]>210&&xy[0]<242&&xy[1]>110&&xy[1]<126&&button[0]==1)||change == 1)
        {
            clrmous(MouseX,MouseY);
            change = 1;
            setfillstyle(1,WHITE);
            bar(151,130,640,480);
            setcolor(WHITE);
            line(160,128,192,128);line(160,129,192,129);
            setcolor(CYAN);
            line(210,128,242,128);line(210,129,242,129);
            setfillstyle(1,LIGHTGREEN);
            bar(279,419,409,453);
            rectangle(240,150,250,160);
            rectangle(240,190,250,200);
            rectangle(240,230,250,240);
            rectangle(240,270,250,280);
            rectangle(240,310,250,320);
            rectangle(240,350,250,360);
            hz32sChanged(260,140,"起床",1);
            hz32sChanged(260,180,"晨间跑步",1);
            hz32sChanged(260,220,"营养早餐",1);
            hz32sChanged(260,260,"午休一小时",1);
            hz32sChanged(260,300,"晚间跑步",1);
            hz32sChanged(260,340,"杜绝过度熬夜",1);
            hz32sChanged(280,420,"确认完成",1);
            while(change == 1)
            {
                newmouse(&MouseX,&MouseY,&press);
                mousexy(xy,button);
                if(MY||STUDY||EXPLORE)
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,CYAN);
                    bar(38,378,102,410);
                    hz32(38,378,0xC8CE,WHITE);
                    hz32(70,378,0xCEF1,WHITE);
                    return 1;
                }
                if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
                {
                    exit(0);
                }
                if(xy[0]>160&&xy[0]<192&&xy[1]>110&&xy[1]<126&&button[0]==1)
                {
                    change = 0;
                    break;
                }
                if(mouse_press(240,150,250,160) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[0] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,151,249,159);
                        choose[0] = 1;
                        continue;
                    }
                    if(choose[0] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,151,249,159);
                        choose[0] = 0;
                        continue;
                    }
                }
                if(mouse_press(240,190,250,200) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[1] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,191,249,199);
                        choose[1] = 1;
                        continue;
                    }
                    if(choose[1] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,191,249,199);
                        choose[1] = 0;
                        continue;
                    }
                }
                if(mouse_press(240,230,250,240) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[2] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,231,249,239);
                        choose[2] = 1;
                        continue;
                    }
                    if(choose[2] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,231,249,239);
                        choose[2] = 0;
                        continue;
                    }
                }
                if(mouse_press(240,270,250,280) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[3] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,271,249,279);
                        choose[3] = 1;
                        continue;
                    }
                    if(choose[3] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,271,249,279);
                        choose[3] = 0;
                        continue;
                    }
                }
                if(mouse_press(240,310,250,320) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[4] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,311,249,319);
                        choose[4] = 1;
                        continue;
                    }
                    if(choose[4] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,311,249,319);
                        choose[4] = 0;
                        continue;
                    }
                }
                if(mouse_press(240,350,250,360) == 1)
                {
                    delay(300);
                    clrmous(MouseX,MouseY);
                    if(choose[5] == 0)
                    {
                        setfillstyle(1,LIGHTBLUE);
                        bar(241,351,249,359);
                        choose[5] = 1;
                        continue;
                    }
                    if(choose[5] == 1)
                    {
                        setfillstyle(1,WHITE);
                        bar(241,351,249,359);
                        choose[5] = 0;
                        continue;
                    }
                }
                if(mouse_press(279,419,409,453) == 1)
				{
					delay(90);
                    hz16sChanged(260,460,"坚持就是胜利",1);
                    setfillstyle(1,WHITE);
                    bar(241,151,249,159);
                    bar(241,191,249,199);
                    bar(241,231,249,239);
                    bar(241,271,249,279);
                    bar(241,311,249,319);
                    bar(241,351,249,359);
                    delay(300);
                    setfillstyle(1,WHITE);
                    bar(260,460,360,480);
                }    
            }
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
        {
			exit(0);
        }
    }
}