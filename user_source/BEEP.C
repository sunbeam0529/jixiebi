
#include "BEEP.H"

static void timer_config(void);

static bool blBeepState;
uint16_t BeepTime;

static void timer_config(void)
{
    /* ----------------------------------------------------------------------------
    TIMER1 Configuration: 
    TIMER1CLK = SystemCoreClock/5400 = 20KHz.
    TIMER1 configuration is timing mode, and the timing is 0.2s(4000/20000 = 0.2s).
    ---------------------------------------------------------------------------- */
    timer_parameter_struct timer_initpara;

    timer_deinit(TIMER1);
    /* initialize TIMER init parameter struct */
    timer_struct_para_init(&timer_initpara);
    /* TIMER1 configuration */
    timer_initpara.prescaler         = 5399;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 20;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(TIMER1, &timer_initpara);

    timer_interrupt_enable(TIMER1, TIMER_INT_UP);
    //timer_enable(TIMER1);
}


void BeepInit(void)
{
    gpio_init(GPIOE,GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,GPIO_PIN_5);

    gpio_bit_write(GPIOE,GPIO_PIN_5,RESET);

    timer_config();

    nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    nvic_irq_enable(TIMER1_IRQn, 1, 1);
}

void BeepEnable(void)
{
    gpio_bit_write(GPIOE,GPIO_PIN_5,SET);
    blBeepState = TRUE;
    timer_enable(TIMER1);
    BeepTime = 0;
}

void BeepDisable(void)
{
    gpio_bit_write(GPIOE,GPIO_PIN_5,RESET);
    blBeepState = FALSE;
    gpio_bit_write(GPIOE,GPIO_PIN_5,RESET);
    timer_disable(TIMER1);
}

void BeepTimerHandler(void)
{
    FlagStatus bb;
    BeepTime++;
    if(BeepTime > 20)
    {
        BeepDisable();
    }
    //bb = gpio_output_bit_get(GPIOE,GPIO_PIN_5);
    //bb = bb?RESET:SET;
    //gpio_bit_write(GPIOE,GPIO_PIN_5,bb);
}