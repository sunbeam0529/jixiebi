

#include "gd32f10x.h"
#include "systick.h"
#include "stdint.h"
#include "gd32f107c_eval.h"
#include "gd32f107c_lcd_eval.h"
#include "picture.h"
#include "pic.h"
#include "BEEP.H"
#include "lcd_driver.h"
#include "key.h"
#include "logic.h"

volatile uint32_t sysfreq;
uint32_t TimeBaseCounter;
uint8_t TimeBase_2ms,TimeBase_5ms,TimeBase_10ms,TimeBase_20ms,TimeBase_50ms,TimeBase_100ms,TimeBase_1000ms;

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
    rcu_periph_clock_enable(RCU_TIMER2);
    sysfreq = rcu_clock_freq_get(CK_SYS);
}

void TimeBaseInit(void)
{
    /* ----------------------------------------------------------------------------
    TIMER1 Configuration: 
    TIMER1CLK = SystemCoreClock/5400 = 20KHz.
    TIMER1 configuration is timing mode, and the timing is 1ms(20000/20 = 1ms).
    ---------------------------------------------------------------------------- */
    timer_parameter_struct timer_initpara;

    timer_deinit(TIMER2);
    /* initialize TIMER init parameter struct */
    timer_struct_para_init(&timer_initpara);
    /* TIMER1 configuration */
    timer_initpara.prescaler         = 5399;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 20;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(TIMER2, &timer_initpara);

    timer_interrupt_enable(TIMER2, TIMER_INT_UP);
    nvic_irq_enable(TIMER2_IRQn, 1, 1);
    timer_enable(TIMER2);
    TimeBaseCounter = 0;
}



void TimeBaseInterruptHandler(void)
{
    TimeBaseCounter++;
    if(TimeBaseCounter % 2 == 0)
    {
        TimeBase_2ms = 1;
    }
    if(TimeBaseCounter % 5 == 0)
    {
        TimeBase_5ms = 1;
    }
    if(TimeBaseCounter % 10 == 0)
    {
        TimeBase_10ms = 1;
    }
    if(TimeBaseCounter % 20 == 0)
    {
        TimeBase_20ms = 1;
    }
    if(TimeBaseCounter % 50 == 0)
    {
        TimeBase_50ms = 1;
    }
    if(TimeBaseCounter % 100 == 0)
    {
        TimeBase_100ms = 1;
    }
    if(TimeBaseCounter % 1000 == 0)
    {
        TimeBase_1000ms = 1;
    }

    if(TimeBaseCounter > 999999)
    {
        TimeBaseCounter = 0;
    }

}

int main()
{
    
    //rcu_system_clock_source_config();
    SystemClockInit();
    systick_config(sysfreq/3);
    BeepInit();
    KeyInit();
    gpio_init(GPIOB,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,GPIO_PIN_0);
    //gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,GPIO_PIN_0);
    
    //delay_1ms(1000);
    LCD_Init();
    delay_1ms(100);
    //LCD_Rect_Fill(200,200,20,20,BLUE);
    LCD_Rect_Fill(0, 0, 480, 272, WHITE);
    //LCD_Picture_Draw(0,0,269,269,gImage_pic);
    LCD_DrawMainMenu();
    TimeBaseInit();
    
    LCD_ShowICON(21,9,0);
    while(1)
    {
        if(TimeBase_2ms == 1)
        {
            TimeBase_2ms = 0;
            KeyScan();
            //KeyPro();
        }
        if(TimeBase_5ms == 1)
        {
            TimeBase_5ms = 0;
            MainStateCtrl();
        }
    }
    //gd_eval_led_toggle(1);
    
    return 0;
}