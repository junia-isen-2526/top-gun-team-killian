//
// Created by JAD on 17/10/2025.
//

#include "Sprite.h"

Sprite* createSprite(char symbols[SPRITE_SIZE][SPRITE_SIZE]) {
    Sprite *newSprite=malloc(sizeof(Sprite));
    for (int i=0;i<SPRITE_SIZE;i++) {
        for (int j=0;j<SPRITE_SIZE;j++) {
            newSprite->symbols[i][j]=symbols[i][j];
        }
    }
    return newSprite;
}

void destroySprite(Sprite *sprite) {
    if (sprite == NULL) return;
    free(sprite);
}
