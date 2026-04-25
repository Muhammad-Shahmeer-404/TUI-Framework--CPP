#include<iostream>
#include <sys/ioctl.h>
#include<unistd.h>
#include"Windows.h"



Window::Window(int height, int width): height(height), width(width)
{
    buffer = new Cell*[height];
    for(int w = 0; w < height; w++)
    {
        buffer[w] = new Cell[width];
    }
    clear();
}


void Window::clear()
{
    for(int h = 0; h < height ;h++)
    {
        for(int w = 0; w < width; w++)
        {
            buffer[h][w].ch = ' ';
            buffer[h][w].color = 0;
        }
    }
}

void Window::flush()
{
    std::cout << "\x1b[H";
    for(int h = 0; h < height ;h++)
    {
        for(int w = 0; w < width; w++)
        {
            std::cout << "\x1b[" << buffer[h][w].color << "m";
            std::cout << buffer[h][w].ch;
        }
        if(h < height - 1)
        {
            std::cout << '\r' <<'\n';
        }
    }
        std::cout << "\x1b[0m";
        std::cout.flush();
}

Window::~Window()
{
    for(int i = 0; i < height; i++)
    {
        delete[] buffer[i];
    }
    delete[] buffer;
}

void Window::setChar(int row, int col, char c, int color)
{
    if(col < width && row < height)
    {
        buffer[row][col].color = color;
        buffer[row][col].ch = c;
    }
}


