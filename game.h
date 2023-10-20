#ifndef __GAME_H__
#define __GAME_H__

#include "pico/stdlib.h"

// Token Types
#define PLAYER  0
#define EQUIP   1

// Player Classes
#define MUTANT  4
#define ROBOT   3
#define DOG   0
#define STRAW   5
#define GOBLIN   2
#define SCIENTIST   1

// Equipment Classes
#define SPECIAL 0
#define HELMET 1
#define FIREARM 2
#define WEAPON 3
#define ARMOR 4

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
    union{
        uint8_t stats[16];
        struct{
            uint8_t speed;
            uint8_t health;
            uint16_t gold;
            uint8_t armor;
            uint8_t attack;
            uint8_t view;
            uint8_t special;
            uint8_t reserved[8];
        };
    };
    uint8_t reserved[28];
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