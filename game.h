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
#define NUM_CLASSES 6

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

typedef union{
    uint8_t stat[16];
    struct{
        uint8_t speed : 4;
        uint8_t view : 4;
        uint8_t health;
        uint16_t gold;
        uint8_t armor;
        uint8_t attack;
        uint8_t special;
        uint8_t reserved[9];
    };
}stat_block;

typedef struct{
    uint8_t uid[7];
    message_pramble preamble;
    uint8_t text_line[8][14];
    stat_block stats;
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

typedef struct{
    uint8_t *title;
    uint8_t *body;
    stat_block stats;
    uint8_t portrait;
} class_entry;

extern class_entry classes[NUM_CLASSES];

#endif