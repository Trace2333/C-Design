#include"./include/common.h"
#include"./include/pageSign.h"
#include"./include/pageT.h"
#include"./include/pageT1.h"
#include"./include/pageT2.h"
/*---------------------------------------------------------------
��������void pageTeacher()
�������ܣ����ڽ�ʦ�˿������ҳ���л�
�βΣ���
����ֵ����
---------------------------------------------------------------*/
void pageTeacher()
{
    int page = 0;
    clrmous(MouseX,MouseY);
    setbkcolor(WHITE);
    setfillstyle(1,CYAN);
    bar(0,0,150,479);
	int poly1[8]={0,0,150,0,150,479,0,479};
	fillpoly(4,poly1);
    setcolor(WHITE);
    line(0,120,150,120);
    pageSign(0,10,4);
    setfillstyle(1,RED);
	bar(580,0,636,40);
    puthz(593,12,"�˳�",16,16,1);
    puthz(11,164,"ѧ����Ϣ",32,32,1);
    puthz(11,364,"���񷢲�",32,32,1);
    while(1)
    {
        switch (page)
        {
        case 0:
			page = patFir();
			break;

		case 1:
			page = patSec();
			break;

        default:
            break;
        }
    }
}