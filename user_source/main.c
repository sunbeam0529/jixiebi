

#include "gd32f10x.h"
#include "systick.h"
#include "stdint.h"
#include "gd32f107c_eval.h"
#include "gd32f107c_lcd_eval.h"
#include "picture.h"
#include "pic.h"
#include "BEEP.H"
#include "lcd_driver.h"

volatile uint32_t sysfreq;

void SystemClockInit(void);

void SystemClockInit(void)
{
    rcu_predv0_config(RCU_PREDV0SRC_HXTAL,RCU_PREDV0_DIV2);//4M 
    rcu_pll_config(RCU_PLLSRC_HXTAL,RCU_PLL_MUL27);//108M -> CK_SYS
    rcu_system_clock_source_config(RCU_CKSYSSRC_PLL);//

    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);
    rcu_periph_clock_enable(RCU_TIMER1);
    sysfreq = rcu_clock_freq_get(CK_SYS);
}

int main()
{
    
    //rcu_system_clock_source_config();
    SystemClockInit();
    systick_config(sysfreq/3);
    BeepInit();
    gpio_init(GPIOB,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,GPIO_PIN_0);
    //gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,GPIO_PIN_0);
    //nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    //nvic_irq_enable(TIMER1_IRQn, 1, 1);
    //delay_1ms(1000);
    LCD_Init();
    delay_1ms(100);
    //LCD_Rect_Fill(200,200,20,20,BLUE);
    LCD_Rect_Fill(0, 0, 480, 272, WHITE);
    //LCD_Picture_Draw(0,0,269,269,gImage_pic);
    LCD_DrawMainMenu();
    LCD_Line(3,38,130,134,1,SILVER);
    LCD_Line(3,229,130,134,1,SILVER);
    LCD_Line(130,134,349,134,1,SILVER);
    LCD_Line(349,134,478,38,1,SILVER);
    LCD_Line(349,134,478,229,1,SILVER);
    LCD_Circle(180,14,5,1,1,GREEN);
    LCD_Circle(253,14,5,1,1,GREEN);
    LCD_Circle(327,14,5,1,1,RED);
    LCD_Circle(400,14,5,1,1,RED);
    LCD_ShowString(230,110,"智能斜臂系统",BLACK);
    LCD_ShowString(70,10,"主页面",BLACK);
    LCD_ShowString(193,5,"开模完",BLACK);
    LCD_ShowString(266,5,"安全门",BLACK);
    LCD_ShowString(340,5,"可锁模",BLACK);
    LCD_ShowString(413,5,"可顶针",BLACK);

    while(1)
    {
        //BeepEnable();
        gpio_bit_write(GPIOB,GPIO_PIN_0,0);
        delay_1ms(200);
        gpio_bit_write(GPIOB,GPIO_PIN_0,1);
        //BeepDisable();
        delay_1ms(800);
    }
    //gd_eval_led_toggle(1);
    
    return 0;
}