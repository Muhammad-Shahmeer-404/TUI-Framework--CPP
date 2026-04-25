#include<iostream>
#include "Windows.h"
#include "Widget.h"
#include "Box.h"

Box::Box(int x, int y, int height, int width):
Widget(x, y, height, width){}

void Box::render(Window& w)
{
    if(focused == true)
    {
        w.setChar(y+1, x+1, '>');
    }
    w.setChar(y,x, '+');
    w.setChar(y, x+width-1, '+');
    w.setChar(y+height-1, x, '+');
    w.setChar(y+height-1, x+width-1, '+');
    
    for(int i = x+1; i <= x+width-2; i++)
    {
        w.setChar(y, i, '-');
        w.setChar(y+height-1, i, '-');
    }   
    for(int j = y+1; j <= y+height-2; j++)
    {
        w.setChar(j, x, '|');
        w.setChar(j, x+width-1, '|');
    }
}

void Box::handleInput(int key){}