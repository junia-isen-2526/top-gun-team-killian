//
// Created by JAD on 17/10/2025.
//
#include "Direction.h"
#include "Sprite.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef JUNIA_ISEN3_TOPGUN__MOBILE_H_
#define JUNIA_ISEN3_TOPGUN__MOBILE_H_

typedef struct {
  int x;
  int y;
  Direction direction;
  Sprite *sprite;
  int maxHeight;
  int maxWidth;
} Mobile;

Mobile *createMobile(int x, int y, Direction direction, Sprite *sprite, int maxHeight, int maxWidth);

void destroyMobile(Mobile* mobile);

int getMobileX(Mobile* mobile);

int getMobileY(Mobile* mobile);

Direction getDirection(Mobile* mobile);

void turnMobileLeft(Mobile* mobile);

void turnMobileRight(Mobile* mobile);

Sprite *getMobileSprite(Mobile* mobile);

void moveMobileForward(Mobile* mobile);

Mobile *createPlane(int x, int y, Direction direction, int maxHeight, int maxWidth);

#endif //JUNIA_ISEN3_TOPGUN__MOBILE_H_
