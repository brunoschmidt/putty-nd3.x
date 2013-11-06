#ifndef ZMODEM_H
#define ZMODEM_H

/******************************
 *macro
 *****************************/

#define ZPAD '*' 
#define ZDLE 030
#define ZDLEE (ZDLE^0100)
#define ZBIN 'A'
#define ZHEX 'B'
#define ZBIN32 'C'

#define XON 021

// Frame types
#define ZRQINIT    0
#define ZRINIT     1
#define ZSINIT     2
#define ZACK       3
#define ZFILE      4
#define ZSKIP      5
#define ZNAK       6
#define ZABORT     7
#define ZFIN       8
#define ZRPOS      9
#define ZDATA      10
#define ZEOF       11
#define ZFERR      12
#define ZCRC       13
#define ZCHALLENGE 14
#define ZCOMPL     15
#define ZCAN       16
#define ZFREECNT   17
#define ZCOMMAND   18
#define ZSTDERR    19

/* ZDLE sequences */
#define ZCRCE 'h'	/* CRC next, frame ends, header packet follows */
#define ZCRCG 'i'	/* CRC next, frame continues nonstop */
#define ZCRCQ 'j'	/* CRC next, frame continues, ZACK expected */
#define ZCRCW 'k'	/* CRC next, ZACK expected, end of frame */
#define ZRUB0 'l'	/* Translate to rubout 0177 */
#define ZRUB1 'm'	/* Translate to rubout 0377 */

#define ZF0	3
#define ZF1	2
#define ZF2	1
#define ZF3	0
#define ZP0	0
#define ZP1	1
#define ZP2	2
#define ZP3	3

#define CANFDX	0x01
#define CANOVIO	0x02
#define CANBRK	0x04
#define CANCRY	0x08
#define CANLZW	0x10
#define CANFC32	0x20
#define ESCCTL  0x40
#define ESC8    0x80


/******************************
 *enum
 *****************************/
typedef enum{
    STATE_IDLE = 0,
    STATE_CHK_ENC,
    STATE_PARSE_HEX,
    STATE_PARSE_BIN,
    STATE_PARSE_BIN32,
    STATE_PARSE_LINESEEDXON,
    
    STATE_PARSE_FILE_NAME,
    STATE_PARSE_FILE_SIZE,
    STATE_PARSE_FILE_MTIME,
    STATE_PARSE_FILE_MODE,
    STATE_PARSE_FILE_NFILELEFT,
    STATE_PARSE_FILE_TOTALSIZELEFT,
    
    STATE_ZRQINIT,

    STATE_EXIT,
    STATE_DUMP
} ZmodemState;

typedef enum{
    ZR_ERROR  = -1,
    ZR_DONE   = 0,
    ZR_PARTLY = 1
} ZmodemResult;

/******************************
 *struct
 *****************************/

#pragma   pack(1)


struct enc_header_tag{
    char      hex_pre[4];
};
typedef struct enc_header_tag enc_header_t;

struct hex_str_tag{
    char hex[2];
};
typedef struct hex_str_tag hex_str_t;    
struct hex_tag{
    hex_str_t type;
    hex_str_t flag[4];
    hex_str_t crc[2];         
};
typedef struct hex_tag hex_t;

struct frame_tag{
    unsigned char type;
    unsigned char flag[4];
    unsigned short crc;
};
typedef struct frame_tag frame_t;

struct frame32_tag{
    unsigned char type;
    unsigned char flag[4];
	unsigned long crc;
};
typedef struct frame32_tag frame32_t;

struct lineseed_tag{
    char lineseed[2];         
};
typedef struct lineseed_tag lineseed_t;
struct lineseedxon_tag{
    char lineseed[2]; 
    char xon;
};
typedef struct lineseedxon_tag lineseedxon_t;

#pragma   pack()



#endif /* ZMODEM_H */

