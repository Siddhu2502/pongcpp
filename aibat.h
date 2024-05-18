#ifndef AIBAT_H
#define AIBAT_H
#include "bat.h"

class aibat : public bat
{
public:
    aibat();
    void update(int ball_y, ball &ball);
};

#endif // AIBAT_H
