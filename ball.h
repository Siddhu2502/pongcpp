#ifndef BALL_H
#define BALL_H
#include <raylib.h>


class ball
{
public:
    float x, y;
    float speedx, speedy;
    int radius;

    ball();
    void draw();
    void update(int screenHeight, int screenWidth,
                int &aiscore, int &playerscore);
    void reset(int screenHeight, int screenWidth);
};

#endif // BALL_H
