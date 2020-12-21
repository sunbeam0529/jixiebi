#include "key.h"
#include "BEEP.H"
#include "lcd_driver.h"
/*
K1 PB1
K2 PB2 
K3 PE7
K4 PE8
K5 PE9
K6 PE10
K7 PE11
K8 PE12
K9 PE13
K10 PE14

*/

#define KEY1_PORT GPIOB
#define KEY2_PORT GPIOB
#define KEY3_PORT GPIOE
#define KEY4_PORT GPIOE
#define KEY5_PORT GPIOE
#define KEY6_PORT GPIOE
#define KEY7_PORT GPIOE
#define KEY8_PORT GPIOE
#define KEY9_PORT GPIOE
#define KEY10_PORT GPIOE

#define KEY1_PIN GPIO_PIN_1
#define KEY2_PIN GPIO_PIN_2
#define KEY3_PIN GPIO_PIN_7
#define KEY4_PIN GPIO_PIN_8
#define KEY5_PIN GPIO_PIN_9
#define KEY6_PIN GPIO_PIN_10
#define KEY7_PIN GPIO_PIN_11
#define KEY8_PIN GPIO_PIN_12
#define KEY9_PIN GPIO_PIN_13
#define KEY10_PIN GPIO_PIN_14

uint8_t KeyId,KeyLast,KeyDelayCount,KeyPressFlag,KeyReleaseCount;

static void KeyOutPutSwitch(uint8_t KeyScanState);

void KeyInit(void)
{
    gpio_init(KEY1_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY1_PIN);
    gpio_init(KEY2_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY2_PIN);
    gpio_init(KEY3_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY3_PIN);
    gpio_init(KEY4_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY4_PIN);
    gpio_init(KEY5_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY5_PIN);
    gpio_init(KEY6_PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,KEY6_PIN);
    gpio_init(KEY7_PORT,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,KEY7_PIN);
    gpio_init(KEY8_PORT,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,KEY8_PIN);
    gpio_init(KEY9_PORT,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,KEY9_PIN);
    gpio_init(KEY10_PORT,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,KEY10_PIN);
    KeyOutPutSwitch(0);
}
 
uint8_t ReadKey(void)
{
    if(gpio_input_bit_get(KEY1_PORT,KEY1_PIN) == SET)
    {
        return 1;
    }
    if(gpio_input_bit_get(KEY2_PORT,KEY2_PIN) == SET)
    {
        return 2;
    }
    if(gpio_input_bit_get(KEY3_PORT,KEY3_PIN) == SET)
    {
        return 3;
    }
    if(gpio_input_bit_get(KEY4_PORT,KEY4_PIN) == SET)
    {
        return 4;
    }
    if(gpio_input_bit_get(KEY5_PORT,KEY5_PIN) == SET)
    {
        return 5;
    }
    if(gpio_input_bit_get(KEY6_PORT,KEY6_PIN) == SET)
    {
        return 6;
    }

    return 0;
}

static void KeyOutPutSwitch(uint8_t KeyScanState)
{
    switch (KeyScanState)
    {
    case 0:
        gpio_bit_write(KEY7_PORT,KEY7_PIN,SET);
        gpio_bit_write(KEY7_PORT,KEY8_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY9_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY10_PIN,RESET);
        break;
    case 1:

        gpio_bit_write(KEY7_PORT,KEY7_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY8_PIN,SET);
        gpio_bit_write(KEY7_PORT,KEY9_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY10_PIN,RESET);
        break;
    case 2:
        gpio_bit_write(KEY7_PORT,KEY7_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY8_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY9_PIN,SET);
        gpio_bit_write(KEY7_PORT,KEY10_PIN,RESET);
        break;
    case 3:
        gpio_bit_write(KEY7_PORT,KEY7_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY8_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY9_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY10_PIN,SET);
        break;
    case 4:
        gpio_bit_write(KEY7_PORT,KEY7_PIN,SET);
        gpio_bit_write(KEY7_PORT,KEY8_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY9_PIN,RESET);
        gpio_bit_write(KEY7_PORT,KEY10_PIN,RESET);
        break;
        
    default:
        break;
    }
}

void KeyScan(void)
{
    static uint8_t KeyScanState=0;
    uint8_t keyread=0,keyid=0;
    
    keyread = ReadKey();
    if(keyread != 0)
    {
        keyid = (KeyScanState-1) * 6 + keyread;
        KeyReleaseCount = 0;
    }
    else
    {
        if(KeyPressFlag == 1)
        {
            KeyReleaseCount++;
            if(KeyReleaseCount > 4)
            {
                KeyReleaseCount = 0;
                KeyPressFlag = 0;
                //KeyId = 0;
                KeyLast = 0;
            }
        }
    }
    if(keyid == 0)
    {
        KeyOutPutSwitch(KeyScanState);
        KeyScanState++;
        if(KeyScanState > 4)KeyScanState=1;

        
    }
    else
    {
        if(KeyLast != keyid)
        {
            KeyLast = keyid;
            KeyDelayCount = 0;
        }
        else if(keyid != 0)
        {
            KeyDelayCount++;
            if(KeyDelayCount > 20)
            {
                if(KeyPressFlag == 0)
                {
                    BeepEnable();
                    KeyPressFlag = 1;
                    KeyId = keyid;
                }
                    
                KeyDelayCount = 20;
                
                
            }
        }
    }
    
}

void KeyPro(void)
{
    switch (KeyId)
    {
    case 0:
        break;
    case 1:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001",BLACK);
        break;
    case 2:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002",BLACK);
        break;
    case 3:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"003",BLACK);
        break;
    case 4:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"004",BLACK);
        break;
    case 5:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"005",BLACK);
        break;
    case 6:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"006",BLACK);
        break;
    case 7:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"007",BLACK);
        break;
    case 8:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"008",BLACK);
        break;
    case 9:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"009",BLACK);
        break;
    case 10:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001000",BLACK);
        break;
    case 11:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001001",BLACK);
        break;
    case 12:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001002",BLACK);
        break;
    case 13:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001003",BLACK);
        break;
    case 14:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001004",BLACK);
        break;
    case 15:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001005",BLACK);
        break;
    case 16:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001006",BLACK);
        break;
    case 17:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001007",BLACK);
        break;
    case 18:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001008",BLACK);
        break;
    case 19:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"001009",BLACK);
        break;
    case 20:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002000",BLACK);
        break;
    case 21:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002001",BLACK);
        break;
    case 22:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002002",BLACK);
        break;
    case 23:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002003",BLACK);
        break;
    case 24:
        LCD_Rect_Fill(100,80,30,16,WHITE);
        LCD_ShowString(100,80,"002004",BLACK);
        break;
    
    default:
        LCD_Rect_Fill(100,80,16*3,16,WHITE);
        LCD_ShowString(100,80,"停止",BLACK);

        
        break;
    }
    KeyId = 0;
}
