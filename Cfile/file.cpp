#include"./include/common.h"
#include"./include/file.h"
#include"./include/user.h"

/*---------------------------------------------------------------
��������File_userinit
�������ܣ��û���ʼ����
�βΣ��ṹ��loginuser��
����ֵ����
---------------------------------------------------------------*/
void File_userinit(User *loginuser)
{
	int i=0,j=0;
	char init[3] = "\0";
    strcpy(loginuser->ID,init);
    strcpy(loginuser->uname,init);
    strcpy(loginuser->upass,init);
    loginuser->ucourse = 0; 
	loginuser->mode = 0;       //39
	for(i=0;i<6;i++)
	{
	for(j=0;j<7;j++)
	{
	loginuser->time[i][j] = 0;
	}
	}
	loginuser->height = 0;
	loginuser->weight = 0;
}

/*---------------------------------------------------------------
��������void File_userdatacopy(User *loginuser,const User *copy);
�������ܣ�����copy��loginuser��
�βΣ��ṹ��loginuser���ṹ��copy��
����ֵ��1��
---------------------------------------------------------------*/
int File_userdatacopy(User *loginuser,const User *copy)
{
    strcpy(loginuser->ID,copy->ID);
    strcpy(loginuser->uname,copy->uname);
    strcpy(loginuser->upass,copy->upass);
	loginuser->ucourse=copy->ucourse;
	loginuser->mode = copy->mode;
	return 1;
}

/*---------------------------------------------------------------
��������int File_useradd(User *loginuser,char *id,char *name,char *pass,int course,int smode);
�������ܣ�Ϊ��ǰ�û������ļ������˺š����룬ͬʱ���ش���״̬��
�βΣ��ṹ��loginuser�������ѧ�ţ�������˺ţ���������룻ѡ��Ŀγ� 
����ֵ��δ�ܴ��ļ�����-1,��ע��ɹ�����1��
---------------------------------------------------------------*/
int File_useradd(User *loginuser,char *id,char *name,char *pass,int course,char smode)
{
    FILE *fp = NULL;
	File_userinit(loginuser);
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
    if((fp=fopen(".\\user\\user_inf.bin","wb+"))==NULL)
	{
		printf("can't add to user_inf.bin\n");
		return -1;
	}
    strcpy(loginuser->ID,id);
    strcpy(loginuser->uname,name);
	strcpy(loginuser->upass,pass);
    loginuser->ucourse = course;
    loginuser->mode = smode;
    fwrite(loginuser,sizeof(User),1,fp);
	fclose(fp);
	rename(".\\user\\user_inf.bin",title);
    return 1;
}

/*---------------------------------------------------------------
��������int File_userfind(User *loginuser,char *name,char *pass);
�������ܣ����ݵ�ǰ�û�������˺š��������ļ���Ѱ���Ƿ����ƥ���������Ѱ�ҽ����
�βΣ��ṹ��loginuser��������˺�name����������룻
����ֵ��δ�ܴ��ļ�����-1;�˺š������ƥ�䷵��1;
	   ֻ�ҵ��û�������-2;��δ�ҵ�����-3;
---------------------------------------------------------------*/
int File_userfind(User *loginuser,char *name,char *pass)
{
    FILE *fp=NULL;
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	User temp;
	if((fp=fopen(title,"rb"))==NULL)
	{
		printf("can't read user.bin\n");
		return -1;
	}
	rewind(fp);
    fread(&temp,sizeof(User),1 ,fp);
    if(strcmp(temp.uname,name)==0)//���ҵ��û���
	{
		if(strcmp(temp.upass,pass)==0)//�ҵ��û������ҵ�����
		{
			File_userinit(loginuser);
			if(File_userdatacopy(loginuser,&temp)==1)//�ҵ�֮�����������
			{
				fclose(fp);
				strcpy(loginuser->uname,name);
				strcpy(loginuser->upass,pass);//���û��������봢�浱ǰ��¼�û�
				return 1;
			}
		}
		else//���벻��
		{
			fclose(fp);
			return -2;
		}
	}
	else//���û���
	{	
		fclose(fp);//�ر��ļ�
		return -3;//�������
	}
}

