#include <stdio.h>

#include "Sky.h"

int main(void) {
    Sky *sky = createSky(5, 10);

    displaySky(sky);

    destroySky(sky);
}
