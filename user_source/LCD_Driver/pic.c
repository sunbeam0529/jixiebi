#include "pic.h"

// 28 * 28 icon
const unsigned char ICON_Arr[ICON_NUM][1568] = 
{
{ /* 0X00,0X10,0X1C,0X00,0X1C,0X00,0X01,0X1B, */
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X7D,0XEF,
0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,
0X9E,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0X9E,0XF7,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,
0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XDC,0XD6,0X02,0X61,0XE0,0X68,0X7E,0XEF,0X7D,0XEF,
0X7D,0XEF,0X9E,0XF7,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X5D,0XF7,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,
0XB8,0XAD,0X9B,0XCE,0XD7,0XC5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XDE,0XFF,0X61,0X91,0X03,0XA2,0XE8,0XAA,
0XBD,0XFF,0X7E,0XF7,0X7D,0XF7,0XFF,0XFF,0XC0,0X70,0X21,0X81,0XD1,0XCC,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X1C,0XFF,
0X00,0X89,0X20,0X99,0X60,0XA1,0XA0,0XA9,0XC0,0XB1,0X20,0XBA,0XA3,0XC2,0X45,0XCB,
0XE6,0XC2,0X62,0X91,0X13,0XCD,0X9D,0XF7,0X7D,0XEF,0X9E,0XF7,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X5C,0XFF,0X00,0X89,0X40,0X99,0X60,0XA1,0XA0,0XA9,0XE0,0XB1,
0X00,0XBA,0X40,0XC2,0X60,0XCA,0XA0,0XD2,0XC0,0XD2,0XC0,0XDA,0X22,0XDB,0X65,0XEB,
0X63,0X99,0XBE,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X9E,0XF7,0X9E,0XF7,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X5D,0XFF,0X01,0X99,0X20,0X99,
0X60,0XA1,0XA0,0XA9,0XE0,0XB1,0X20,0XC2,0X60,0XCA,0XA0,0XD2,0XE0,0XDA,0X00,0XDB,
0X20,0XDB,0X40,0XE3,0X40,0XE3,0XE1,0XB9,0X87,0XAA,0X41,0X88,0X9E,0XF7,0X9E,0XF7,
0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X9E,0XF7,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X1B,0XFF,0X00,0X91,0X20,0X91,0X40,0X99,0XA0,0XA9,0XE0,0XB1,0X20,0XC2,0X80,0XCA,
0XC0,0XD2,0X00,0XDB,0X40,0XE3,0X80,0XEB,0X80,0XEB,0X80,0XEB,0XE2,0XD2,0X8F,0XC5,
0X6E,0XC5,0XA6,0XAA,0X21,0X88,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0X9D,0XFF,0X00,0X89,0X20,0X91,0X60,0XA1,0X80,0XA1,
0XC0,0XB1,0X20,0XC2,0X60,0XCA,0XC0,0XD2,0X20,0XE3,0X80,0XEB,0XA0,0XEB,0XE0,0XEB,
0X00,0XF4,0XE4,0XEB,0XF1,0XCD,0XF5,0XF6,0XB3,0XE6,0XB0,0XCD,0XA7,0XBA,0X61,0X80,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X1B,0XFF,0XE0,0X88,
0X00,0X91,0X40,0X99,0X60,0XA1,0XA0,0XA9,0X00,0XBA,0X60,0XCA,0XA0,0XD2,0X20,0XE3,
0X80,0XEB,0XC0,0XEB,0X20,0XF4,0X40,0XFC,0XA3,0XFC,0X12,0XCE,0X16,0XF7,0X36,0XF7,
0XF5,0XF6,0X73,0XE6,0X32,0XD6,0XE7,0XBA,0X81,0X78,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X9D,0XFF,0XE0,0X88,0X00,0X91,0X40,0X99,0X60,0XA1,0XA0,0XA9,0XE0,0XB1,
0X40,0XC2,0X80,0XD2,0XE0,0XDA,0X60,0XE3,0XC0,0XF3,0X40,0XF4,0X80,0XF4,0X64,0XFD,
0X53,0XCE,0X36,0XFF,0X14,0XCE,0XFB,0XD6,0XBF,0XF7,0XD2,0XCD,0X74,0XE6,0X74,0XDE,
0XE8,0XC2,0XC2,0X80,0XFF,0XFF,0XFF,0XFF,0XFA,0XF6,0XC0,0X90,0X00,0X91,0X20,0X99,
0X40,0XA1,0X80,0XA9,0XC0,0XB1,0X00,0XBA,0X60,0XCA,0XC0,0XD2,0X40,0XE3,0XA0,0XEB,
0X00,0XF4,0X80,0XFC,0X82,0XFD,0XD2,0XCD,0X16,0XF7,0X58,0XFF,0X7B,0XB6,0X3A,0XB6,
0XBC,0XC6,0XD3,0XCD,0XB5,0XE6,0XF6,0XEE,0X95,0XE6,0X89,0XD3,0XC6,0X91,0X7D,0XEF,
0X5D,0XF7,0X7D,0XF7,0X83,0X89,0X81,0XA9,0X60,0XA1,0XA0,0XA9,0XC0,0XB1,0X20,0XC2,
0X60,0XCA,0XE0,0XDA,0X60,0XE3,0XE0,0XEB,0X40,0XFC,0X43,0XFD,0X96,0XE6,0XF7,0XEE,
0XF7,0XEE,0X59,0XFF,0XFA,0X9D,0XB9,0X95,0X5B,0XAE,0XD3,0XCD,0X17,0XF7,0XD6,0XEE,
0X38,0XF7,0X96,0XE6,0XC9,0XDB,0X54,0XDD,0XFF,0XFF,0XFF,0XFF,0X14,0XD6,0XD2,0XCD,
0X90,0XCD,0X22,0X89,0X20,0XC2,0X40,0XC2,0XA0,0XD2,0X00,0XDB,0X80,0XEB,0XE0,0XEB,
0XE1,0XFC,0XB6,0XE6,0X59,0XFF,0X59,0XFF,0XD7,0XEE,0X58,0XFF,0X16,0XBE,0XD4,0XC5,
0X35,0XD6,0X38,0XF7,0X59,0XFF,0XD7,0XEE,0X17,0XF7,0X58,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X96,0XDE,0X54,0XDE,0X33,0XD6,0XD1,0XCD,0X90,0XCD,0X4F,0XC5,
0XE0,0X80,0X80,0XE3,0X80,0XF3,0X60,0XF4,0X4F,0XC5,0X58,0XF7,0X79,0XFF,0X59,0XFF,
0XF7,0XEE,0XD7,0XEE,0X58,0XF7,0X58,0XF7,0X58,0XF7,0X38,0XF7,0X38,0XF7,0X18,0XF7,
0XD6,0XEE,0X38,0XF7,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XB7,0XE6,0XD7,0XEE,
0XB6,0XE6,0X34,0XD6,0X54,0XD6,0X12,0XD6,0XD1,0XCD,0X8F,0XC5,0X0E,0XC5,0XEC,0XC4,
0XD1,0XCD,0X59,0XF7,0X59,0XF7,0X59,0XF7,0X18,0XF7,0XD7,0XEE,0X17,0XF7,0X38,0XF7,
0X38,0XF7,0X38,0XF7,0X38,0XF7,0X18,0XF7,0XB6,0XE6,0XD7,0XEE,0X7D,0XEF,0X7D,0XEF,
0X7D,0XEF,0X7D,0XEF,0XD7,0XE6,0X18,0XEF,0XF7,0XEE,0XB6,0XE6,0XB6,0XE6,0X54,0XD6,
0X54,0XDE,0X12,0XD6,0X90,0XC5,0X6F,0XC5,0XD1,0XCD,0X38,0XF7,0X38,0XF7,0X38,0XF7,
0X38,0XF7,0X95,0XE6,0X03,0X82,0X22,0X8A,0X41,0X8A,0XE2,0X81,0X0F,0XBD,0X17,0XF7,
0XD6,0XEE,0X95,0XE6,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XD7,0XEE,0X38,0XF7,
0X38,0XF7,0XBF,0XF7,0XBD,0XF7,0X75,0XDE,0X97,0XE6,0X74,0XDE,0X13,0XD6,0XD1,0XD5,
0X12,0XD6,0X38,0XF7,0X18,0XF7,0X38,0XF7,0X17,0XF7,0X82,0XB3,0X22,0X9B,0X46,0X9B,
0X2C,0XB4,0X61,0X61,0X30,0XBD,0XD7,0XEE,0XD6,0XEE,0X75,0XDE,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X18,0XEF,0X58,0XF7,0X18,0XF7,0X5E,0XDF,0X3D,0XDF,0X9B,0XC6,
0XFD,0XD6,0X55,0XD6,0X75,0XDE,0X34,0XDE,0XF3,0XD5,0X17,0XF7,0XF7,0XEE,0XF7,0XF6,
0XF7,0XEE,0X62,0XAB,0X28,0XBC,0XA7,0XAB,0X47,0X9B,0X41,0X61,0X50,0XC5,0XB6,0XEE,
0XB6,0XEE,0X95,0XE6,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0X39,0XF7,0X59,0XFF,
0XF8,0XEE,0X1D,0XCF,0X5A,0XB6,0X3A,0XAE,0X9B,0XBE,0X7B,0XBE,0XD6,0XE6,0X96,0XE6,
0XF3,0XCD,0XD6,0XEE,0XD6,0XEE,0XD6,0XEE,0XD6,0XEE,0X03,0XA3,0XC7,0XAB,0X46,0XA3,
0XC5,0X92,0X40,0X61,0X91,0XC5,0X95,0XE6,0X95,0XE6,0X95,0XE6,0X7D,0XEF,0X7E,0XEF,
0X7D,0XEF,0X7D,0XEF,0X39,0XF7,0X5A,0XFF,0XD8,0XEE,0X9C,0XAE,0X5B,0XA6,0X98,0X8D,
0XD9,0X95,0X37,0X85,0XF7,0XEE,0XB6,0XE6,0XF3,0XD5,0X75,0XE6,0XD6,0XEE,0XB6,0XEE,
0XB5,0XEE,0X82,0X92,0X66,0XA3,0XC5,0X92,0X65,0X8A,0X41,0X61,0XB2,0XCD,0X74,0XE6,
0X74,0XE6,0X74,0XE6,0X7D,0XEF,0X7E,0XEF,0X9E,0XF7,0X9E,0XF7,0X3A,0XF7,0X5A,0XF7,
0XF9,0XEE,0X7B,0XFF,0XF4,0XC5,0XF9,0XA5,0X3B,0XA6,0X1A,0X9E,0XF8,0XEE,0XD6,0XEE,
0X13,0XDE,0X54,0XDE,0X95,0XE6,0X95,0XE6,0X75,0XE6,0XC2,0X79,0XC6,0X92,0X24,0X8A,
0X04,0X82,0X20,0X61,0XF2,0XD5,0X54,0XDE,0X53,0XDE,0X33,0XDE,0X9D,0XEF,0X9E,0XF7,
0XFF,0XFF,0XFF,0XFF,0XD2,0X9C,0X7B,0XF7,0X5B,0XF7,0X9D,0XF7,0X3B,0XEF,0X9C,0XFF,
0XF4,0XC5,0X37,0XBE,0XF8,0XEE,0X96,0XE6,0X13,0XD6,0X54,0XDE,0X34,0XDE,0X74,0XE6,
0X74,0XE6,0XA1,0X79,0X45,0X8A,0XC3,0X81,0XA3,0X79,0X00,0X61,0X13,0XDE,0X33,0XDE,
0X33,0XDE,0X33,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X3C,0XE7,
0X96,0XB5,0X9D,0XF7,0X5C,0XEF,0XBD,0XFF,0X7C,0XF7,0X3A,0XF7,0XF8,0XEE,0X55,0XDE,
0XF2,0XD5,0X33,0XDE,0X12,0XD6,0X33,0XDE,0X33,0XDE,0X61,0X71,0XE4,0X81,0X62,0X79,
0X62,0X71,0XE0,0X60,0X33,0XDE,0X12,0XDE,0X12,0XD6,0XF2,0XD5,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XBA,0XD6,0X30,0X84,
0X7C,0XF7,0X3A,0XF7,0XD8,0XEE,0X34,0XD6,0XD2,0XCD,0X33,0XDE,0XF2,0XD5,0XF2,0XD5,
0X13,0XDE,0X41,0X71,0X61,0X71,0XE1,0X81,0X60,0X92,0XC0,0X9A,0X00,0XA3,0XD1,0XD5,
0XD1,0XCD,0XD2,0XC5,0X3C,0XE7,0X7D,0XEF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0XB2,0X9C,0XD8,0XE6,0X34,0XDE,
0XB1,0XCD,0X12,0XDE,0XF2,0XD5,0XB1,0XCD,0XF2,0XD5,0X41,0X69,0X80,0X79,0XE0,0X81,
0XC1,0X81,0X80,0X58,0XE0,0X68,0XE0,0X60,0XBE,0XF7,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X7D,0XEF,
0X7D,0XEF,0XFF,0XFF,0XDE,0XFF,0XD7,0XB5,0X70,0X94,0X71,0X94,0XB6,0XB5,0X59,0XC6,
0XFB,0XDE,0X5D,0XEF,0X84,0X51,0X8D,0X83,0X75,0XAD,0X79,0XCE,0X7D,0XF7,0XFF,0XFF,
0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,
0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X9D,0XEF,
0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7E,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,
0X9D,0XEF,0X7E,0XF7,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,
}

};
