#include"./include/common.h"
#include"./include/pageT.h"
#include"./include/login.h"
/*---------------------------------------------------------------
函数名：void loginG()
函数功能：用于登录页面的绘制
形参：无
返回值：无
---------------------------------------------------------------*/
void loginG()
{
	clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    bar(160,4,636,436);
    setcolor(1);
    rectangle(280,156,600,192);
    rectangle(280,156+60,600,192+60);
    puthz(210,158,"账号",32,32,1);
    puthz(210,218,"密码",32,32,1);
    setfillstyle(1,GREEN);
    bar(390,252+30,460,252+66);
    puthz(391,252+32,"登录",32,32,1);
    setfillstyle(1,LIGHTBLUE);
    bar(480,252+30,550,252+66);
    puthz(481,252+32,"注册",32,32,1);
    setfillstyle(1,RED);
    bar(560,6,630,40);
    puthz(563,7,"退出",32,32,1);
    setfillstyle(1,LIGHTBLUE);
    bar(170,6,300,40);
    puthz(171,7,"教师入口",32,32,1);
}

/*---------------------------------------------------------------
函数名：int loginP(User *loginuser,char mode)
函数功能：用于登录页面的功能实现，有教师模式以及注册的入口
形参：User *loginuser,char mode
返回值：page
---------------------------------------------------------------*/
int loginP(User *loginuser,char mode)
{
    int page =0;
    int mouse =0;
    int len1 =0,len2 =0;
    int findjudge = 0;
    int xy[2]={0},button[3]={0};
    char user_name[12] = "\0";
    char user_pass[12] = "\0";
    int getchar;
	mousehide();
    delay(100);
	loginG();
	mousevisiual();
    while(page == 0)
    {
        mousexy(xy,button);
        newmouse(&MouseX,&MouseY,&press);
        if(mouse_press(170,6,300,40) == 1)
        {
            if(strcmp(user_name,"teacher")==0)
            {
                pageTeacher();
            }
            break;
        }
        if(xy[0]>280&&xy[0]<600&&xy[1]>156&&xy[1]<192&&button[0]==1)
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len1 = textshow(283,156,597,192,12,len1,12,user_name,0);
            user_name[len1] = '\0';
        }

        if(xy[0]>280&&xy[0]<600&&xy[1]>156+60&&xy[1]<192+60&&button[0]==1)
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len2 = textshow_pro(283,156+60,597,192+60,12,len2,12,user_pass);
            user_pass[len2] = '\0';
        }

        if(xy[0]>560&&xy[0]<630&&xy[1]>6&&xy[1]<40&&button[0]==1)
        {
            delay(9);
            exit(0);
        }

        if (bioskey(1))
			getchar = bioskey(0);
		if (getchar == 0X11B)//ESC
		{
            exit(0);
		}

        if(xy[0]>480&&xy[0]<550&&xy[1]>252+30&&xy[1]<252+66&&button[0]==1)
        {
            clrmous(MouseX,MouseY);
            page = 1; //注册页跳转
            break;
        }

		if (xy[0]>390&&xy[0]<460&&xy[1]>252+30&&xy[1]<252+66&&button[0]==1)//点击登录框
        {
            if(len1 > 0 && len2 >0)
            {
				findjudge = File_userfind(loginuser,user_name,user_pass);
                if(findjudge == 1)
                {
                    puthz(380,350+90,"登陆成功",16,16,LIGHTGREEN);
                    delay(300);
                    page = -1;
                    //mousehide();
                    cleardevice();
                    //mousevisiual();
                    clrmous(MouseX,MouseY);
                    break;
                }
                else if(findjudge == -2)
                {
                    puthz(380,350+90,"密码错误",16,16,LIGHTRED);
                    delay(300);
                    setfillstyle(1,WHITE);
                    bar(380,350+90,380+64,366+90);
                }
                else if(findjudge == -1)
                {
                    puthz(360,350+90,"用户名不存在",16,16,LIGHTRED);
                    delay(300);
                    setfillstyle(1,WHITE);
                    bar(360,350+90,360+96,366+90);
                }
                // else if(findjudge == -1)
                // {

				// 	puthz(360,350+90,"文件打开失败",16,16,LIGHTRED);
                //     delay(300);
                //     exit(0);
                // }
            }
        }
    }
    return page;
}