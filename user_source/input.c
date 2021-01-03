
#include "input.h"
#include "logic.h"
static uint8_t input_state[16];

typedef struct 
{
    uint32_t PORT;
    uint32_t PIN;
}IO_TYPE;

const IO_TYPE Input_arr[]={
    {GPIOB,GPIO_PIN_7},//X1
    {GPIOE,GPIO_PIN_15},//X2
    {GPIOA,GPIO_PIN_2},//X3
    {GPIOA,GPIO_PIN_1},//X4
    {GPIOB,GPIO_PIN_5},//X5
    {GPIOB,GPIO_PIN_8},//X6
    {GPIOD,GPIO_PIN_2},//X7
    {GPIOB,GPIO_PIN_9},//X8
    {GPIOD,GPIO_PIN_0},//X9
    {GPIOE,GPIO_PIN_0},//X10
    {GPIOA,GPIO_PIN_3},//X11
    {GPIOD,GPIO_PIN_1},//X12
    {GPIOD,GPIO_PIN_3},//X13
    {GPIOD,GPIO_PIN_4}//X14
};

void Input_Init(void)
{
    uint8_t i;
    for(i=0;i<14;i++)
    {
        gpio_init(Input_arr[i].PORT,GPIO_MODE_IN_FLOATING,GPIO_OSPEED_2MHZ,Input_arr[i].PIN);
    }
}

void Input_Detect(void)
{
    uint8_t i;
    FlagStatus val;
    static uint8_t input_filter_counter[16];

    for(i=0;i<14;i++)
    {
        val = gpio_input_bit_get(Input_arr[i].PORT,Input_arr[i].PIN);
        if(val == RESET)
        {
            input_filter_counter[i] ++;
            if(input_filter_counter > 10)
            {
                input_state[i] = 1;
            }
        }
        else
        {
            input_filter_counter[i] = 0;
            input_state[i] = 0;
        }
        
    }
    
}

uint8_t Input_GetState(uint8_t input_id)
{
    return input_state[input_id];
}




