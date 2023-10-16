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

#endif