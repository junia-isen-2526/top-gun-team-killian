#include <stdio.h>

#include "Sky.h"

int main(void) {
    Sky *sky = createSky(20, 100);
    Mobile *plane = createPlane(10,10,EAST,getSkyHeight(sky),getSkyWidth(sky));
    putMobileOnSky(sky,plane);


    displaySky(sky);

    destroySky(sky);

    system("Pause");
    return 0;
}
