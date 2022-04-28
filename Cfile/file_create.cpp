#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bios.h>
#include<dos.h>
#include"./include/user.h"
/*---------------------------------------------------------------
file_create.cpp
�������ܣ��û��ļ����ٳ�ʼ��������
�βΣ���
����ֵ����
---------------------------------------------------------------*/
void main()
{
    FILE *fp;
    int j=0;
    long int i =202114930;
    long int k=0;
    char ck[11] = "\0";
    char u[12] = "U";
    Stuname *phead = NULL;
    Stuname *pnew = NULL;
    Stuname *pend = NULL;
	char n[10][5] = {"����","���","����","�ĺ�","���","��ǉ","�µ�","����","����","����"};
    char un[10][12] = {"zl","sh","gy","xh","lr","yl","wd","ht","tm","bc"};
	if((fp=fopen(".\\user\\stuname.bin","wb+")) == NULL)
    {
        printf("error\n");
        exit(1);
    }
	while(j<10)
	{
		if((pnew = (Stuname *)malloc(sizeof(Stuname))) == NULL)
		{
			delay(300);
			exit(1);
		}
		k = i+j;
		ltoa(k,ck,10);
		strcat(u,ck);
		strcpy(pnew->name,n[j]);
		strcpy(pnew->uname,un[j]);
		strcpy(pnew->Stuid,u);
		strcpy(u,"U");
        j++;
		if(phead == NULL)
		{
			phead = pnew,pend = phead;
		}
		else{
			pend->next = pnew;
			pend = pnew;
		}
	}
	pend->next = NULL;
	free(pnew);
    while(phead->next != NULL)
    {
        fwrite(phead,sizeof(Stuname),1,fp);
        phead = phead->next;
    }
	fclose(fp);
}