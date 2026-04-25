#include<iostream>
#include"Windows.h"
#include "Widget.h"


Widget::Widget(){};
Widget::Widget(int x, int y,  int height, int width): x(x), y(y), height(height), width(width){}
void Widget::setY(int Y)
{
    this->y = Y;
}

void Widget::setX(int X)
{
    this->x = X;
}

void Widget::focus()
{
    focused =  true;
}

void Widget::unfocus()
{
    focused = false;
}

int Widget::getY()
{
    return y;
}

int Widget::getX()
{
    return x;
}

int Widget::getHeight()
{
    return height;
}

int Widget::getWidth()
{
    return width;
}

bool Widget::getfocus()
{
    return focused;
}

Widget::~Widget(){};

