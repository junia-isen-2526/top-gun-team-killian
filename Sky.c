//
// Created by JAD on 17/10/2025.
//

#include "Sky.h"


Sky *createSky(int height, int width) {
    Sky *newSky = malloc(sizeof(Sky));
    newSky->height = height;
    newSky->width = width;
    return newSky;
}


void destroySky(Sky *sky) {
    free(sky);
}


void displaySky(Sky *sky) {
    for (int i=0; i < sky->height; i++) {
        for (int l=0; l < sky->width; l++) {
            printf("%c",EMPTY_SKY_TILE);
        }
        printf("\n");
    }
}
