#pragma once 
#include "raylib-cpp-master/include/raylib-cpp.hpp"
#include <iostream>
using namespace raylib;
#include "SnakeBody.h" 
class Snake
{
public:
    raylib::Vector2 position;
    raylib::Vector2 direction;
    int timer;
    int count = 0;
    SnakeBody sb;
    bool moved;
    Snake()
    {
        position = { 5,5 };
        direction = { 1, 0 };
        timer = 0;
        moved = true;
    }

    bool Update(int w, int h)
    {
        if (moved)
        {
            if (IsKeyPressed(KEY_F))
                if (direction.y != 0) {
                    direction.x = -1;
                    direction.y = 0;
                    moved = false;
                }
            if (IsKeyPressed(KEY_T))
                if (direction.x != 0) {
                    direction.y = -1;
                    direction.x = 0;
                    moved = false;
                }
            if (IsKeyPressed(KEY_H))
                if (direction.y != 0) {
                    direction.x = 1;
                    direction.y = 0;
                    moved = false;
                }
            if (IsKeyPressed(KEY_G))
                if (direction.x != 0) {
                    direction.y = 1;
                    direction.x = 0;
                    moved = false;
                }
        }
        timer++;
        if (timer > 60)
        {
            timer = 0;
            if (count <= 4)
            {
                sb.AddBody(position);
                count++;
            }
            sb.Turn(position);
            position.x += 2 * direction.x;
            position.y += 2 * direction.y;
            moved = true;
        }
        raylib::Vector3 pos3D(position.x, 1, position.y);
        raylib::Vector3 dir3D(position.x + direction.x, 1, position.y + direction.y);
        pos3D.DrawCube(raylib::Vector3(2, 2, 2), raylib::RED);
        dir3D.DrawCube(raylib::Vector3(1, 1, 1), raylib::BLACK);
        sb.Draw();
        return true;
    }
};