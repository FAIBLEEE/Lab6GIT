#pragma once
#include "Figure.h"
//Класс квадрат
class Rect : public Figure {
public:
    Rect(int x, int y, int width, int height, COLORREF bg, COLORREF border);
    ~Rect();

    void draw() override;
    void hide() override;

private:
    int width;
    int height;
};