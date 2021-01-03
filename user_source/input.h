#ifndef __INPUT_H__
#define __INPUT_H__

#include "gd32f10x.h"


void Input_Init(void);
void Input_Detect(void);
uint8_t Input_GetState(uint8_t input_id);

#endif
