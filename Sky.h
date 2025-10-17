//
// Created by JAD on 17/10/2025.
//
#include "Mobile.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef JUNIA_ISEN3_TOPGUN__SKY_H_
#define JUNIA_ISEN3_TOPGUN__SKY_H_
#define EMPTY_SKY_TILE '.'
typedef struct {
  int height;
  int width;
} Sky;

Sky* createSky(int height, int width);

void destroySky(Sky* sky);

void displaySky(Sky* sky);

int getSkyHeight(Sky* sky);

int getSkyWidth(Sky* sky);

void putMobileOnSky(Sky* sky, Mobile* mobile);

#endif //JUNIA_ISEN3_TOPGUN__SKY_H_
