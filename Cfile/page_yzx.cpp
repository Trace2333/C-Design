#include"./include/common.h"
#include"./include/welcome.h"
#include"./include/login.h"
#include"./include/register.h"
#include"./include/page_yzx.h"

/*---------------------------------------------------------------
函数名：page_yzx
函数功能：用于登录注册以及教师端口的切换
形参：结构体loginuser；mode
返回值：无
---------------------------------------------------------------*/
void page_yzx(User *loginuser,char mode)
{
    int page = 0;
    welcome();
    while(1)
    {
        switch(page)
        {
            case 0:
			page = loginP(loginuser,mode);
            break;

            case 1:
			page = registerP(loginuser);
            break;

            default:
            break;
        }
        if(page == -1)
        break;
    }
}