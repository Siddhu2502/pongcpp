#include "bat.h"

bat::bat() {
}

void bat::draw(){
    DrawRectangle(x, y, width, height, WHITE);
}

void bat::checkcollison(){

    // checking collision top and bottom
    if (y <= 0){
        y = 0;
    }
    if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }
}

void bat::checkcollisionball(ball &ball){
    if (ball.x - ball.radius <= x + width && ball.x + ball.radius >= x
        && ball.y - ball.radius <= y + height && ball.y + ball.radius >= y){
        ball.speedx *= -1;
    }
}

void bat::update(ball &ball){

    checkcollison();
    checkcollisionball(ball);

    // pressing up command
    if(IsKeyDown(KEY_UP)){
        y -= speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y += speed;
    }
}
