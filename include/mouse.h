#ifndef _MOUSE_H_
#define _MOUSE_H_

void graphinit();
void mouseinit();
void mousexy(int *xy,int *button);
void mousehide();
void mousevisiual();
void mouseCreate();
int mousey();
int mousex();
int mouseLeftStatus();

void mouseinit();
void mouse(int x,int y);
void mread(int *nx,int *ny,int *nbuttons);
void newmouse(int *nx,int *ny,int *nbuttons);
void save_bk_mou(int nx,int ny);
void clrmous(int nx,int ny);
int mouse_press(int x1, int y1, int x2, int y2);
void drawmous(int nx,int ny);

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;

#endif
