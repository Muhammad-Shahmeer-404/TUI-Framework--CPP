#ifndef BOX_H
#define BOX_H


#include "Windows.h"
#include "Widget.h"

class Box : public Widget
{
public:
    Box(int x, int y, int height, int width);
    void render(Window& w) override;
    void handleInput(int key) override;
};

#endif