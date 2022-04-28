#include"./include/common.h"
#include"./include/register.h"
/*---------------------------------------------------------------
函数名：void registerG()
函数功能：用于注册页面的绘制
形参：无
返回值：无
---------------------------------------------------------------*/
void registerG()
{
	clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
    bar(160,4,636,436);
    setcolor(1);
    rectangle(300,96,600,132);
    rectangle(300,156,600,192);
    rectangle(300,216,600,252);
    rectangle(300,276,600,312);
    puthz(170,98,"学号选填",32,32,1);
    puthz(230,158,"账号",32,32,1);
    puthz(230,218,"密码",32,32,1);
    puthz(170,278,"确认密码",32,32,1);
    setfillstyle(1,LIGHTGREEN);
    bar(340,360,410,400);
    puthz(343,364,"注册",32,32,1);
    setfillstyle(1,YELLOW);
    bar(480,360,550,400);
    puthz(483,364,"返回",32,32,1);
    setfillstyle(1,RED);
    bar(560,6,630,40);
    puthz(563,7,"退出",32,32,1);
}

/*---------------------------------------------------------------
函数名：int registerP(User *loginuser)
函数功能：用于注册页面的功能实现
形参：User *loginuser
返回值：page
---------------------------------------------------------------*/
int registerP(User *loginuser)
{
    int page = 1;
    int len1 = 0,len2 = 0,len3 = 0,len4 = 0;
    int xy[2]={0},button[3]={0};
    int getc,judge;
    char smode = '0';
    char user_id[12]="\0";
    char user_name[12]="\0";
    char temp_pass[12]="\0";
    char user_pass[12]="\0";
    int user_course = 0;
    //mousehide();
    delay(100);
    registerG();
    //mousevisiual();
    while(1)
    {
        mousexy(xy,button);
        newmouse(&MouseX,&MouseY,&press);
        if(xy[0]>300&&xy[0]<600&&xy[1]>96&&xy[1]<132&&button[0]==1) 
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len1 = textshow(303,96,597,132,12,len1,12,user_id,0);
            user_id[len1] = '\0';
        }
        if(xy[0]>300&&xy[0]<600&&xy[1]>156&&xy[1]<192&&button[0]==1) 
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len2 = textshow(303,156,597,192,12,len2,12,user_name,0);
            user_name[len2] = '\0';
        }
        if(xy[0]>300&&xy[0]<600&&xy[1]>216&&xy[1]<252&&button[0]==1) 
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len3 = textshow_pro(303,216,597,252,12,len3,12,temp_pass);
            temp_pass[len3] = '\0';
        }
        if(xy[0]>300&&xy[0]<600&&xy[1]>276&&xy[1]<312&&button[0]==1) 
        {
            delay(9);
            clrmous(MouseX,MouseY);
            len4 = textshow_pro(303,276,597,312,12,len4,12,user_pass);
            user_pass[len4] = '\0';
        }
        if(xy[0]>560&&xy[0]<630&&xy[1]>6&&xy[1]<40&&button[0]==1)
        {
            delay(9);
            exit(0);
        }

        if(xy[0]>480&&xy[0]<550&&xy[1]>360&&xy[1]<400&&button[0]==1)
        {
            delay(9);
            page = 0;
            break;
        }
    
        if(bioskey(1))
        {
            getc = bioskey(0);
        }
        if(getc ==0x11B)
        {
            delay(9);
            exit(0);
        }
        if(xy[0]>340&&xy[0]<410&&xy[1]>360&&xy[1]<400&&button[0]==1)
        {
            strcpy(loginuser->ID,user_id);
            strcpy(loginuser->uname,user_name);
            strcpy(loginuser->upass,user_pass);
            loginuser->ucourse = user_course;
            if(len1 == 0)
            {
                smode = '1';
            }
            if(len1 > 0)
            {
                smode = '0';
            }
            if (len2 > 0 && len3 > 0 && len4 >0)
            {
				judge=File_userfind(loginuser,user_name,user_pass);
                if(judge!=-3&&judge!=-1)
                {
                    puthz(410,450,"用户已存在",16,16,RED);
                    delay(900);
                    setfillstyle(1,WHITE);
                    bar(410,450,490,466);
                }
                
                else
                {
                    if(len3 >= 6 && strcmp(temp_pass,user_pass) == 0) 
                    {
                        judge = File_useradd(loginuser,user_id,user_name,user_pass,user_course,smode);
                        if(judge == 1)
                        {
                            puthz(420,450,"注册成功",16,16,LIGHTGREEN);
                            delay(900);
                            setfillstyle(1,WHITE);
                            bar(420,450,490,466);
                            page = -1;
                            delay(500);
                            puthz(420,450,"正在登录",16,16,LIGHTGREEN);
                            delay(500);
                            cleardevice();
                            clrmous(MouseX,MouseY);
                            break;
                        }
                        if(judge == -1)
                        {
                            puthz(400,450,"文件打开失败",16,16,RED);
                            delay(900);
                            setfillstyle(1,WHITE);
                            bar(400,450,500,466);
                        }
                    }
                    else if(strcmp(temp_pass,user_pass) != 0)
                    {
                        puthz(410,450,"密码不一致",16,16,RED);
                        delay(900);
                        setfillstyle(1,WHITE);
                        bar(410,450,490,466);
                    }
					else if(len3 < 6)
                    {
                        puthz(380,450,"密码不得少于六位",16,16,RED);
                        delay(900);
                        setfillstyle(1,WHITE);
                        bar(380,450,508,466);
                    }
                }
            }
            else if(len2 == 0||len3 == 0||len4 == 0)
            {
                puthz(380,450,"未输入账号或密码",16,16,RED);
                delay(900);
                setfillstyle(1,WHITE);
                bar(380,450,508,466);
            }
        }
    }
    return page;
}