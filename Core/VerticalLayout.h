#ifndef VERTICALLAYOUT_H
#define VERTICALLAYOUT_H

#include "Container.h"
#include "Widget.h"
#include "Windows.h"


class VerticalLayout : public Container
{
private:
    int verticalPosition;
public:
    VerticalLayout(int x, int y, int height, int width, int capacity);
    void addWidget(Widget* w) override;
    void reset() override;
};

#endif