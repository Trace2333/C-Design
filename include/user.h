#ifndef _USER_H_
#define _USER_H_

typedef struct
{
    char uname[12];
    char upass[12];
    char ID[12];//36
    char mode;       
    int ucourse; //39
    int time[6][7]; //123
    int height;
    int weight;  //127
}User;


typedef struct stuname
{
    char name[5];
    char Stuid[12];
    char uname[12];
    struct stuname *next;
}Stuname;


#endif