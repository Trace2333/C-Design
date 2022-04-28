#ifndef _FILE_H_
#define _FILE_H_
#include"user.h"

void File_userinit(User *loginuser);
int File_userdatacopy(User *loginuser,const User *copy);
int File_useradd(User *loginuser,char *id,char *name,char *pass,int course,char smode);
int File_userfind(User *loginuser,char *name,char *pass);
int File_changepass(User *loginuser,char *name,char *pass);
int File_changecourse(User *loginuser,char *name,int *course);
int time_add(User *loginuser,int *time);
void time_add2(char *uname);
int File_delete(char *name);

#endif