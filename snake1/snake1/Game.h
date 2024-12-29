#pragma once
#include "raylib-cpp-master/include/raylib-cpp.hpp"
#include "Snake.h"
using namespace raylib;
class Game 
{
public:    
    raylib::Camera3D camera;
    Snake snake;    
    int width;
    int height;
    bool isRunning = true;
    Game()
    {
        camera.position = { 10, 10, 10 };
        camera.target = { 0, 0, 0 };        
        camera.up = { 0, 1, 0 };
        camera.fovy = 70;        
        camera.projection = CAMERA_PERSPECTIVE;
        width = 20;        
        height = 30;
    }    
    bool Update()
    {
        camera.Update(CAMERA_FREE);
        camera.BeginMode();        
        raylib::Vector3 borderX(width, 5, -0.5);
        borderX.DrawCube(raylib::Vector3(width, 5, 0.5) * 2, raylib::PURPLE);
        borderX.z = height * 2 + 0.5;
        borderX.DrawCube(raylib::Vector3(width, 5, 0.5) * 2, raylib::PURPLE);
        raylib::Vector3 borderY(-0.5, 5, height);
        borderY.DrawCube(raylib::Vector3(0.5, 5, height) * 2, raylib::BLUE);
        borderY.x = width * 2 + 0.5;
        borderY.DrawCube(raylib::Vector3(0.5, 5, height) * 2, raylib::BLUE);
        snake.Update(width, height);
        if (snake.position.x > width * 2 || snake.position.y > height * 2 || snake.position.x < 1 || snake.position.y < 1)
            isRunning = false;
        if (snake.sb.CheckCollision(snake.position))
            isRunning = false;
        DrawGrid(100, 2);
        camera.EndMode();
        return true;
    }
};