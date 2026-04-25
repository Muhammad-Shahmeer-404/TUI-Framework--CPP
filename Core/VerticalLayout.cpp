#include<iostream>
#include "VerticalLayout.h"
#include "Container.h"
#include "Widget.h"
#include "Windows.h"

VerticalLayout::VerticalLayout(int x, int y, int height, int width, int capacity):
Container(capacity, x, y, height, width)
{
    verticalPosition = y;
}

void VerticalLayout::addWidget(Widget* w)
{
    if(verticalPosition + w->getHeight() <= y+height)
    {
        w->setY(verticalPosition);
        verticalPosition += w->getHeight();
        Container::addWidget(w);

    }else
    {
        std::cerr << "Out of bounds";
        std::cerr << currentWidget;
        std::cerr << "position: " << verticalPosition 
          << " widget width: " << w->getHeight() 
          << " limit: " << x + height;
    }
}

void VerticalLayout::reset()
{
    currentWidget = 0; 
    foucusIndex = 0;
    verticalPosition = y;
}

