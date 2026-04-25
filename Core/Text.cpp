#include <iostream>
#include <string.h>
#include "Windows.h"
#include "Widget.h"
#include "Text.h"

Text::Text(int x, int y, int height, int witdh, std::string sentence, int color):
Widget(x, y, height, witdh), sentence(sentence), color(color){}

void Text::render(Window& w){
    int count = x;
    for(int i = 0; i < sentence.length(); i++)
    {
        w.setChar(y, count, sentence[i], color);
        count++;  
    }
}

void Text::setSentence(std::string s)
{
    sentence = s;
    width = sentence.length();
}

void Text::handleInput(int key){}