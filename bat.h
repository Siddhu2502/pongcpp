#ifndef BAT_H
#define BAT_H
#include "ball.h"

class bat
{
public:
    float x, y;
    float width, height;
    float speed;

    bat();
    void draw();
    void checkcollison();
    void checkcollisionball(ball &ball);
    void update(ball &ball);
};

#endif // BAT_H
