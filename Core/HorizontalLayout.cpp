#include<iostream>
#include "HorizontalLayout.h"
#include "Container.h"
#include "Widget.h"
#include "Windows.h"

HorizontalLayout::HorizontalLayout(int x, int y, int height, int width, int capacity):
Container(capacity, x, y, height, width)
{
    horizontalPosition = x;
}

void HorizontalLayout::addWidget(Widget* w)
{
    if(horizontalPosition + w->getWidth() <= x+width)
    {
        w->setX(horizontalPosition);
        horizontalPosition += w->getWidth();
        Container::addWidget(w);

    }else
    {
        std::cerr << "Out of bounds: ";  
        std::cerr << currentWidget;
        std::cerr << "position: " << horizontalPosition 
          << " widget width: " << w->getWidth() 
          << " limit: " << x + width;
    }
}

void HorizontalLayout::reset()
{
    currentWidget = 0; 
    foucusIndex = 0;
    horizontalPosition = x;
}


