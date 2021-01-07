
#include "logic.h"
#include "key.h"
#include "lcd_driver.h"
#include "input.h"

#define PAGEID_STARTPAGE    0
#define PAGEID_SHOUDONG     1
#define PAGEID_FUNCTION     2
#define PAGEID_ADVANCE      3
#define PAGEID_MONITOR      4
#define PAGEID_INFOMATION   5


static uint8_t PageId=0,firststartflag=0;

void PagePro_SwitchPage(void);

void PagePro_StartPage(void);
void PagePro_ShoudongPage(void);
void PagePro_FunctionPage(void);
void PagePro_Monitor(void);
void PagePro_Auto(void);
void PagePro_Security(void);
void PagePro_Program(void);
void PagePro_Time(void);
void PagePro_Version(void);
void PagePro_Update(void);

void PageDraw_Shoudong(void);
void PageDraw_StartPage(void);
void PageDraw_Function(void);
void PageDraw_Advance(void);
void PageDraw_Monitor(void);
void PageDraw_Infomation(void);
void PageDraw_Auto(void);
void PageDraw_Security(void);
void PageDraw_Program(void);
void PageDraw_Time(void);
void PageDraw_Version(void);
void PageDraw_Update(void);

void PageDraw_Monitor_Light(uint8_t light_id,uint8_t state);

void MainStateCtrl(void)
{
    PagePro_SwitchPage();
    switch (PageId)
    {
    case PAGEID_STARTPAGE:
        PagePro_StartPage();
        break;
    case PAGEID_SHOUDONG:
        PagePro_ShoudongPage();
        break;
    case PAGEID_FUNCTION:
        PagePro_FunctionPage();
        break;
    case PAGEID_ADVANCE:

        break;
    case PAGEID_MONITOR:
        PagePro_Monitor();
        break;
    
    default:
        break;
    }
    //PageId = 0;
}

void PagePro_SwitchPage(void)
{
    switch (KeyId)
    {
    case KEY_MANU:
        if(PageId != PAGEID_SHOUDONG)
        {
            PageDraw_Shoudong();
            PageId = PAGEID_SHOUDONG;
        }
        KeyId = 0;
        break;
    case KEY_FUNC:
        if(PageId != PAGEID_FUNCTION)
        {
            PageDraw_Function();
            PageId = PAGEID_FUNCTION;
        }
        KeyId = 0;
        break;
    case KEY_STOP:
        if(PageId != PAGEID_STARTPAGE)
        {
            PageDraw_StartPage();
            PageId = PAGEID_STARTPAGE;
        }
        KeyId = 0;
        break;
    case KEY_MONIT:
        if(PageId != PAGEID_MONITOR)
        {
            PageDraw_Monitor();
            PageId = PAGEID_MONITOR;
        }
        KeyId = 0;
        break;
    case KEY_INFO:
        if(PageId != PAGEID_INFOMATION)
        {
            PageDraw_Infomation();
            PageId = PAGEID_INFOMATION;
        }
        KeyId = 0;
        break;
    default:
        break;
    }
}

void PagePro_StartPage(void)
{
    if(firststartflag == 0)
    {
        firststartflag = 1;
        PageDraw_StartPage();
    }

}

void PagePro_ShoudongPage(void)
{

}

void PagePro_FunctionPage(void)
{


}

void PagePro_Monitor(void)
{
    uint8_t i;
    static uint8_t input_id;
    static uint16_t last_state;
    uint16_t state;
    /*
    for(i=0;i<14;i++)
    {
        state = Input_GetState(i);
        if(((last_state>>i)&0x01) ^ state == 1)//different
        {
            PageDraw_Monitor_Light(i,state);
            last_state &= !(0x0001<<i);
            last_state |= ((uint16_t)state << i);
        }
    }
    */

    PageDraw_Monitor_Light(input_id,Input_GetState(input_id));
    input_id ++;
    if(input_id >= 14)input_id=0;
}

