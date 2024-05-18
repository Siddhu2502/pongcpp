#include "ball.h"

ball::ball() {
}

void ball::draw()
{
    DrawCircle(x, y, radius, GREEN);
}

void ball::update(int screenHeight, int screenWidth,
                    int &aiscore, int &playerscore){
    x += speedx;
    y += speedy;

    // Check for collision with top and bottom of the screen
    if (y - radius <= 0 || y + radius >= screenHeight) {
        speedy *= -1; // Reverse the y direction
    }

    if (x + radius >= screenWidth){
        aiscore++;
        reset(screenHeight, screenWidth);
    }

    if (x - radius <= 0 ){
        playerscore++;
        reset(screenHeight, screenWidth);
    }
}

void ball::reset(int screenHeight, int screenWidth){
    x = screenWidth/2;
    y = screenHeight/2;

    int speed_choice[2] = {-1, 1};
    speedx *= speed_choice[GetRandomValue(0,1)];
    speedy *= speed_choice[GetRandomValue(0,1)];
}
