#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <pages.h>
#include <stdlib.h>
#include <string.h>
#include <IMAGE.h>
#include <malloc.h>
#include <mem.h>
#include"./include/common.h"
/*
*******************************************
����:���״̬�����ָ��
��ʾ���ҵġ�ҳ
*******************************************
*/
/*
״̬��˵��:signMy���������ҵ���һ??ҳ��??����Щ��??
1-->My information
2-->Mayjor
3-->acculuate
4-->health
5-->
Infosign��ʾ�ڹ�������򿪵���Щ�ӹ���
0-->the time in Acculuate
1-->visible time in Acculuate
2-->back to the acculuate function
3-->health function
4-->pressure
5-->weight
6-->healthy life
7-->back to the health funcion
8-->pressure exam
9-->change weight and height
10-->change weight
11-->change height
*/

/*---------------------------------------------------------------
��������int pageMy(int *xy,int *button,User *loginuser)
�������ܣ������ҵ�ҳ��Ļ����Լ�����ʵ��
��ع��ܣ�������Ϣչʾ��BMi����Ϣ��չʾ���޸ģ���ӦBMi�Ľ������飬
�βΣ�int *xy,int *button,User *loginuser�������ز������û���Ϣ��
����ֵ��page
---------------------------------------------------------------*/
int pageMy(int *xy,int *button,User *loginuser)
{
    //����??����ʾ��,�ܹ�42����??
    int Times[42]={0};
    int len1 =0,len2 =0;
    char weighta[12] = "\0";
    char heighta[12] = "\0";
    int choose[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    char id[12]="\0";
    int weight=0,height=0;
    int score1=0,score2=0,score3=0,score4=0;
    int sco_all=0;char score[3]="\0";
    float xia = 0.0;
    int course = 0;
    Stuname *phead = NULL;
    Stuname *pnew = NULL;
    Stuname *pend = NULL;
    Stuname *phead_t = NULL;
    int i=0,j=0;
    char title[30] = ".\\user\\";
    int accumulated[6];
	char subject[6][7] = {"����","�٤","ƹ����","̫��","����","��ë��"};
    FILE *fp = NULL;
    FILE *fp_name = NULL;
    strcat(title,loginuser->uname);
    strcat(title,".bin");
    if((fp=fopen(title,"rb"))==NULL)
	{
		printf("can't add to user_inf.bin\n");
		return -1;
	}
    fseek(fp,39,SEEK_SET);
    for(i=0;i<42;i++)
    {
        fread(&Times[i],sizeof(int),1,fp);
    }
    fseek(fp,24,SEEK_SET);
    fread(id,12,1,fp);
    fseek(fp,123,SEEK_SET);
    fread(&height,sizeof(int),1,fp);
    fread(&weight,sizeof(int),1,fp);
    fseek(fp,37,SEEK_SET);
    fread(&course,sizeof(int),1,fp);
    fclose(fp);
    if((fp_name = fopen(".\\user\\stuname.bin","rb")) == NULL)
    {
        hz16sChanged(10,10,"��ʧ��һ",1);
        delay(300);
        exit(1);
    }
    rewind(fp_name);
    while(feof(fp_name) == 0)
    {
        if((pnew = (Stuname *)malloc(sizeof(Stuname)-2)) == NULL)
        {
            hz16sChanged(10,10,"��ʧ�ܶ�",1);
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
    for(i=0;i<6;i++)
    {
        for(j=i*7;j<i*7+7;j++)
        accumulated[i]+=Times[j];
    }
    accumulated[0]=40;accumulated[1]=20;accumulated[2]=140;accumulated[3]=70;accumulated[4]=240;accumulated[5]=140;
    for(i=0;i<6;i++)
    {
        if(accumulated[i]>=300) accumulated[i]=300;
    }
    char TimeForAccu[20];
    float BMI=0.0;
     //�����λ??һ??���ǣ��ﵽ�л�ҳ���Ч��
	//mousehide();
    clrmous(MouseX,MouseY);
    int signMy=0,Infosign=0;//signMy��������ҳ���л���Ҳ�����ڼ�??�������������л���Infosign�����ڴ�����С�������л�  
    setfillstyle(1,WHITE);
	bar(151,120,639,479);//���ұߵ���???�����?
    bar(151,0,580,120);
    bar(580,40,639,120);
    setfillstyle(1,LIGHTCYAN);
	bar(38,174,102,206);//��ߵĵ��???bar�����������°���д��??
	hz32(38,174,0xCED2,WHITE);
	hz32(70,174,0xB5C4,WHITE);
	//mousevisiual();
	//�������Ͻǵġ�ҳ��Ϣ??.���ѡ����λ????0~150
	hz32(160,20,0xCED2,BLACK);
	hz32(200,20,0xB5C4,BLACK);
	//���������ѡ������??y=110Ϊ��߷ֽ���
	//�ҵ���Ϣ
	hz16(160,110,0xCED2,BLACK);
	hz16(176,110,0xB5C4,BLACK);
	hz16(192,110,0xD0C5,BLACK);
	hz16(208,110,0xCFA2,BLACK);
	//ѧϰͳ???
	hz16(336,110,0xD1A7,BLACK);
	hz16(352,110,0xCFB0,BLACK);
	hz16(368,110,0xCDB3,BLACK);
	hz16(384,110,0xBCC6,BLACK);
	//��������
	hz16(432,110,0xBDA1,BLACK);
	hz16(448,110,0xBFB5,BLACK);
    hz16(464,110,0xB9DC,BLACK);
    hz16(480,110,0xC0ED,BLACK);
    //�˳�
    delay(200);
	while(1)
	{
		mousexy(xy,button);
		newmouse(&MouseX,&MouseY,&press);
		if(STUDY||EXPLORE||MISSION)//ҳ����ת.**�����һ�£��ĳ�ÿһ�ζ��ж�??���ǵ㵽������ҳ����ֹ???��??ͨλ??Ҳ����bar**
		{
            clrmous(MouseX,MouseY);
            setfillstyle(1,CYAN);
            bar(38,174,102,206);
            hz32(38,174,0xCED2,WHITE);
	        hz32(70,174,0xB5C4,WHITE);
			return 1;
		}
		if(xy[0]>160&&xy[0]<224&&xy[1]>110&&xy[1]<126&&button[0]==1&&signMy!=1)//��Ϣҳ��??,����Ҫ???����һ�����жϻ��ƣ�ͬʱ����signMY���ۺ���??
        {
            signMy=1;
            setcolor(WHITE);
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,126,639,479);
            setcolor(CYAN);
            line(160,136,224,136);line(160,137,224,137);//??����͵�y����??137
            //mousevisiual();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            //��Ϣ��ʾʾ��������???��һ??��Ϣָ��������ȡ���޸���??�ſ�??
            //����
            hz16(170,148,0xD0D5,BLACK);
            hz16(186,148,0xC3FB,BLACK);
            hz16(202,148,0xA3BA,BLACK);
            while(strcmp(phead->uname,"\0")!=0)
            {
                if(strcmp(phead->uname,loginuser->uname)==0)
                {
                    hz16sChanged(222,148,phead->name,1);
                }
                phead = phead->next;
            }
            phead = phead_t;
            //ѧ��
            hz16(170,168,0xD1A7,BLACK);
            hz16(186,168,0xBAC5,BLACK);
            hz16(202,168,0xA3BA,BLACK);
            outtextxy(218,179,id);
            //????
            hz16(170,188,0xB0E0,BLACK);
            hz16(186,188,0xBCB6,BLACK);
            hz16(202,188,0xA3BA,BLACK);
            outtextxy(220,199,"2101");
            hz16sChanged(265,188,"��",1);
            //����
            hz16(170,208,0xD6F7,BLACK);
            hz16(186,208,0xD0DE,BLACK);
            hz16(202,208,0xA3BA,BLACK);
            hz16sChanged(218,208,subject[course],1);
        }
        
        if(xy[0]>336&&xy[0]<400&&xy[1]>110&&xy[1]<126&&signMy!=3||Infosign==2)//ѧϰͳ???
        {
            signMy=3;
            Infosign=0;
            clrmous(MouseX,MouseY);
            setcolor(WHITE);
            //mousehide();
            setfillstyle(1,WHITE);
            bar(151,126,639,479);
            setcolor(CYAN);
            line(336,136,400,136);line(336,137,400,137);
            //mousevisiual();
            //��ʾ
			setlinestyle(SOLID_LINE,1,3);
            hz16(170,148,0xCAB1,BLACK);hz16(186,148,0xB3A4,BLACK);hz16(202,148,0xCDB3,BLACK);hz16(218,148,0xBCC6,BLACK);//ʱ��ͳ???
            //�ʼ���¼�??20??���أ�֮��������ֱ�Ӽ��?4??���ؼ��ɣ�����???��20
            hz16(180,184,0xC0BA,BLACK);hz16(196,184,0xC7F2,BLACK);//????-->BLUE
            hz16(180,220,0xE8A4,BLACK);hz16(196,220,0xD9A4,BLACK);//��?-->GREEN
            hz16(180,256,0xC6B9,BLACK);hz16(196,256,0xC5D2,BLACK);hz16(212,256,0xC7F2,BLACK);//ƹ��??-->RED
            hz16(180,292,0xCCAB,BLACK);hz16(196,292,0xBCAB,BLACK);//????--->YELLOW
            hz16(180,328,0xD7E3,BLACK);hz16(196,328,0xC7F2,BLACK);//����--->CYAN
            hz16(180,364,0xD3F0,BLACK);hz16(196,364,0xC3AB,BLACK);hz16(212,364,0xC7F2,BLACK);//��ë??-->MAGENTA
            //����ʱ�仭��.??220��ʼ��520���ߴ�Ϊ3��ɫ�ֱ�Ϊ��ɫ����ɫ����ɫ����ɫ����ɫ��????
            setcolor(DARKGRAY);
            line(240,190,520,190);//+6
            line(240,226,520,226);
            line(240,262,520,262);
            line(240,298,520,298);
            line(240,334,520,334);
            line(240,370,520,370);
            //����
            setcolor(BLUE);line(240,190,220+accumulated[0],190);//????-->BLUE
            setcolor(GREEN);line(240,226,220+accumulated[1],226);//��?-->GREEN
            setcolor(RED);line(240,262,220+accumulated[2],262);//ƹ��??-->RED
            setcolor(YELLOW);line(240,298,220+accumulated[3],298);//????--->YELLOW
            setcolor(CYAN);line(240,334,220+accumulated[4],334);//����--->CYAN
            setcolor(MAGENTA);line(240,370,220+accumulated[5],370);//��ë??-->MAGENTA
            itoa(accumulated[0],TimeForAccu,10);
			outtextxy(530,184,TimeForAccu);strcpy(TimeForAccu,"");
            itoa(accumulated[1],TimeForAccu,10);
            outtextxy(530,220,TimeForAccu);strcpy(TimeForAccu,"");
            itoa(accumulated[2],TimeForAccu,10);
            outtextxy(530,256,TimeForAccu);strcpy(TimeForAccu,"");
			itoa(accumulated[3],TimeForAccu,10);
			outtextxy(530,292,TimeForAccu);strcpy(TimeForAccu,"");
			itoa(accumulated[4],TimeForAccu,10);
			outtextxy(530,328,TimeForAccu);strcpy(TimeForAccu,"");
			itoa(accumulated[5],TimeForAccu,10);
			outtextxy(530,364,TimeForAccu);strcpy(TimeForAccu,"");
			setlinestyle(SOLID_LINE,1,1);
            //��ʾ??�ӻ�
            setfillstyle(1,GREEN);
            bar(275,400,355,430);
            hz16(291,407,0xBFC9,BLACK);hz16(307,407,0xCAD3,BLACK);hz16(323,407,0xBBAF,BLACK);
        }
        if(signMy==3&&xy[0]>275&&xy[0]<335&&xy[1]>400&&xy[1]<450&&button[0]==1&&Infosign!=1)//ͳ???ҳ�ڿ��ӻ�����---��signMy==3,Infosign=1
        {
            delay(50);
            Infosign=1;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            //������???��ʾ���ӻ���???����???Ϊһ??����??
            //����ͼ���������???��Ϊ190??400����ĳ����?345??220ÿһ??������??�ļ���?42�������?????199??241??283??325??367??409??451
			setlinestyle(SOLID_LINE,1,2);setcolor(BLACK);
			line(190,400,535,400);line(190,400,190,184);
            setlinestyle(SOLID_LINE,1,1);
            //�����ϵ�С?????
            line(187,183,193,183);line(188,182,192,182);line(189,181,191,181);line(190,180,191,180);
            line(536,403,536,397);line(537,402,537,398);line(538,401,538,399);line(539,400,539,399);
            setfillstyle(1,RED);bar(475,440,535,470);
            hz16(491,447,0xB7B5,BLACK);hz16(507,447,0xBBD8,BLACK);
			hz16(288,150,0xC6DF,BLACK);hz16(304,150,0xCCEC,BLACK);hz16(320,150,0xD6F7,BLACK);hz16(336,150,0xD0DE,BLACK);hz16(352,150,0xD1A7,BLACK);hz16(368,150,0xCFB0,BLACK);hz16(384,150,0xCDB3,BLACK);hz16(400,150,0xBCC6,BLACK); //��������??�ۿ�ͳ???
            //������Ϣ??����??��Ŀ��ȷ����ʾ��??,�ǵ�Ҫ��һ??��ͷ,ʾ��??0�ţ���Ӧ????
            Times[0]=100;Times[1]=50;Times[2]=153;Times[3]=88;Times[4]=198;Times[5]=123;Times[6]=89;
            setfillstyle(1,GREEN);
            setcolor(GREEN);
            hz16(212,420,0xD2BB,BLACK);hz16(252,420,0xB6FE,BLACK);hz16(294,420,0xC8FD,BLACK);hz16(336,420,0xCBC4,BLACK);hz16(378,420,0xCEE5,BLACK);hz16(420,420,0xC1F9,BLACK);hz16(462,420,0xC6DF,BLACK);
            //mousevisiual();
            for(i=0;i<7;i++)
            {
                bar(220+42*i,403-Times[0*7+i],223+42*i,397-Times[0*7+i]);
                if(i<6) line(220+42*i,400-Times[0*7+i],262+42*i,400-Times[0*7+i+1]);
            }
        }
        if(Infosign==1&&xy[0]>475&&xy[0]<535&&xy[1]>440&&xy[1]<490&&signMy==3)//����??�ӻ�����һ??,���˶�ͳ�Ƶ���ҳ
        {
            Infosign=2;
        }
        if(xy[0]>432&&xy[0]<496&&xy[1]>110&&xy[1]<126&&signMy!=4||Infosign==7)//��������ҳ�Ļ�???ҳ�����?
        {
            Infosign=3;
            signMy=4;
            //��������ҳ���û�Ϊ�˶��Ŀ�Ƭ��???�������ܹ���������С��һ??��������??Ϊѹ�������ع�����������??
            setcolor(WHITE);
            mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,126,639,479);//����
            setcolor(CYAN);
            line(432,136,496,136);line(432,137,496,137);
            mousevisiual();
            setfillstyle(1,YELLOW);bar(200,180,350,250);//ѹ��
            setfillstyle(1,GREEN);bar(440,180,590,250);//���ع���
            setfillstyle(1,DARKGRAY);bar(275,300,515,400);//��������
            hz32(243,199,0xD1B9,BLACK);hz32(275,199,0xC1A6,BLACK);//ѹ��
            hz32(451,199,0xCCE5,BLACK);hz32(483,199,0xD6D8,BLACK);hz32(515,199,0xB9DC,BLACK);hz32(547,199,0xC0ED,BLACK);//���ع���
            hz32(331,334,0xBDA1,CYAN);hz32(363,334,0xBFB5,CYAN);hz32(395,334,0xC9FA,CYAN);hz32(427,334,0xBBEE,CYAN);
        }
		if(signMy==4&&mouse_press(402,232,448,248) == 1&&Infosign==5)
        {
            Infosign = 9;
            setfillstyle(1,WHITE);
            bar(230,195,300,269);
            setcolor(1);
            rectangle(224,200,360,220);
            rectangle(224,230,360,250);
        }
        if(signMy==4&&mouse_press(224,200,360,220) == 1&&(Infosign==9||Infosign==11))
        {
            Infosign = 10;
            delay(9);
            clrmous(MouseX,MouseY);
			len1 = textshow(225,201,240,223,12,len1,12,weighta,0);
			weighta[len1] = '\0';
			weight = atoi(weighta);
            if((fp=fopen(title,"rb+"))==NULL)
            {
                printf("can't add to user_inf.bin\n");
                return -1;
            }
            fseek(fp,123,SEEK_SET);
            fwrite(&weight,sizeof(int),1,fp);
            fclose(fp);
		}
		if(signMy==4&&mouse_press(224,230,360,250) == 1&&(Infosign==10||Infosign==9))
		{
			Infosign = 11;
			delay(9);
			clrmous(MouseX,MouseY);
			len2 = textshow(225,231,240,253,12,len2,12,heighta,0);
			heighta[len2] = '\0';
            height = atoi(heighta);
            if((fp=fopen(title,"rb+"))==NULL)
            {
                printf("can't add to user_inf.bin\n");
                return -1;
            }
            fseek(fp,123+sizeof(int),SEEK_SET);
            fwrite(&height,sizeof(int),1,fp);
            fclose(fp);
        }
        if(signMy==4&&xy[0]>440&&xy[0]<590&&xy[1]>180&&xy[1]<250&&button[0]==1&&Infosign==3)//��������---���ع���
        {
            Infosign=5;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            setfillstyle(1,RED);
            bar(402,232,448,248);
            bar(402,440,448,456);
            hz16(192,200,0xCCE5,BLACK);hz16(208,200,0xD6D8,BLACK);//����
            hz16(192,232,0xC9ED,BLACK);hz16(208,232,0xB8DF,BLACK);//????
            hz16(412,232,0xD0DE,BLACK);hz16(428,232,0xB8C4,BLACK);//????
            hz16(412,440,0xB7B5,BLACK);hz16(428,440,0xBBD8,BLACK);//����
            hz32(182,280,0xA3C2,BLACK);hz32(214,280,0xA3CD,BLACK);hz32(246,280,0xA3C9,BLACK);//BMI
            //mousevisiual();
            //���ع����ֱ�ΪBMI���㣬�����������룬�õ���������أ����������ᣩ���ݸ�����BMI������?��������ͬ�Ľ�?????������???��Ϊ������???����ʳ��??
            char advice[20];
            char DataForPerson[20];
            //����ʾ��
            if(height == 0||weight == 0)
            {
                height = 180;
                weight = 65;
            }
            xia = (float)height*height/10000;
			BMI = (float)weight/xia;
            //�����������???,һ����??4??��???
            setfillstyle(1,LIGHTGRAY);
            bar(162,320,448,430);//��?????,ʵ���ڷ����ֵ�ʱ���������ұ߽��???10??����
            setcolor(BLACK);
            if(BMI<18.5)//��ͼƬ�͸�����???
            {
                mousehide();
                imagePut16(460,140,".\\IMAGES\\1.bmp");
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
                gcvt(weight,4,DataForPerson);
                outtextxy(230,217,DataForPerson);
                gcvt(height,4,DataForPerson);
                outtextxy(230,249,DataForPerson);
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                gcvt(BMI,4,DataForPerson);
                outtextxy(278,285,DataForPerson);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
                hz16(172,330,0xCCE5,BLACK);hz16(188,330,0xD6D8,BLACK);hz16(204,330,0xBDCF,BLACK);hz16(220,330,0xC7E1,BLACK);hz16(236,330,0xA3AC,BLACK);hz16(252,330,0xD0E8,BLACK);
                hz16(268,330,0xD2AA,BLACK);hz16(284,330,0xD4F6,BLACK);hz16(300,330,0xBCD3,BLACK);hz16(316,330,0xC9E3,BLACK);hz16(332,330,0xC8EB,BLACK);hz16(348,330,0xA3AC,BLACK);
                hz16(364,330,0xB6E0,BLACK);hz16(380,330,0xBCD3,BLACK);hz16(396,330,0xB6CD,BLACK);hz16(412,330,0xC1B6,BLACK);hz16(428,330,0xA3AC,BLACK);hz16(172,346,0xBBF1,BLACK);
                hz16(188,346,0xB5C3,BLACK);hz16(204,346,0xB8FC,BLACK);hz16(220,346,0xC7BF,BLACK);hz16(236,346,0xBDA1,BLACK);hz16(252,346,0xB5C4,BLACK);hz16(268,346,0xC9ED,BLACK);
                hz16(284,346,0xCCE5,BLACK);hz16(300,346,0xA1A3,BLACK);//���ؽ��ᣬ��Ҫ???�����룬???�Ӷ�������ø���ǿ����?????
                mousevisiual();
            }
            if(BMI>=18.5&&BMI<23.9)
            {
                mousehide();
                imagePut16(460,140,".\\IMAGES\\2.bmp");
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
                gcvt(weight,4,DataForPerson);
                outtextxy(230,217,DataForPerson);
                gcvt(height,4,DataForPerson);
                outtextxy(230,249,DataForPerson);
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                gcvt(BMI,4,DataForPerson);
                outtextxy(278,285,DataForPerson);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
                hz16(172,330,0xCCE5,BLACK);hz16(188,330,0xD6D8,BLACK);hz16(204,330,0xCACA,BLACK);hz16(220,330,0xD6D0,BLACK);hz16(236,330,0xA3AC,BLACK);hz16(252,330,0xC7EB,BLACK);
                hz16(268,330,0xBCCC,BLACK);hz16(284,330,0xD0F8,BLACK);hz16(300,330,0xB1A3,BLACK);hz16(316,330,0xB3D6,BLACK);hz16(332,330,0xC5B6,BLACK);hz16(348,330,0xA1A3,BLACK);
                //�������У�???��??����??         
                mousevisiual();   
            }
            if(BMI>=23.9&&BMI<27.9)
            {
                mousehide();
                imagePut16(460,140,".\\IMAGES\\3.bmp");
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
                gcvt(weight,4,DataForPerson);
                outtextxy(230,217,DataForPerson);
                gcvt(height,4,DataForPerson);
                outtextxy(230,249,DataForPerson);
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                gcvt(BMI,4,DataForPerson);
                outtextxy(278,285,DataForPerson);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
                hz16(172,330,0xCCE5,BLACK);hz16(188,330,0xD6D8,BLACK);hz16(204,330,0xBDCF,BLACK);hz16(220,330,0xD6D8,BLACK);hz16(236,330,0xA3AC,BLACK);hz16(252,330,0xD0E8,BLACK);
                hz16(268,330,0xD2AA,BLACK);hz16(284,330,0xD4F6,BLACK);hz16(300,330,0xBCD3,BLACK);hz16(316,330,0xD4CB,BLACK);hz16(332,330,0xB6AF,BLACK);hz16(348,330,0xA3AC,BLACK);
                hz16(364,330,0xBFD8,BLACK);hz16(380,330,0xD6C6,BLACK);hz16(396,330,0xD2FB,BLACK);hz16(412,330,0xCAB3,BLACK);hz16(428,330,0xA3AC,BLACK);hz16(172,346,0xB1DC,BLACK);
                hz16(188,346,0xC3E2,BLACK);hz16(204,346,0xCCE5,BLACK);hz16(220,346,0xD6D8,BLACK);hz16(236,346,0xBDF8,BLACK);hz16(252,346,0xD2BB,BLACK);hz16(268,346,0xB2BD,BLACK);
                hz16(284,346,0xD4F6,BLACK);hz16(300,346,0xB3A4,BLACK);hz16(316,346,0xCDAC,BLACK);hz16(332,346,0xCAB1,BLACK);hz16(348,346,0xD7A2,BLACK);hz16(364,346,0xD2E2,BLACK);
                hz16(380,346,0xCBAF,BLACK);hz16(396,346,0xC3DF,BLACK);hz16(412,346,0xA1A3,BLACK);
            //���ؽ��أ���Ҫ???���˶���������ʳ���������ؽ�һ��???����ͬʱע��˯��??
                mousevisiual();
            }
            if(BMI>=27.9)
            {
                mousehide();
                imagePut16(460,140,".\\IMAGES\\4.bmp");
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
                gcvt(weight,4,DataForPerson);
                outtextxy(230,217,DataForPerson);
                gcvt(height,4,DataForPerson);
                outtextxy(230,249,DataForPerson);
                strcpy(DataForPerson,"");
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                gcvt(BMI,4,DataForPerson);
                outtextxy(278,285,DataForPerson);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
                mousevisiual();
                hz16(172,330,0xCCE5,BLACK);hz16(188,330,0xD6D8,BLACK);hz16(204,330,0xBDCF,BLACK);hz16(220,330,0xD6D8,BLACK);hz16(236,330,0xA3AC,BLACK);hz16(252,330,0xD0E8,BLACK);
                hz16(268,330,0xD2AA,BLACK);hz16(284,330,0xD4F6,BLACK);hz16(300,330,0xBCD3,BLACK);hz16(316,330,0xD4CB,BLACK);hz16(332,330,0xB6AF,BLACK);hz16(348,330,0xA3AC,BLACK);
                hz16(364,330,0xBFD8,BLACK);hz16(380,330,0xD6C6,BLACK);hz16(396,330,0xD2FB,BLACK);hz16(412,330,0xCAB3,BLACK);hz16(428,330,0xA3AC,BLACK);hz16(172,346,0xB1DC,BLACK);
                hz16(188,346,0xC3E2,BLACK);hz16(204,346,0xCCE5,BLACK);hz16(220,346,0xD6D8,BLACK);hz16(236,346,0xBDF8,BLACK);hz16(252,346,0xD2BB,BLACK);hz16(268,346,0xB2BD,BLACK);
                hz16(284,346,0xD4F6,BLACK);hz16(300,346,0xB3A4,BLACK);hz16(316,346,0xCDAC,BLACK);hz16(332,346,0xCAB1,BLACK);hz16(348,346,0xD7A2,BLACK);hz16(364,346,0xD2E2,BLACK);
                hz16(380,346,0xCBAF,BLACK);hz16(396,346,0xC3DF,BLACK);hz16(412,346,0xA1A3,BLACK);
            }
            //ע��Ҫ����һ????�ĺ������жϵ���??

        }
        if(signMy==4&&xy[0]>402&&xy[0]<448&&xy[1]>440&&xy[1]<456&&button[0]==1&&Infosign==5)
        {
            clrmous(MouseX,MouseY);
            Infosign=7;//���ع����ķ��ؼ�
        }
        if(signMy==4&&xy[0]>200&&xy[0]<350&&xy[1]>180&&xy[1]<250&&button[0]==1&&Infosign==3)//ѹ��ҳ��ʼҳ??,����??ѹ��ҳ�ĳ�???ҳ���???
        {
            //ֱ�ӿ�ʼ��??
            Infosign=8;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            //mousevisiual();
            //hz16(315,240,0xBFAA,BLACK);hz16(331,240,0xCABC,BLACK);hz16(347,240,0xB2E2,BLACK);hz16(363,240,0xCAD4,BLACK);hz16(379,240,0xB0C9,BLACK);hz16(395,240,0xA1AB,BLACK);
            setfillstyle(1,GREEN);bar(280,280,446,350);
            hz32(299,299,0xBFAA,BLACK);hz32(331,299,0xCABC,BLACK);hz32(363,299,0xB2E2,BLACK);hz32(395,299,0xCAD4,BLACK);
            int pressureScore=0;
        }
        if(signMy==4&&xy[0]>280&&xy[0]<446&&xy[1]>280&&xy[1]<350&&Infosign==8)
        {
            button[0]=0;
            Infosign=91;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            setfillstyle(1,GREEN);
            bar(320,420,400,460);hz16s(336,432,"��һ��",BLACK,3);
            //mousevisiual();
            setcolor(BLACK);
            hz16s(200,150,"�ڹ�ȥ��һ������ж���ʱ����е��޷��ƿ���������Ҫ",BLACK,26);
            hz16s(200,166,"�����飿",BLACK,4);
            hz16s(190,198,"A.�Ӳ�",DARKGRAY,4);circle(500,206,6);
            hz16s(190,230,"B.�����Ӳ�",DARKGRAY,6);circle(500,238,6);
            hz16s(190,262,"C.��ʱ",DARKGRAY,4);circle(500,270,6);
            hz16s(190,294,"D.�Ƚ�Ƶ��",DARKGRAY,6);circle(500,302,6);
            delay(180);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>200&&xy[1]<212&&Infosign==91)
        {
            delay(30);
            score1 = 4;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,206,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>232&&xy[1]<244&&Infosign==91)
        {
            delay(30);
            score1 = 3;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,238,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>264&&xy[1]<276&&Infosign==91)
        {
            delay(30);
            score1 = 2;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,270,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>296&&xy[1]<308&&Infosign==91)
        {
            delay(30);
            score1 = 1;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,302,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,238,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>320&&xy[0]<400&&xy[1]>420&&xy[1]<460&&button[0]==1&&Infosign==91)
        {
            button[0]=0;
            Infosign=92;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            setfillstyle(1,GREEN);
            bar(320,420,400,460);hz16s(336,432,"��һ��",BLACK,3);
            //mousevisiual();
            setcolor(BLACK);
            hz16s(200,150,"�ڹ�ȥ��һ������ж���ʱ����е����鷢չ��Ԥ��һ��",BLACK,26);
            hz16s(200,166,"��",BLACK,1);
            hz16s(190,198,"A.�Ӳ�",DARKGRAY,4);circle(500,206,6);
            hz16s(190,230,"B.�����Ӳ�",DARKGRAY,6);circle(500,238,6);
            hz16s(190,262,"C.��ʱ",DARKGRAY,4);circle(500,270,6);
            hz16s(190,294,"D.�Ƚ�Ƶ��",DARKGRAY,6);circle(500,302,6);
            delay(180);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>200&&xy[1]<212&&Infosign==92)
        {
            delay(30);
            score2 = 4;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,206,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>232&&xy[1]<244&&Infosign==92)
        {
            delay(30);
            score2 = 3;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,238,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>264&&xy[1]<276&&Infosign==92)
        {
            delay(30);
            score2 = 2;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,270,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>296&&xy[1]<308&&Infosign==92)
        {
            delay(30);
            score2 = 1;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,302,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,238,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>320&&xy[0]<400&&xy[1]>420&&xy[1]<460&&button[0]==1&&Infosign==92)
        {
            button[0]=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            Infosign=93;
            setcolor(WHITE);                                                                                              
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            setfillstyle(1,GREEN);
            bar(320,420,400,460);hz16s(336,432,"��һ��",BLACK,3);
            //mousevisiual();
            setcolor(BLACK);
            hz16s(200,150,"�����Ҿ��������Լ��ĸ���",BLACK,12);
            hz16s(190,198,"A.��ȫ������",DARKGRAY,4);circle(500,206,6);
            hz16s(190,230,"B.�ȽϷ���",DARKGRAY,6);circle(500,238,6);
            hz16s(190,262,"C.����",DARKGRAY,4);circle(500,270,6);
            hz16s(190,294,"D.��ȫ����",DARKGRAY,6);circle(500,302,6);
            delay(180);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>200&&xy[1]<212&&Infosign==93)
        {
            delay(30);
            score3 = 4;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,206,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>232&&xy[1]<244&&Infosign==93)
        {
            delay(30);
            score3 = 3;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,238,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>264&&xy[1]<276&&Infosign==93)
        {
            delay(30);
            score3 = 2;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,270,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>296&&xy[1]<308&&Infosign==93)
        {
            delay(30);
            score3 = 1;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,302,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,238,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>320&&xy[0]<400&&xy[1]>420&&xy[1]<460&&button[0]==1&&Infosign==93)
        {
            button[0]=0;
            Infosign=94;
            setcolor(WHITE);
            mousehide();
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            setfillstyle(1,GREEN);
            bar(320,420,400,460);hz16s(336,432,"�����?",BLACK,3);
            mousevisiual();
            setcolor(BLACK);
            hz16s(200,150,"�Ҿ������ﷳ�һ��߾��þ���",BLACK,13);
            hz16s(190,198,"A.û��",DARKGRAY,4);circle(500,206,6);
            hz16s(190,230,"B.����ʱ��",DARKGRAY,6);circle(500,238,6);
            hz16s(190,262,"C.�൱��ʱ��",DARKGRAY,4);circle(500,270,6);
            hz16s(190,294,"D.����",DARKGRAY,6);circle(500,302,6);
            delay(180);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>200&&xy[1]<212&&Infosign==94)
        {
            delay(30);
            score4 = 4;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,206,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>232&&xy[1]<244&&Infosign==94)
        {
            delay(30);
            score4 = 3;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,238,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>264&&xy[1]<276&&Infosign==94)
        {
            delay(30);
            score4 = 2;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,270,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,238,0,360,6);
            pieslice(500,302,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>494&&xy[0]<506&&xy[1]>296&&xy[1]<308&&Infosign==94)
        {
            delay(30);
            score4 = 1;
            setfillstyle(1,LIGHTBLUE);
            pieslice(500,302,0,360,6);
            setfillstyle(1,WHITE);
            pieslice(500,270,0,360,6);
            pieslice(500,238,0,360,6);
            pieslice(500,206,0,360,6);
        }
        if(signMy==4&&xy[0]>320&&xy[0]<400&&xy[1]>420&&xy[1]<460&&button[0]==1&&Infosign==94)
        {
            Infosign = 7;
            sco_all = score1+score2+score3+score4;
            itoa(sco_all,score,10);
            hz16s(240,360,"�ܳɼ���",LIGHTGREEN,4);
            outtextxy(310,374,score);
            delay(900);
        }
        
        /*
        if(xy[0]>528&&xy[0<560&&xy[1]>110&&xy[1]<126]&&signMy!=5)//����
        {

        }*/
        if(signMy==4&&xy[0]>275&&xy[0]<515&&xy[1]>300&&xy[1]<400&&Infosign==3&&BMI==0.0)
        {
            Infosign=101;//��ʾ���ڽ��������BMI=0ҳ��
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            //mousevisiual();
            hz16s(200,150,"û���������Ŷ��������д������������~",BLACK,22);
            setfillstyle(1,DARKGRAY);
            bar(265,410,365,460);//���ذ�ť
            //hz16s(299,427,"����",BLACK,2);
        }
        if(signMy==4&&xy[0]>275&&xy[0]<515&&xy[1]>300&&xy[1]<400&&Infosign==3&&BMI>18.5&&BMI>0.0)
        {
            Infosign=102;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            hz16s(200,150,"������������ָ��Ϊ��",BLACK,10);
            setfillstyle(1,GREEN);
            bar(200,182,600,242);
			setfillstyle(1,YELLOW);
            bar(200,258,600,318);
            setfillstyle(1,CYAN);
            bar(200,334,600,394);
            setfillstyle(1,DARKGRAY);
            bar(265,410,365,460);//���ذ�ť
            hz16s(299,427,"����",BLACK,2);
            hz16s(216,204,"���أ����ع��ᣬ���岻��ǿ׳����Ҫ�����㹻��̼ˮ",BLACK,24);
            hz16s(216,280,"ǿ���������Ƽ���ѧϰ������������ʵ���������",BLACK,23);
            hz16s(216,356,"������Ϣ�����ֽ�������Ϣ�����������������",BLACK,21);
            //mousevisiual();
        }
        if(signMy==4&&xy[0]>275&&xy[0]<515&&xy[1]>300&&xy[1]<400&&Infosign==3&&BMI>23.9&&BMI<=27.9)
        {
            Infosign=103;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            hz16s(200,150,"������������ָ��Ϊ��",BLACK,10);
            setfillstyle(1,GREEN);
            bar(200,182,600,242);
			setfillstyle(1,YELLOW);
            bar(200,258,600,318);
            setfillstyle(1,CYAN);
            bar(200,334,600,394);
            setfillstyle(1,DARKGRAY);
            bar(265,410,365,460);//���ذ�ť
            hz16s(299,427,"����",BLACK,2);
            hz16s(216,204,"�������ģ��������ؽ�Ϊ���ʣ���Ҫ��������",BLACK,20);
            hz16s(216,280,"���Ӷ������ʵ����и�ǿ�ȶ���������ķ�����������",BLACK,24);
            hz16s(216,356,"������ʳ��������Ƹ������룬���ֽ�����л",BLACK,20);
            //mousevisiual();
        }
        if(signMy==4&&xy[0]>275&&xy[0]<515&&xy[1]>300&&xy[1]<400&&Infosign==3&&BMI>27.9)
        {
            Infosign=103;
            setcolor(WHITE);
            //mousehide();
            clrmous(MouseX,MouseY);
            setfillstyle(1,WHITE);
            bar(151,138,639,479);//����
            hz16s(200,150,"������������ָ��Ϊ��",BLACK,10);
            setfillstyle(1,GREEN);
            bar(200,182,600,242);
			setfillstyle(1,YELLOW);
            bar(200,258,600,318);
            setfillstyle(1,CYAN);
            bar(200,334,600,394);
            setfillstyle(1,DARKGRAY);
            bar(265,410,365,460);//���ذ�ť
            hz16s(299,427,"����",BLACK,2);
            hz16s(216,204,"��֬�����ؽ��أ�����ѡ��ʳ�ø�����߲˹���",BLACK,21);
            hz16s(216,280,"ǿ���������Ƽ�ѧϰ����������������Ӷ���������ǿ��",BLACK,26);
            hz16s(216,356,"������Ϣ����˯���𣬱��ⰾҹ�����ʺ��ػ��ۡ�",BLACK,22);
            //mousevisiual();
        }
        if(signMy==4&&xy[0]>265&&xy[0]<365&&xy[1]>410&&xy[1]<460&&(Infosign==101||Infosign==102||Infosign==103||Infosign==104||Infosign==105))
        {
            Infosign=7;
        }
        if(xy[0]>580&&xy[0]<639&&xy[1]>0&&xy[1]<40)
        {
			exit(0);
        }
    }
}