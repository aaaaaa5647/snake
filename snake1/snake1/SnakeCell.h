#pragma once
#include "raylib-cpp-master/include/raylib-cpp.hpp"

class SnakeCell
{
public:
    raylib::Vector2 pos;
    SnakeCell* next;
    SnakeCell* prev;
    SnakeCell(raylib::Vector2 po, SnakeCell* n, SnakeCell* p)
    {
        pos = po;
        next = n;
        prev = p;
    }
    SnakeCell(raylib::Vector2 po) : SnakeCell(po, nullptr, nullptr) {}
    void Draw()
    {
        raylib::Vector3 pos3D(pos.x, 1, pos.y);
        pos3D.DrawCube(raylib::Vector3(2, 2, 2), raylib::RED);
    }
};