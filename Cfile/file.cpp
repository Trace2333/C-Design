#include"./include/common.h"
#include"./include/file.h"
#include"./include/user.h"

/*---------------------------------------------------------------
函数名：File_userinit
函数功能：用户初始化；
形参：结构体loginuser；
返回值：无
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
函数名：void File_userdatacopy(User *loginuser,const User *copy);
函数功能：复制copy到loginuser；
形参：结构体loginuser；结构体copy；
返回值：1；
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
函数名：int File_useradd(User *loginuser,char *id,char *name,char *pass,int course,int smode);
函数功能：为当前用户创建文件储存账号、密码，同时返回储存状态；
形参：结构体loginuser；输入的学号；输入的账号；输入的密码；选择的课程 
返回值：未能打开文件返回-1,；注册成功返回1；
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
函数名：int File_userfind(User *loginuser,char *name,char *pass);
函数功能：根据当前用户输入的账号、密码在文件中寻找是否存在匹配项，并返回寻找结果；
形参：结构体loginuser；输入的账号name；输入的密码；
返回值：未能打开文件返回-1;账号、密码均匹配返回1;
	   只找到用户名返回-2;都未找到返回-3;
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
    if(strcmp(temp.uname,name)==0)//若找到用户名
	{
		if(strcmp(temp.upass,pass)==0)//找到用户名又找到密码
		{
			File_userinit(loginuser);
			if(File_userdatacopy(loginuser,&temp)==1)//找到之后就载入数据
			{
				fclose(fp);
				strcpy(loginuser->uname,name);
				strcpy(loginuser->upass,pass);//将用户名与密码储存当前登录用户
				return 1;
			}
		}
		else//密码不对
		{
			fclose(fp);
			return -2;
		}
	}
	else//无用户名
	{	
		fclose(fp);//关闭文件
		return -3;//密码错误
	}
}

/*----------------------------------------------------------------------------
函数名：int File_changepass(User *loginuser,char *name,char *pass)
函数功能：修改用户密码
形参：输入账号，新密码地址pass；loginuser结构体
返回值：-1未能打开文件报错；0修改成功；2未找到该用户
-----------------------------------------------------------------------------*/
int File_changepass(User *loginuser,char *name,char *pass)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	FILE *fp=NULL;
	User copy;
	fp=fopen(title,"rb+");//读写
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
函数名：int File_changecourse(User *loginuser,char *course)
函数功能：修改用户选课
形参：输入新选课地址course；loginuser结构体
返回值：-1未能打开文件报错；0修改成功；2未找到该用户
-----------------------------------------------------------------------------*/
int File_changecourse(User *loginuser,char *name,int *course)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	FILE *fp=NULL;
	User copy,del;
	fp=fopen(title,"rb+");//读写
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
函数名：void time_add（User *loginuser,int *time);
函数功能：写入用户学习时间
形参：输入用户名,时间数组；
返回值：-1未能打开文件报错；0写入成功；
-----------------------------------------------------------------------------*/
int time_add(User *loginuser,int time,int course_num)
{
	char title[30] = ".\\user\\";
	strcat(title,loginuser->uname);
    strcat(title,".bin");
	FILE *fp=NULL;
	fp=fopen(title,"rb+");//读写
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
函数名：void time_add2(char *uname);
函数功能：写入用户历史学习时间
形参：输入用户名；
返回值：-1未能打开文件报错；0写入成功；
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
	fp=fopen(title,"rb+");//读写
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
函数名：int File_delete(char *name)
函数功能：注销用户
形参：输入用户名地址name；
返回值：0修改成功；
-----------------------------------------------------------------------------*/
int File_delete(char *name)
{
	char title[30] = ".\\user\\";
	strcat(title,name);
    strcat(title,".bin");
	remove(title);
	return 0;
}
