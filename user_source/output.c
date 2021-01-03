#include "output.h"


#define O1_PORT         GPIOD
#define O2_PORT         GPIOD
#define O3_PORT         GPIOA
#define O4_PORT         GPIOB
#define O5_PORT         GPIOB
#define O6_PORT         GPIOD
#define O7_PORT         GPIOD
#define O8_PORT         GPIOD
#define O9_PORT         GPIOB
#define O10_PORT        GPIOB
#define O11_PORT        GPIOD
#define O12_PORT        GPIOD
#define O13_PORT        GPIOD
#define O14_PORT        GPIOD
#define O15_PORT        GPIOB
#define O16_PORT        GPIOB




#define O1_PIN      GPIO_PIN_11
#define O2_PIN      GPIO_PIN_8
#define O3_PIN      GPIO_PIN_8
#define O4_PIN      GPIO_PIN_12
#define O5_PIN      GPIO_PIN_15
#define O6_PIN      GPIO_PIN_14
#define O7_PIN      GPIO_PIN_14
#define O8_PIN      GPIO_PIN_9
#define O9_PIN      GPIO_PIN_13
#define O10_PIN     GPIO_PIN_15
#define O11_PIN     GPIO_PIN_5
#define O12_PIN     GPIO_PIN_13
#define O13_PIN     GPIO_PIN_12
#define O14_PIN     GPIO_PIN_10
#define O15_PIN     GPIO_PIN_11
#define O16_PIN     GPIO_PIN_10

const uint32_t output_port_arr[]={O1_PORT , O2_PORT , O3_PORT , O4_PORT , O5_PORT , O6_PORT , O7_PORT , O8_PORT , O9_PORT , O10_PORT, O11_PORT, O12_PORT, O13_PORT, O14_PORT, O15_PORT, O16_PORT};
const uint32_t output_pin_arr[]={O1_PIN , O2_PIN , O3_PIN , O4_PIN , O5_PIN , O6_PIN , O7_PIN , O8_PIN , O9_PIN , O10_PIN, O11_PIN, O12_PIN, O13_PIN, O14_PIN, O15_PIN, O16_PIN};

void Output_Init(void)
{
    uint8_t i;
    for(i=0;i<16;i++)
    {
        gpio_init(output_port_arr[i],GPIO_MODE_OUT_PP,GPIO_OSPEED_2MHZ,output_pin_arr[i]);
        gpio_bit_write(output_port_arr[i],output_pin_arr[i],SET);
    }
    
}

void Output_test_1way(uint8_t id)
{
    
}

void light_test(void)
{
    static uint8_t counter,light_id;
    counter++;
    if(counter > 10)
    {
        counter = 0;
        gpio_bit_write(output_port_arr[light_id],output_pin_arr[light_id],SET);
        light_id++;
        if(light_id >= 16)
            light_id = 0;

        gpio_bit_write(output_port_arr[light_id],output_pin_arr[light_id],RESET);
    }
}
