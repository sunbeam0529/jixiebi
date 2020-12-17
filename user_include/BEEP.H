
#ifndef __BEEP_H__
#define __BEEP_H__

#include "gd32f10x.h"

void BeepInit(void);

void BeepEnable(void);

void BeepDisable(void);

void BeepTimerHandler(void);



#endif
