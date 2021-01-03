#ifndef __KEY_H__
#define __KEY_H__

#include "gd32f10x.h"

#define KEY_STOP        1
#define KEY_INPUT       2
#define KEY_DOWN        3
#define KEY_UP          4
#define KEY_MONIT       5   
#define KEY_INFO        6
#define KEY_START       7
#define KEY_DEL         8
#define KEY_FBJK        9
#define KEY_SPTD        10
#define KEY_ZBJK        11
#define KEY_TIME        12
#define KEY_AUTO        13
#define KEY_DBSB        14
#define KEY_FBJT        15
#define KEY_ZKXF        16
#define KEY_ZBJT        17
#define KEY_PROG        18
#define KEY_MANU        19
#define KEY_TBCR        20
#define KEY_FBSX        21
#define KEY_XRXC        22
#define KEY_ZBSX        23
#define KEY_FUNC        24

#define KEY_0     14
#define KEY_1     23
#define KEY_2     17
#define KEY_3     11
#define KEY_4     22
#define KEY_5     16
#define KEY_6     10
#define KEY_7     21
#define KEY_8     15
#define KEY_9     9


extern uint8_t KeyId;

void KeyInit(void);
void KeyScan(void);
void KeyPro(void);

#endif
