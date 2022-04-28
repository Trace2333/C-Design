/*BY TRACE-2022         IMAGE.H*/
struct BitMapFileHeader{
    unsigned int head;//a stable number,0x424D.
    unsigned int size;//the size of the pictures,measured by pixel.
    unsigned int n1;//remains to be used.
    unsigned int n2;
    unsigned int start;//the start pixel.
};
struct BitMapInfoHeader{
    unsigned int DIB;//stable,0x28
    unsigned int length;
    unsigned int height;
    unsigned int color_plane;//stable,1
    unsigned int biBytes;//how many colors a pixel contains,there is 16.
    unsigned int BI_RGB;
    unsigned int n1;
    unsigned int pixel_length;//1
    unsigned int pixel_height;//2
    unsigned int n2;//tiaoseban,tongchangwei 0.
    unsigned int n3;//0,normally
};
struct BitMapContent{
    unsigned int color;
};
struct RGBTABLE{
    unsigned short int R;
    unsigned short int G;
    unsigned short int B;
    unsigned short RESERVED;
};
void image16(int X,int Y,char *filename);
void imagePut16(int X,int Y,char *filename);
void putpiece(char *filename, int Direct, int lines);
int videoControl(char *filename,int n,int *xy,int *button);
void EGAinit();
void videoPut(int x,int y,char *filename, int page);
void moveData01(int START, int END, int SIZE);
void moveData10(int START, int END, int SIZE);
void videoMove01();
void videoMove10();
void videoPutTo0(int x,int y,char *filename);
void videoPutTo1(int x,int y,char *filename);
int bmp_fast(int y1,int y2,char* path);
void Selectpage(char page);
void SVGAinit();
void SVGAPlanefind(int plane);
void SVGA640(char *filename,int videoTop,int videoButtom);
void videoControlSVGA(char *filename,int n,int *xy,int *button);
int huge detectSVGA256(void);
int letterChoose();


int mouse_press(int x1, int y1, int x2, int y2);//如果在框中点击，则返回1；在框中未点击，则返回2；不在框中则返回0
void mouse(int,int);//设计鼠标
void mouseinit(void);//初始化
//void mou_pos(int*,int*,int*);//更改鼠标位置
void mread(int *,int *,int*);//改坐标不画
void save_bk_mou(int x,int y);//存鼠标背景
void clrmous(int x,int y);//清除鼠标
void drawmous(int x,int y);//画鼠标
void newmouse(int *nx,int *ny,int *nbuttons);   //更新鼠标

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;
