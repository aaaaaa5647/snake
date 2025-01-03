#include <iostream> 
#include <chrono> 
#include <string> 
#include "Game.h"
#include "raylib-cpp-master/include/raylib-cpp.hpp" 
using namespace std;
using namespace raylib;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    Window window(screenWidth, screenHeight, "Game Test");
    window.SetTargetFPS(60);
    raylib::Font font("raylib-cpp-master/raylib-cpp-master/examples/text/resources/pixantiqua.fnt");
    Text text(font, "Game over!", 30, 1, raylib::BLACK);
    Game game;
    DisableCursor();
    while (!WindowShouldClose())
    {
        window.BeginDrawing();
        window.ClearBackground(raylib::RAYWHITE);
        if (game.isRunning)
        {
            game.Update();
        }
        else
        {
            text.Draw(315, 340);
        }
        window.DrawFPS();
        window.EndDrawing();
    }
    return 0;
}
