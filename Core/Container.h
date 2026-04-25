#ifndef CONTAINER_H
#define CONTAINER_H

#include "Widget.h"
#include "Windows.h"

class Container: public Widget
{
protected:
    Widget** myWidget;
    int currentWidget;
    int capacity;
    int foucusIndex;
public:
    Container();
    Container(int capacity, int x, int y, int height, int width);
    virtual void addWidget(Widget* w);
    void render(Window& w) override;
    void handleInput(int k) override;
    virtual void reset() = 0;
    int getFocusedIndex();
    ~Container();
};



#endif