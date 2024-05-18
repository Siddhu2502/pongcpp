#include "aibat.h"

aibat::aibat() {}

void aibat::update(int ball_y, ball &ball){

    checkcollison();
    checkcollisionball(ball);

    if (y + height /2 > ball_y){
        y -= speed;
    }
    if (y + height / 2 < ball_y){
        y += speed;
    }
}
