#ifndef WINDOWS_H
#define WINDOWS_H

#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37


struct Cell
{
    char ch;
    int color;
};


class Window
{
private:
    int height;
    int width;
    Cell** buffer;
public:
    void clear();
    Window(int height, int width);
    void flush();
    void setChar(int col, int row, char c, int color = 0);
    ~Window();
};

#endif