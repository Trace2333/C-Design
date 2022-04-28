#include"./include/common.h"
#include"./include/pageT2.h"
#include"./include/input.h"
/*---------------------------------------------------------------
函数名：int patSec()
函数功能：用于教师端口里面的任务发布页
主要分为两部分，一部分选择已有的任务发布，第二部分选择自拟任务
形参：无
返回值：page用于页面切换
---------------------------------------------------------------*/
int patSec()
{
    int page = 1;
    int i = 0;
    int num_len = 0;
    int xy[2]={0},button[3]={0};
    FILE *fp;
    char m[31] = "\0";
    char mission[8][31] = {"俯卧撑五十次","测试一千米长跑","跳绳两百次","练习立定跳远三十分钟","测试一百米短跑","做拉伸动作十五分钟","仰卧起坐六十次","\0"};
    char hz_in[30][3] = {"\0","\0","\0","\0","\0","\0","\0","\0","\0","\0","\0","\0","\0","\0","\0"};
    char hz_in_ex[45] = "\0";
    int choose[8] = {0,0,0,0,0,0,0,0};
    //mousehide();
    clrmous(MouseX,MouseY);
    setfillstyle(1,WHITE);
	bar(151,120,639,479);
    bar(151,0,580,120);
    bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
	bar(11,364,139,396);//左边的点击框bar出来，再重新把字写上去
    hz32sChanged(11,364,"任务发布",1);
    hz32sChanged(160,20,"教师端",1);
    setcolor(1);
    rectangle(165,80,605,420);
    line(580,80,580,420);
    line(165,120,605,120);
    line(165,160,605,160);
    line(165,200,605,200);
    line(165,240,605,240);
    line(165,280,605,280);
    line(165,320,605,320);
    line(165,360,605,360);
    hz32sChanged(166,84,"俯卧撑五十次",1);
    hz32sChanged(166,124,"测试一千米长跑",1);
    hz32sChanged(166,164,"跳绳两百次",1);
    hz32sChanged(166,204,"练习立定跳远三十分钟",1);
    hz32sChanged(166,244,"测试一百米短跑",1);
    hz32sChanged(166,284,"做拉伸动作十五分钟",1);
    hz32sChanged(166,324,"仰卧起坐六十次",1);
    hz16sChanged(166,361,"自拟",1);
    setcolor(DARKGRAY);
	rectangle(170,380,570,410);
    setfillstyle(1,LIGHTBLUE);
    bar(165+220-18,430,165+220+18,450);
    hz16sChanged(165+220-16,432,"确认",1);
    //mousevisiual();
    delay(100);
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        mousexy(xy,button);
        if(xy[0]>11&&xy[0]<139&&xy[1]>164&&xy[1]<196)
        {
            clrmous(MouseX,MouseY);
            setfillstyle(1,CYAN);
	        bar(11,364,139,396);
            hz32sChanged(11,364,"任务发布",1);
            page = 0;
            break;
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>80&&xy[1]<120&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[0] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,83,602,117);
                choose[0] = 1;
                continue;
            }
            if(choose[0] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,83,602,117);
                choose[0] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>120&&xy[1]<160&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[1] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,123,602,157);
                choose[1] = 1;
                continue;
            }
            if(choose[1] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,123,602,157);
                choose[1] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>160&&xy[1]<200&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[2] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,163,602,197);
                choose[2] = 1;
                continue;
            }
            if(choose[2] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,163,602,197);
                choose[2] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>200&&xy[1]<240&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[3] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,203,602,237);
                choose[3] = 1;
                continue;
            }
            if(choose[3] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,203,602,237);
                choose[3] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>240&&xy[1]<280&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[4] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,243,602,277);
                choose[4] = 1;
                continue;
            }
            if(choose[4] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,243,602,277);
                choose[4] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>280&&xy[1]<320&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[5] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,283,602,317);
                choose[5] = 1;
                continue;
            }
            if(choose[5] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,283,602,317);
                choose[5] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>320&&xy[1]<360&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[6] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,323,602,357);
                choose[6] = 1;
                continue;
            }
            if(choose[6] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,323,602,357);
                choose[6] = 0;
                continue;
            }
        }
        if(xy[0]>580&&xy[0]<605&&xy[1]>360&&xy[1]<420&&button[0]==1)
        {
            delay(300);
            clrmous(MouseX,MouseY);
            if(choose[7] == 0)
            {
                setfillstyle(1,LIGHTBLUE);
                bar(583,363,602,417);
                choose[7] = 1;
                continue;
            }
            if(choose[7] == 1)
            {
                setfillstyle(1,WHITE);
                bar(583,363,602,417);
                choose[7] = 0;
                continue;
            }
        }
        if(xy[0]>170&&xy[0]<570&&xy[1]>380&&xy[1]<410&&button[0]==1)
        {
            clrmous(MouseX,MouseY);
            num_len = py_input_main(170,380,570,410,&hz_in[num_len],num_len);
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
        {
            exit(0);
        }
        if(xy[0]>165+220-18&&xy[0]<165+220+18&&xy[1]>430&&xy[1]<450&&button[0]==1)
        {
            for(i=1;i<num_len;i++)
            {
                if(strcmp(hz_in[i*2],"\0")!=0)
                {
                    strcpy(hz_in[i],hz_in[i*2]);
                    strcpy(hz_in[i*2],"\0");
                }
            }
            for(i=0;i<num_len;i++)
            {
                strcat(hz_in_ex,hz_in[i]);
            }
            hz_in_ex[2*num_len + 1] = '\0';
            strcpy(mission[7],hz_in_ex);
            if((fp=fopen(".\\user\\mission.bin","wb+")) == NULL)
            {
                printf("error open\n");
                exit(1);
            }
            for(i=0;i<30;i++)
            {
                strcpy(hz_in[i],"\0");
            }
            for(i=0;i<8;i++)
            {
                if(choose[i] == 1)
                {
                    fwrite(&mission[i],31,1,fp);
                }
                else if(choose[i] == 0)
                {
                    fwrite(m,31,1,fp);
                }
            }
            fclose(fp);
            break;
        }
    }
    return page;
}