/*----------------------------------------------------------------------------
��������int File_changepass(User *loginuser,char *name,char *pass)
�������ܣ��޸��û�����
�βΣ������˺ţ��������ַpass��loginuser�ṹ��
����ֵ��-1δ�ܴ��ļ�����0�޸ĳɹ���2δ�ҵ����û�
-----------------------------------------------------------------------------*/
int File_changepass(User *loginuser,char *name,char *pass)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	FILE *fp=NULL;
	User copy;
	fp=fopen(title,"rb+");//��д
	if(fp==NULL)
    {
		printf("can't open user_inf.bin when File_changepass in file.c");
		return -1;
	}
	rewind(fp);
	fread(&copy,sizeof(User),1,fp);
	if(strcmp(copy.ID,loginuser->ID)==0)
	{
		strcpy(copy.upass,pass);
		strcpy(loginuser->upass,pass);
		fseek(fp,0,SEEK_SET);
		fwrite(&copy,sizeof(User),1,fp);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return 2;
}

/*----------------------------------------------------------------------------
��������int File_changecourse(User *loginuser,char *course)
�������ܣ��޸��û�ѡ��
�βΣ�������ѡ�ε�ַcourse��loginuser�ṹ��
����ֵ��-1δ�ܴ��ļ�����0�޸ĳɹ���2δ�ҵ����û�
-----------------------------------------------------------------------------*/
int File_changecourse(User *loginuser,char *name,int *course)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	FILE *fp=NULL;
	User copy,del;
	fp=fopen(title,"rb+");//��д
	if(fp==NULL)
    {
		printf("can't open user_inf.bin when File_changecourse in file.c");
		return -1;
	}
	fread(&copy,sizeof(User),1,fp);
	if(strcmp(copy.ID,loginuser->ID)==0)
	{
		copy.ucourse=*course;
		loginuser->ucourse=*course;
		fseek(fp,0,SEEK_SET);
		fwrite(&copy,sizeof(User),1,fp);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return 2;
}

/*----------------------------------------------------------------------------
��������void time_add��User *loginuser,int *time);
�������ܣ�д���û�ѧϰʱ��
�βΣ������û���,ʱ�����飻
����ֵ��-1δ�ܴ��ļ�����0д��ɹ���
-----------------------------------------------------------------------------*/
int time_add(User *loginuser,int time,int course_num)
{
	char title[30] = ".\\user\\";
	strcat(title,loginuser->uname);
    strcat(title,".bin");
	FILE *fp=NULL;
	fp=fopen(title,"rb+");//��д
	if(fp==NULL)
    {
		printf("can't open user_inf.bin when time_add in file.c");
		return -1;
	}
	switch(course_num)
	{
		case 0:
			fseek(fp,51,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 1:
		    fseek(fp,65,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 2:
			fseek(fp,79,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 3:
			fseek(fp,93,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 4:
			fseek(fp,107,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 5:
			fseek(fp,121,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		case 6:
			fseek(fp,138,SEEK_SET);
			fwrite(&time,sizeof(int),1,fp);
			break;
		default:
		break;
	}
	fclose(fp);
	return 0;
}

/*----------------------------------------------------------------------------
��������void time_add2(char *uname);
�������ܣ�д���û���ʷѧϰʱ��
�βΣ������û�����
����ֵ��-1δ�ܴ��ļ�����0д��ɹ���
-----------------------------------------------------------------------------*/
void time_add2(char *uname)
{
	int time_num = 0;
	int i = 0,j = 0;
	int time_fake[6][7];
	char title[30] = ".\\user\\";
	strcat(title,uname);
    strcat(title,".bin");
	FILE *fp=NULL;
	fp=fopen(title,"rb+");//��д
	if(fp==NULL)
    {
		printf("can't open user_inf.bin in file.c");
		exit(1);
	}
	srand((unsigned int)time(0));
	for(j=0;j<6;j++)
	{
		for(i=0;i<7;i++)
		{
			time_num = rand()%200+0;
			time_fake[j][i] = time_num;
		}
	    fseek(fp,39+j*14,SEEK_SET);
	    fwrite(time_fake[j],7*sizeof(int),1,fp);
	}
	fclose(fp);
}

/*----------------------------------------------------------------------------
��������int File_delete(char *name)
�������ܣ�ע���û�
�βΣ������û�����ַname��
����ֵ��0�޸ĳɹ���
-----------------------------------------------------------------------------*/
int File_delete(char *name)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	remove(title);
	return 0;
}
