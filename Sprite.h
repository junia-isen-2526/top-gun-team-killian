//
// Created by JAD on 17/10/2025.
//

#include <stdlib.h>
#include <stdio.h>
#ifndef JUNIA_ISEN3_TOPGUN__SPRITE_H_
#define JUNIA_ISEN3_TOPGUN__SPRITE_H_
#define SPRITE_SIZE 5
typedef struct {
  char symbols[SPRITE_SIZE][SPRITE_SIZE];
} Sprite;

Sprite* createSprite(char symbols[SPRITE_SIZE][SPRITE_SIZE]);

void destroySprite(Sprite* sprite);

#endif //JUNIA_ISEN3_TOPGUN__SPRITE_H_
