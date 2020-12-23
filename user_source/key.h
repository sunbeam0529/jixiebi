#ifndef __KEY_H__
#define __KEY_H__

#include "gd32f10x.h"

extern uint8_t KeyId;

void KeyInit(void);
void KeyScan(void);
void KeyPro(void);

#endif
