#include"./include/common.h"
#include"./include/pageT1.h"
#include"./include/user.h"
#include"./include/input.h"
/*---------------------------------------------------------------
函数名：void patFir()
函数功能：用于教师端口里面的首页
形参：无
返回值：page用于页面切换
---------------------------------------------------------------*/
int patFir()
{
    int page = 0;
    int sign1 = 1;
    int i = 0,j = 0;
    int num_len = 0;
    char title[60] = ".\\user\\";
    char end[5] = ".bin";
    int xy[2]={0},button[3]={0};
	int time_read[42] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int time_all[10] = {0,0,0,0,0,0,0,0,0,0};
    int time_num[6] = {0,0,0,0,0,0};
    int poly[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    FILE *fp_name; 
    FILE *fp_stu;
    Stuname *phead = NULL;
    Stuname *pnew = NULL;
    Stuname *pend = NULL;
    Stuname *phead_t = NULL;
    char hz_in[5][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
    char hz_in_ex[5] ="\0";
    mousehide();
    setfillstyle(1,WHITE);
	bar(151,120,639,479);
    bar(151,0,580,120);
    bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
    setcolor(CYAN);
    line(208,128,272,128);line(208,129,272,129);
	bar(11,164,139,196);//左边的点击框bar出来，再重新把字写上去
    hz32sChanged(11,164,"学生信息",1);
    hz32sChanged(160,20,"教师端",1);
    hz16sChanged(208,110,"班级总览",1);
    hz16sChanged(368,110,"学生查询",1);
    mousevisiual();
    delay(100);
    if((fp_name = fopen(".\\user\\stuname.bin","rb")) == NULL)
    {
        hz16sChanged(10,10,"打开失败一",1);
        delay(300);
        exit(1);
    }
    rewind(fp_name);
    while(feof(fp_name) == 0)
    {
        if((pnew = (Stuname *)malloc(sizeof(Stuname)-2)) == NULL)
        {
            hz16sChanged(10,10,"打开失败二",1);
            delay(300);
            exit(1);
        }
        fread(pnew,sizeof(Stuname),1,fp_name);
        fseek(fp_name,-2,SEEK_CUR);
        if(phead == NULL)
        {
			phead = pnew,pend = phead;
        }
        else if(strcmp(pnew->uname,"\0")==0)
        {
            break;
        }
        else{
            pend->next = pnew;
			pend = pnew;
        }
    }
    pend->next = NULL;
    phead_t = phead;
    fclose(fp_name);
    setfillstyle(1,WHITE);
	bar(151,130,639,479);
    setcolor(CYAN);
    line(208,128,272,128);line(208,129,272,129);
    setcolor(WHITE);
    line(368,128,432,128);line(368,129,432,129);
    hz32sChanged(160,150,"学习时长",1);
    ShowNumberAndLetter5(160,190+40,"0-3000",RED);
    ShowNumberAndLetter5(160,230+40,"3000-4000",LIGHTRED);
    ShowNumberAndLetter5(160,270+40,"4000-5000",LIGHTMAGENTA);
    ShowNumberAndLetter5(160,310+40,"5000-6000",YELLOW);
    ShowNumberAndLetter5(160,350+40,"6000-7000",GREEN);
    ShowNumberAndLetter5(160,390+40,"7000-8400",LIGHTGREEN);
    setlinestyle(SOLID_LINE,0,3);
    setcolor(LIGHTGRAY);
    line(160,200+40,360,200+40);
    line(160,240+40,360,240+40);
    line(160,280+40,360,280+40);
    line(160,320+40,360,320+40);
    line(160,360+40,360,360+40);
	line(160,400+40,360,400+40);
	phead = phead_t;
    for(i=0;i<9;i++)
    {
        strcat(title,phead->uname);
        strcat(title,end);
        phead = phead->next;
        if((fp_stu = fopen(title,"rb")) == NULL)
        {
            hz16sChanged(180,170,"文件打开失败",RED);
            delay(300);
            setfillstyle(1,WHITE);
            bar(180,170,320,186);
            exit(1);
        }
        strcpy(title,".\\user\\");
        fseek(fp_stu,39,SEEK_SET);
        for(j=0;j<42;j++)
        {
            fread(&time_read[j],sizeof(int),1,fp_stu);
            time_all[i] += time_read[j]; 
        }
        fclose(fp_stu);
    }
    for(i=0;i<9;i++)
    {
        if(time_all[i]>0&&time_all[i]<3000)
        {
        time_num[0]++;
        }
        if(time_all[i]>3000&&time_all[i]<4000)
        {
        time_num[1]++;
        }
        if(time_all[i]>4000&&time_all[i]<5000)
        {
        time_num[2]++;
        }
        if(time_all[i]>5000&&time_all[i]<6000)
        {
        time_num[3]++;
        }
        if(time_all[i]>6000&&time_all[i]<7000)
        {
        time_num[4]++;
        }
        if(time_all[i]>7000&&time_all[i]<8400)
        {
        time_num[5]++;
        }
    }
    setcolor(RED);
    line(160,200+40,160+20*time_num[0],200+40);
    setcolor(LIGHTRED);
    line(160,240+40,160+20*time_num[1],240+40);
    setcolor(LIGHTMAGENTA);
    line(160,280+40,160+20*time_num[2],280+40);
    setcolor(YELLOW);
    line(160,320+40,160+20*time_num[3],320+40);
    setcolor(GREEN);
    line(160,360+40,160+20*time_num[4],360+40);
    setcolor(LIGHTGREEN);
    line(160,400+40,160+20*time_num[5],400+40);
    setlinestyle(SOLID_LINE,0,1);
    for(i=0;i<6;i++)
    {
        time_num[i] = 0;
    }
    for(i=0;i<9;i++)
    {
        time_all[i] = 0;
    }
    phead = phead_t;
    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
		mousexy(xy,button);
        if(xy[0]>11&&xy[0]<139&&xy[1]>364&&xy[1]<396&&button[0]==1)           //PAGET2 -> x>11,x<139,y>364,y<396
        {
            clrmous(MouseX,MouseY);
            setfillstyle(1,CYAN);
	        bar(11,164,139,196);
            hz32sChanged(11,164,"学生信息",1);
            page = 1;
            break;
        }
        if(xy[0]>208&&xy[0]<272&&xy[1]>110&&xy[1]<128&&button[0]==1&&sign1 != 1)     //PAGE1 -> x>208,x<272,y>110,y<128
        {
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,130,639,479);
            mousehide();
            setcolor(CYAN);
            line(208,128,272,128);line(208,129,272,129);
            setcolor(WHITE);
            line(368,128,432,128);line(368,129,432,129);
            sign1 = 1;
            hz32sChanged(160,150,"学习时长",1);
            ShowNumberAndLetter5(160,190+40,"0-3000",RED);
            ShowNumberAndLetter5(160,230+40,"3000-4000",LIGHTRED);
            ShowNumberAndLetter5(160,270+40,"4000-5000",LIGHTMAGENTA);
            ShowNumberAndLetter5(160,310+40,"5000-6000",YELLOW);
            ShowNumberAndLetter5(160,350+40,"6000-7000",GREEN);
            ShowNumberAndLetter5(160,390+40,"7000-8400",LIGHTGREEN);
            setlinestyle(SOLID_LINE,0,3);
            setcolor(LIGHTGRAY);
            line(160,200+40,360,200+40);
            line(160,240+40,360,240+40);
            line(160,280+40,360,280+40);
            line(160,320+40,360,320+40);
            line(160,360+40,360,360+40);
            line(160,400+40,360,400+40);
            for(i=0;i<9;i++)
            {
                strcat(title,phead->uname);
                strcat(title,end);
                phead = phead->next;
                if((fp_stu = fopen(title,"rb")) == NULL)
                {
                    hz16sChanged(180,170,"文件打开失败",RED);
                    delay(300);
                    setfillstyle(1,WHITE);
                    bar(180,170,320,186);
                    exit(1);
                }
				strcpy(title,".\\user\\");
				fseek(fp_stu,39,SEEK_SET);
                for(j=0;j<6;j++)
                {
					fread(&time_read[j],sizeof(int),1,fp_stu);
                    time_all[i] += time_read[j]; 
                }
                fclose(fp_stu);
            }
            for(i=0;i<9;i++)
            {
                if(time_all[i]>0&&time_all[i]<3000)
                {
                time_num[0]++;
                }
                if(time_all[i]>3000&&time_all[i]<4000)
                {
                time_num[1]++;
                }
                if(time_all[i]>4000&&time_all[i]<5000)
                {
                time_num[2]++;
                }
                if(time_all[i]>5000&&time_all[i]<6000)
                {
                time_num[3]++;
                }
                if(time_all[i]>6000&&time_all[i]<7000)
                {
                time_num[4]++;
                }
                if(time_all[i]>7000&&time_all[i]<8400)
                {
                time_num[5]++;
                }
            }
            setcolor(RED);
            line(160,200+40,160+20*time_num[0],200+40);
            setcolor(LIGHTRED);
            line(160,240+40,160+20*time_num[1],240+40);
            setcolor(LIGHTMAGENTA);
            line(160,280+40,160+20*time_num[2],280+40);
            setcolor(YELLOW);
            line(160,320+40,160+20*time_num[3],320+40);
            setcolor(GREEN);
            line(160,360+40,160+20*time_num[4],360+40);
            setcolor(LIGHTGREEN);
            line(160,400+40,160+20*time_num[5],400+40);
            setlinestyle(SOLID_LINE,0,1);
            for(i=0;i<6;i++)
            {
                time_num[i] = 0;
            }
            for(i=0;i<9;i++)
            {
                time_all[i] = 0;
            }
            phead = phead_t;
            mousevisiual();
        }
        if(xy[0]>328&&xy[0]<432&&xy[1]>110&&xy[1]<128&&button[0]==1&&sign1 != 2)   //PAGE2 -> x>368,x<432,y>110,y<128
        {
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,130,639,479);
            mousehide();
            setcolor(WHITE);
            line(208,128,272,128);line(208,129,272,129);
            setcolor(CYAN);
            line(368,128,432,128);line(368,129,432,129);
            sign1 = 2;
            setcolor(1);
            rectangle(180,140,300,160);
            setfillstyle(1,LIGHTBLUE);
            bar(320,140,356,160);
            hz16sChanged(322,143,"查询",1);
            setlinestyle(SOLID_LINE,0,3);
            setcolor(1);
            line(170,180,170,390);
            line(170,390,490,390);
            setlinestyle(SOLID_LINE,0,1);
            mousevisiual();
            delay(90);
			while(sign1 == 2)
            {
                mousexy(xy,button);
                newmouse(&MouseX,&MouseY,&press);
                if(xy[0]>180&&xy[0]<300&&xy[1]>140&&xy[1]<160&&button[0]==1)
                {
                    clrmous(MouseX,MouseY);
                    //mousehide();
                    //num_len0 = num_len;
					num_len = py_input_main(180,140,300,160,&hz_in[num_len],num_len);
                    strcpy(hz_in[1],hz_in[2]);
                    strcpy(hz_in[2],"\0");
					//mousevisiual();
                }
                if(xy[0]>208&&xy[0]<272&&xy[1]>110&&xy[1]<128&&button[0]==1&&sign1 != 1)     //PAGE1 -> x>208,x<272,y>110,y<128
                {
                    sign1 = 0;
                    break;
                }
                if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
                {
                    exit(0);
                }
                if(xy[0]>11&&xy[0]<139&&xy[1]>364&&xy[1]<396&&button[0]==1)           //PAGET2 -> x>11,x<139,y>364,y<396
                {
                    clrmous(MouseX,MouseY);
                    setfillstyle(1,CYAN);
                    bar(11,164,139,196);
                    hz32sChanged(11,164,"学生信息",1);
                    page = 1;
                    break;
                }
                if(num_len >= 5)
                {
                    hz16sChanged(180,170,"输入过多字符",RED);
                    delay(300);
                    setfillstyle(1,WHITE);
                    bar(180,170,320,186);
                }
                if(xy[0]>320&&xy[0]<356&&xy[1]>140&&xy[1]<160&&button[0]==1)
                {
                    clrmous(MouseX,MouseY);
                    delay(30);
                    if(num_len == 0)
                    {
                        //hz16sChanged(180,170,"姓名输入不能为空",RED);
                        delay(300);
                        setfillstyle(1,WHITE);
                        bar(180,170,320,186);
                    }
                    else
                    {
                        for(i=0;i<num_len;i++)
                        {
                            strcat(hz_in_ex,hz_in[i]);
                            /*if(num_len < num_len0)
                            {
                                strcpy(&hz_in_ex[0]+num_len,"\0");
                            }*/
                        }
                        do
                        {
                            if(phead->next == NULL)
                            {
                                hz16sChanged(180,170,"查无此人",RED);
                                delay(300);
                                setfillstyle(1,WHITE);
                                bar(180,170,320,186);
                                bar(181,141,299,159);
                                num_len = 0;
								for(i=0;i<5;i++)
								{
								strcpy(hz_in[i],"\0");
								}
                                strcpy(hz_in_ex,"\0");
                            }
							if(strcmp(phead->name,hz_in_ex)==0)
                            {
                                num_len = 0;
                                strcat(title,phead->uname);
                                strcat(title,end);
                                if((fp_stu = fopen(title,"rb")) == NULL)
                                {
                                    hz16sChanged(180,170,"文件打开失败",RED);
                                    delay(300);
                                    setfillstyle(1,WHITE);
                                    bar(180,170,320,186);
                                    //exit(1);
                                }
								strcpy(title,".\\user\\");
								fseek(fp_stu,39,SEEK_SET);
                                for(i=0;i<6;i++)
                                {
                                    fread(&time_read[i],sizeof(int),1,fp_stu);
                                }
                                fclose(fp_stu);
                                setfillstyle(1,WHITE);
                                bar(170,180,490,390);
								setcolor(LIGHTGREEN);
								poly[0] = 180;
                                poly[1] = 390-time_read[0];
                                poly[2] = 230;
                                poly[3] = 390-time_read[1];
                                poly[4] = 280;
                                poly[5] = 390-time_read[2];
                                poly[6] = 330;
								poly[7] = 390-time_read[3];
                                poly[8] = 380;
                                poly[9] = 390-time_read[4];
                                poly[10] = 430;
                                poly[11] = 390-time_read[5];
								drawpoly(6,poly);
                                setfillstyle(1,LIGHTBLUE);
                                pieslice(180,390-time_read[0],0,360,3);
                                pieslice(230,390-time_read[1],0,360,3);
                                pieslice(280,390-time_read[2],0,360,3);
                                pieslice(330,390-time_read[3],0,360,3);
                                pieslice(380,390-time_read[4],0,360,3);
                                pieslice(430,390-time_read[5],0,360,3);
                                setfillstyle(1,WHITE);
                                bar(181,141,299,159);
                                bar(180,170,320,186);
                                num_len = 0;
								for(i=0;i<5;i++)
								{
								strcpy(hz_in[i],"\0");
								}
                                strcpy(hz_in_ex,"\0");
                                break;
                            }
                            phead = phead->next;
						}while(1);
                        phead = phead_t;
                    }
                }
            }
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40&&button[0]==1)
        {
            exit(0);
        }
    }
    return page;
}