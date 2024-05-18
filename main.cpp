#include <raylib.h>
#include <raymath.h>
#include "ball.h"
#include "bat.h"
#include "aibat.h"

const int screenHeight = 720;
const int screenWidth = 1280;

int playerscore = 0;
int aiscore = 0;
Texture2D texture;

void screen() {
    // Clear the background with a green color (like a tennis court)
    ClearBackground(DARKGREEN);

    // Draw the playfield lines
    // Outer border
    DrawRectangleLines(10, 10, screenWidth - 20, screenHeight - 20, WHITE);

    // Center line (dotted)
    for (int i = 10; i < screenHeight - 10; i += 20) {
        DrawRectangle(screenWidth / 2 - 2, i, 4, 10, WHITE);
    }

    // Service boxes (if needed for more detail)
    DrawLine(screenWidth / 4, 10, screenWidth / 4, screenHeight - 10, WHITE);
    DrawLine(3 * screenWidth / 4, 10, 3 * screenWidth / 4, screenHeight - 10, WHITE);

    // Additional service box lines
    DrawLine(10, screenHeight / 2, screenWidth - 10, screenHeight / 2, WHITE);

    // Some system stats
    DrawText(TextFormat("Current FPS: %03i", GetFPS()), 15, screenHeight - 20, 20, WHITE);

    // Player info
    int textwidth = MeasureText("Player Score A", 20);
    DrawText(TextFormat("Player A: %i", aiscore), screenWidth / 4 - textwidth / 2 , 20, 30, WHITE);
    DrawText(TextFormat("Player B: %i", playerscore), screenWidth / 2 + screenWidth / 4 - textwidth / 2, 20, 30, WHITE);
}


int main() {
    InitWindow(screenWidth, screenHeight, "Pong game");
    SetTargetFPS(144);


    // Attempt to load texture with correct relative path
    texture = LoadTexture("../../ping-pong-table-in-blue-color-top-view-vector.png");

    ball ball;
    ball.radius = 10;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedx = 2;
    ball.speedy = 2;

    bat bat;
    bat.width = 15;
    bat.height = 80;
    bat.x = screenWidth - 25;
    bat.y = (screenHeight - bat.height) / 2;
    bat.speed = 4;

    aibat aibat;
    aibat.width = 15;
    aibat.height = 80;
    aibat.x = 10;
    aibat.y = (screenHeight - bat.height) / 2;
    aibat.speed = 1.5;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        screen();
        ball.draw();
        ball.update(screenHeight, screenWidth, aiscore, playerscore);
        bat.draw();
        bat.update(ball);
        aibat.draw();
        aibat.update(ball.y, ball);
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();

    return 0;
}
