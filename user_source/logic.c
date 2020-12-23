
#include "logic.h"
#include "key.h"
#include "lcd_driver.h"

#define PAGEID_STARTPAGE    0
#define PAGEID_SHOUDONG     1

static uint8_t PageId=0,firststartflag=0;

void PagePro_StartPage(void);
void PagePro_ShoudongPage(void);

void PageDraw_Shoudong(void);
void PageDraw_StartPage(void);


void MainStateCtrl(void)
{
    switch (PageId)
    {
    case PAGEID_STARTPAGE:
        PagePro_StartPage();
        break;
    case PAGEID_SHOUDONG:
        PagePro_ShoudongPage();
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    
    default:
        break;
    }
    //PageId = 0;
}

void PagePro_StartPage(void)
{
    if(firststartflag == 0)
    {
        firststartflag = 1;
        PageDraw_StartPage();
    }
    if(KeyId == 19)
    {
        KeyId = 0;
        PageDraw_Shoudong();
        PageId = PAGEID_SHOUDONG;
    }
}

void PagePro_ShoudongPage(void)
{
    if(KeyId == 1)
    {
        KeyId = 0;
        PageDraw_StartPage();
        PageId = PAGEID_STARTPAGE;
    }
}


void PageDraw_Shoudong(void)
{
    
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_ShowHanziString(30,63,"当前程式：",BLACK);
    LCD_Rect_Round(19,92,112,34,1,1,GRAY);
    LCD_Rect_Round_Fill(20,93,110,16,1,BLUE);
    LCD_Rect_Round(19,143,112,34,1,1,GRAY);
    LCD_Rect_Round_Fill(20,144,110,16,1,BLUE);
    LCD_Rect_Round_Fill(182,93,110,53,1,TEAL);
    LCD_Rect_Round_Fill(182,93,110,16,1,GREEN);
    LCD_ShowHanziString(46,93,"手臂选择",WHITE);
    LCD_ShowHanziString(57,108,"双臂",BLACK);
    LCD_ShowString(46,144,"Sp",WHITE);
    LCD_ShowHanziString(46+28,144,"键功能",WHITE);
    LCD_ShowHanziString(50,160,"预留输出",BLACK);
}

void PageDraw_StartPage(void)
{
    LCD_Rect_Fill(0,39,480,190,WHITE);
    LCD_Line(3,38,130,134,1,SILVER);
    LCD_Line(3,229,130,134,1,SILVER);
    LCD_Line(130,134,349,134,1,SILVER);
    LCD_Line(349,134,478,38,1,SILVER);
    LCD_Line(349,134,478,229,1,SILVER);
    LCD_ShowHanziString(70,10,"主页面",BLACK);
    LCD_ShowHanziString(230,110,"智能型斜臂系统",BLACK);
}

