#ifndef __GAME_H__
#define __GAME_H__

#include "pico/stdlib.h"

#define PLAYER  0
#define EQUIP   1

#define MUTANT  0
#define ROBOT   1

#define ARMOR 0

typedef struct{
    uint8_t type : 1;
    uint8_t class : 3;
    uint8_t na : 4;
    uint8_t reserved;
    uint8_t unknown;
    uint8_t last;
} message_pramble;

typedef struct{
    uint8_t uid[7];
    message_pramble preamble;
    uint8_t text_line[8][14];
    uint8_t reserved[44];
    union{
        struct{
            uint8_t figurine_spacer[104];
            uint8_t portrait[240];
        };
        struct{
            uint8_t full_image[320];
            uint8_t equipment_image[24];
        };
    };
} NTAG215;


#endif