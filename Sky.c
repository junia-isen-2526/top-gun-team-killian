//
// Created by JAD on 17/10/2025.
//

#include "Sky.h"

void putMobileOnScreen(Mobile *mobile, char **screen, int height, int width);

char **createEmptyScreen(const Sky *sky);

void destroyScreen(const Sky *sky, char **screen);

Sky *createSky(int height, int width) {
    Sky *newSky = malloc(sizeof(Sky));
    newSky->height = height;
    newSky->width = width;
    for (int i = 0; i < MAX_MOBILE_ON_SKY; i++) {
        newSky->mobileOnSky[i] = NULL;
    }
    return newSky;
}


void destroySky(Sky *sky) {
    if (sky == NULL) return;
    for (int i = 0; i < MAX_MOBILE_ON_SKY; i++) {
        if (sky->mobileOnSky[i] != NULL) {
            destroyMobile(sky->mobileOnSky[i]);
        }
    }
    free(sky);
}


void displaySky(Sky *sky) {
    char **screen = createEmptyScreen(sky);
    for (int i = 0; i < MAX_MOBILE_ON_SKY && sky->mobileOnSky[i] != NULL; i++) {
        putMobileOnScreen(sky->mobileOnSky[i], screen, sky->height, sky->width);
    }
    for (int row = 0; row < sky->height; row++) {
        for (int column = 0; column < sky->width; column++) {
            printf("%c", screen[row][column]);
        }
        printf("\n");
    }
    destroyScreen(sky, screen);
}


void destroyScreen(const Sky *sky, char **screen) {
    for (int row = 0; row < sky->height; row++) {
        free(screen[row]);
    }
    free(screen);
}

char **createEmptyScreen(const Sky *sky) {
    char **screen = malloc(sky->height * sizeof(char *));
    for (int row = 0; row < sky->height; row++) {
        screen[row] = malloc(sky->width * sizeof(char));
    }
    for (int row = 0; row < sky->height; row++) {
        for (int column = 0; column < sky->width; column++) {
            screen[row][column] = EMPTY_SKY_TILE;
        }
    }
    return screen;
}

void putMobileOnScreen(Mobile *mobile, char **screen, int height, int width) {
    for (int row = -SPRITE_SIZE / 2; row <= SPRITE_SIZE / 2; row++) {
        for (int column = -SPRITE_SIZE / 2; column <= SPRITE_SIZE / 2; column++) {
            int screenRow = (getMobileY(mobile) + row + height) % height;
            int screenColumn = (getMobileX(mobile) + column + width) % width;
            screen[screenRow][screenColumn] =
                getMobileSprite(mobile)->symbols[row + SPRITE_SIZE / 2][column + SPRITE_SIZE / 2];
        }
    }
}

int getSkyHeight(Sky *sky) {
    return sky == NULL ? 0 : sky->height;
}

int getSkyWidth(Sky *sky) {
    return sky == NULL ? 0 : sky->width;
}

void putMobileOnSky(Sky *sky, Mobile *mobile) {
    for (int i = 0; i < MAX_MOBILE_ON_SKY; i++) {
        if (sky->mobileOnSky[i] == NULL) {
            sky->mobileOnSky[i] = mobile;
            return;
        }
    }
}