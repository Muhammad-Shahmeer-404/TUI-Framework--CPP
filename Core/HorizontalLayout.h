#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H


#include "Container.h"
#include "Widget.h"
#include "Windows.h"

class HorizontalLayout: public Container
{
private:
    int horizontalPosition;
public:
    HorizontalLayout(int x, int y, int height, int width, int capacity);
    void addWidget(Widget *w) override; 
    void reset() override;
};


#endif