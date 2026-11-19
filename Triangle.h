#pragma once
#include "Figure.h"
#include <cmath>
//Класс треугольник
class Triangle : public Figure {
public:
    Triangle(int x, int y, int side, COLORREF bg, COLORREF border);
    ~Triangle();

    void draw() override;
    void hide() override;

    int getHeight() const { return height; }
    int getSide() const { return side; }
    int getX() const { return position.x; }
    int getY() const { return position.y; }

private:
    int side;
    int height;
};