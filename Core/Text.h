#ifndef TEXT_H
#define TEXT_H

#include "Windows.h"
#include "Widget.h"
#include <iostream>

class Text : public Widget 
{
private:
    std::string sentence;
    int color;
public:
    Text(int x, int y, int height, int width, std::string sentence, int color);
    void render(Window& w) override;
    void handleInput(int key) override;
    void setSentence(std::string s);
};

#endif