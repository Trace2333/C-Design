#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bios.h>
#include<dos.h>
#include"./include/user.h"
#include"./include/file.h"
/*---------------------------------------------------------------
file——student.cpp
函数功能：用户个人文件快速初始化建立；
形参：无
返回值：无
---------------------------------------------------------------*/
void main()
{
    FILE *fp;
    int time_re[7]={0,0,0,0,0,0,0};
    char title[30] = ".\\user\\";
    char un[10][12] = {"zl","sh","gy","xh","lr","yl","wd","ht","tm","bc"};
    long int i =202114930;
    long int k=0;
	int j = 0;
    int p=0;
    char ck[11] = "\0";
    char u[12] = "U";
    User news;
    k = i+j;
    ltoa(k,ck,10);
    strcat(u,ck);
    strcat(title,un[0]);
    strcat(title,".bin");
    if((fp=fopen(".\\user\\stu.bin","wb+")) == NULL)
    {
        printf("error1\n");
        exit(1);
    }
	strcpy(news.uname,un[0]);
	strcpy(news.upass,"123456");
	strcpy(news.ID,u);
	news.mode = '0';
    srand((unsigned int)time(0));
    news.height = rand()%185+160;
    news.weight = rand()%90+50;
    news.ucourse = rand()%5+0;
    fwrite(&news,sizeof(User),1,fp);
    fclose(fp);
	rename(".\\user\\stu.bin",title);
    time_add2(un[0]);

    if((fp=fopen(title,"rb")) == NULL)
    {
        printf("error2\n");
        exit(1);
    }
    fseek(fp,67,SEEK_SET);
    for(p=0;p<7;p++)
    {
    fread(&time_re[p],sizeof(int),1,fp);
    printf("%d\t",time_re[p]);
    }
    fclose(fp);
}