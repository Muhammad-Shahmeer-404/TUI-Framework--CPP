#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include "Windows.h"
#include <functional>


class Button : public Widget
{
private:
    std::function<void()> onClick;
    std::string label;
    bool isDir;
public:
    Button();
    Button(int x, int y, int height, int width, std::string label , bool isDir,std::function<void()> onClick);
    void render(Window& w) override;
    void handleInput(int k) override;
};

#endif