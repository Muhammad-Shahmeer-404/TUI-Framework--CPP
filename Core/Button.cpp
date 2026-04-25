#include<iostream>
#include "Widget.h"
#include "Windows.h"
#include "Button.h"
#include <functional>
#include <string>

Button::Button(int x, int y,int height, int width, std::string label, bool isDir ,std::function<void()> onClick):
Widget(x, y, height, width), onClick(onClick), label(label), isDir(isDir) {}

Button::Button(){}

void Button::render(Window& w)
{
    if(focused == true)
    {
        w.setChar(y+1, x+1, '>', CYAN);

        w.setChar(y,x, '+',  CYAN); 
        w.setChar(y, x+width-1, '+', CYAN);
        w.setChar(y+height-1, x, '+', CYAN);
        w.setChar(y+height-1, x+width-1, '+', CYAN);

        for(int i = x+1; i <= x+width-2; i++)
        {
            w.setChar(y, i, '-', CYAN);
            w.setChar(y+height-1, i, '-', CYAN);
        }   
        for(int j = y+1; j <= y+height-2; j++)
        {
            w.setChar(j, x, '|', CYAN);
            w.setChar(j, x+width-1, '|', CYAN);
        }
        for(int i = 0; i < label.length(); i++)
        {
            w.setChar(y+height/2, (x + width/2 + i - label.length()/2), label[i], CYAN);
        }
    }else
    {
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
        if(isDir)
        {
            for(int i = 0; i < label.length(); i++)
            {
                w.setChar(y+height/2, (x + width/2 + i - label.length()/2), label[i], YELLOW);
            }
        }else
        {
            for(int i = 0; i < label.length(); i++)
            {
                w.setChar(y+height/2, (x + width/2 + i - label.length()/2), label[i]);
            }
        }
    } 
}


void Button::handleInput(int k)
{
    if(k == 13 || k == 98)
    {
        if(onClick) onClick();

    }
}


