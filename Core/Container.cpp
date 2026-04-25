#include<iostream>
#include "Widget.h"
#include "Container.h"
#include "Windows.h"

Container::Container(){}

Container::Container(int capacity, int x, int y, int height, int width): 
capacity(capacity), Widget(x,y, height, width) 
{ 
    currentWidget = 0;
    foucusIndex = 0;
    myWidget = new Widget*[capacity];
}

void Container::addWidget(Widget* w)
{
    if(capacity != currentWidget + 1)
    {
        myWidget[currentWidget] = w;
        if(currentWidget == 0) myWidget[currentWidget]->focus();
        currentWidget++;
    }else
    {
        std::cerr << "Capacity full";
    }
}

void Container::render(Window &w)
{ 
    for(int i = 0; i < currentWidget; i++)
    {
        myWidget[i]->render(w);
    }
}

void Container::handleInput(int k)
{
    if(k == 106)
    {
        int oldIndex = foucusIndex;
        foucusIndex = (foucusIndex + 1) % currentWidget;
        myWidget[foucusIndex]->focus();
        myWidget[oldIndex]->unfocus();
    
    }else if (k == 107)
    {
        int oldIndex = foucusIndex;
        foucusIndex = (foucusIndex - 1 + currentWidget) % currentWidget;
        myWidget[foucusIndex]->focus();
        myWidget[oldIndex]->unfocus();
    }else
    {
        myWidget[foucusIndex]->handleInput(k);
    }
}

int Container::getFocusedIndex()
{
    return foucusIndex;
}

Container::~Container()
{
    delete[] myWidget;
}