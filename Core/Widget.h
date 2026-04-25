#ifndef WIDGET_H
#define WIDGET_H

#include "Windows.h"


class Widget
{
protected:
    int x, y;
    int height, width;
    bool focused;
public:
    Widget();
    Widget(int x, int y, int height, int width);
    virtual void render(Window& w) = 0;
    virtual ~Widget();
    virtual void handleInput(int key) = 0;
    void setY(int y);
    void setX(int x);
    void focus();
    void unfocus();
    int getY();
    int getX();
    int getHeight();
    int getWidth();
    bool getfocus();

};


#endif