void PagePro_Auto(void)
{
    ;//
}

void PagePro_Security(void)
{
    ;//
}

void PagePro_Program(void)
{
    ;//
}

void PagePro_Time(void)
{
    ;//
}

void PagePro_Version(void)
{
    ;//
}

void PagePro_Update(void)
{
    ;//
}


void PageDraw_Shoudong(void)
{
    
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_ShowString(30,63,"当前程式：",BLACK);
    LCD_Rect_Round(19,92,112,34,1,1,GRAY);
    LCD_Rect_Round_Fill(20,93,110,16,1,BLUE);
    LCD_Rect_Round(19,143,112,34,1,1,GRAY);
    LCD_Rect_Round_Fill(20,144,110,16,1,BLUE);
    LCD_Rect_Round_Fill(182,93,110,53,1,TEAL);
    LCD_Rect_Round_Fill(182,93,110,16,1,GREEN);
    LCD_ShowString(46,93,"手臂选择",WHITE);
    LCD_ShowString(57,108,"双臂",BLACK);
    LCD_ShowString(46,144,"Sp",WHITE);
    LCD_ShowString(46+28,144,"键功能",WHITE);
    LCD_ShowString(50,160,"预留输出",BLACK);
}

void PageDraw_StartPage(void)
{
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_Line(3,38,130,134,1,SILVER);
    LCD_Line(3,229,130,134,1,SILVER);
    LCD_Line(130,134,349,134,1,SILVER);
    LCD_Line(349,134,478,38,1,SILVER);
    LCD_Line(349,134,478,229,1,SILVER);
    LCD_ShowString(70,10,"主页面",BLACK);
    LCD_ShowString(230,110,"智能型斜臂系统",BLACK);
}

void PageDraw_Function(void)
{
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_Rect_Round(13,43,225,171,2,1,GRAY);
    LCD_Rect_Round(248,43,220,171,2,1,GRAY);
    LCD_Rect_Round_Fill(14,44,223,21,2,SILVER);
    LCD_ShowString(17,47,"语言选择",WHITE);
    LCD_ShowString(17,47+20*1,"顶针控制",BLACK);
    LCD_ShowString(17,47+20*2,"主夹检测",BLACK);
    LCD_ShowString(17,47+20*3,"副夹检测",BLACK);
    LCD_ShowString(17,47+20*4,"真空检测",BLACK);
    LCD_ShowString(17,47+20*5,"夹吸检知",BLACK);

    LCD_ShowString(256,47+20*0,"产量设定",BLACK);
    LCD_ShowString(256,47+20*1,"预留O1模数",BLACK);
    LCD_ShowString(256,47+20*2,"预留O2模数",BLACK);
    LCD_ShowString(256,47+20*3,"预留O3模数",BLACK);
    LCD_ShowString(256,47+20*4,"预留I1模数",BLACK);
    LCD_ShowString(256,47+20*5,"预留I2模数",BLACK);
    LCD_ShowString(256,47+20*6,"预留I3模数",BLACK);
}

void PageDraw_Advance(void)
{
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_Rect_Round(13,43,225,171,2,1,GRAY);
    LCD_Rect_Round(248,43,220,171,2,1,GRAY);
    LCD_Rect_Round_Fill(14,44,223,21,2,SILVER);

    LCD_ShowString(17,47+20*0,"单双臂选择",WHITE);
    LCD_ShowString(17,47+20*1,"上下报警时间",BLACK);
    LCD_ShowString(17,47+20*2,"旋动报警时间",BLACK);
    LCD_ShowString(17,47+20*3,"预留报警时间",BLACK);
    LCD_ShowString(17,47+20*4,"手动关模",BLACK);
    LCD_ShowString(17,47+20*5,"屏幕亮度设置",BLACK);
    LCD_ShowString(17,47+20*6,"恢复出厂设置",BLACK);

    LCD_ShowString(256,47+20*0,"气压检测",BLACK);
}

