#pragma once
#include "Figure.h"

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