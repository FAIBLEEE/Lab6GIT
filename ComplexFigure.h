#pragma once
#include "Figure.h"
#include "Triangle.h"
#include "Rect.h"

class ComplexFigure : public Figure {
public:
    ComplexFigure(int x, int y, int triangleSide, COLORREF triangleBg, COLORREF triangleBorder, COLORREF rectBg, COLORREF rectBorder);

    ~ComplexFigure();

    void draw() override;
    void hide() override;
    void move(int newX, int newY) override;

private:
    Triangle* triangle;
    Rect* rect;
};