void PageDraw_Monitor(void)
{
    uint8_t i;
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_Rect_Round(11,39,232,180,2,1,SILVER);
    LCD_Rect_Round(243,39,232,180,2,1,SILVER);
    
    LCD_Rect_Round_Fill(12,40,230,17,2,GREEN);
    LCD_Rect_Round_Fill(244,40,230,17,2,PINK);

    LCD_ShowString(72,39,"监视输入限",BLACK);
    LCD_ShowString(323,39,"监视输出阀",BLACK);

    LCD_ShowString(17,60+20*0,"X01主上限",BLACK);
    LCD_ShowString(17,60+20*1,"X02主夹限",BLACK);
    LCD_ShowString(17,60+20*2,"X03真空限",BLACK);
    LCD_ShowString(17,60+20*3,"X04旋入限",BLACK);
    LCD_ShowString(17,60+20*4,"X05旋出限",BLACK);
    LCD_ShowString(17,60+20*5,"X06副上限",BLACK);
    LCD_ShowString(17,60+20*6,"X07副夹限",BLACK);
    LCD_ShowString(17,60+20*7,"X08气压限",BLACK);

    LCD_ShowString(140,60+20*0,"X09预留I1",BLACK);
    LCD_ShowString(140,60+20*1,"X10预留I2",BLACK);
    LCD_ShowString(140,60+20*2,"X11预留I3",BLACK);
    LCD_ShowString(140,60+20*3,"X12中模限",BLACK);
    LCD_ShowString(140,60+20*4,"X13安全门",BLACK);
    LCD_ShowString(140,60+20*5,"X14开模完",BLACK);    

    LCD_ShowString(249,60+20*0,"Y01主下降",BLACK);
    LCD_ShowString(249,60+20*1,"Y02主前进",BLACK);
    LCD_ShowString(249,60+20*2,"Y03主夹阀",BLACK);
    LCD_ShowString(249,60+20*3,"Y04旋入阀",BLACK);
    LCD_ShowString(249,60+20*4,"Y05旋出阀",BLACK);
    LCD_ShowString(249,60+20*5,"Y06真空阀",BLACK);
    LCD_ShowString(249,60+20*6,"Y07副下降",BLACK);
    LCD_ShowString(249,60+20*7,"Y08副前进",BLACK);

    LCD_ShowString(369,60+20*0,"Y09副夹阀",BLACK);
    LCD_ShowString(369,60+20*1,"Y10预留O1",BLACK);
    LCD_ShowString(369,60+20*2,"Y11预留O2",BLACK);
    LCD_ShowString(369,60+20*3,"Y12预留O3",BLACK);
    LCD_ShowString(369,60+20*4,"Y13模安全",BLACK);
    LCD_ShowString(369,60+20*5,"Y14可锁模",BLACK);
    LCD_ShowString(369,60+20*6,"Y15可顶针",BLACK);
    LCD_ShowString(369,60+20*7,"Y16报警阀",BLACK);

    for(i=0;i<14;i++)
    {
        PageDraw_Monitor_Light(i,Input_GetState(i));
    }

}

void PageDraw_Infomation(void)
{

}

void PageDraw_Auto(void)
{
    ;//
}

void PageDraw_Security(void)
{
    ;//
}

void PageDraw_Program(void)
{
    ;//
}

void PageDraw_Time(void)
{
    ;//
}

void PageDraw_Version(void)
{
    ;//
}

void PageDraw_Update(void)
{
    ;//
}


void PageDraw_Monitor_Light(uint8_t light_id,uint8_t state)
{
    if(light_id < 8)
    {
        LCD_Circle(104,67+20*light_id,5,1,1,state?GREEN:RED);
    }
    else
    {
        LCD_Circle(224,67+20*(light_id-8),5,1,1,state?GREEN:RED);
    }
}
