#pragma once
#include "SnakeCell.h"
class SnakeBody
{
public:
    SnakeCell* first;
    SnakeCell* last;
    int size;
    SnakeBody()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    void AddBody(raylib::Vector2 head)
    {
        if (size == 0)
        {
            first = new SnakeCell(head);
            last = first;
            size += 1;
        }
        else
        {
            SnakeCell* n = new SnakeCell(head);
            first->prev = n;
            n->next = first;
            first = n;
            size += 1;
        }
    }
    void Turn(raylib::Vector2 head)
    {
        if (size != 0)
        {
            last->pos = head;
            if (size != 1)
            {
                last->next = first;
                first->prev = last;
                first = last;
                last = last->prev;
            }
        }
    }
    void Draw()
    {
        SnakeCell* c = first;
        for (int i = 0; i < size; i++) {
            c->Draw();
            if (c->next) 
                c = c->next;
        }
    }
    bool CheckCollision(raylib::Vector2 head)
    {
        SnakeCell* c = first;
        for (int i = 0; i < size; i++)
        {
            if (head == c->pos)
                return true;
            if (c->next)
                c = c->next;
        }
        return false;
    }
};