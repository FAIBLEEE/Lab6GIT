#include "ComplexFigure.h"

ComplexFigure::ComplexFigure(int x, int y, int triangleSide,
    COLORREF triangleBg, COLORREF triangleBorder,
    COLORREF rectBg, COLORREF rectBorder)
    : Figure(x, y, triangleBg, triangleBorder) {

    triangle = new Triangle(x, y, triangleSide, triangleBg, triangleBorder);

    int rectX = triangle->getX() - triangle->getSide() / 4;
    int rectY = triangle->getY() + triangle->getHeight() / 2;
    int rectW = triangle->getSide() / 2;
    int rectH = triangle->getHeight() / 2;

    rect = new Rect(rectX, rectY, rectW, rectH, rectBg, rectBorder);
}

ComplexFigure::~ComplexFigure() {
    delete triangle;
    delete rect;
}

void ComplexFigure::draw() {
    triangle->draw();
    rect->draw();
}

void ComplexFigure::hide() {
    triangle->hide();
    rect->hide();
}

void ComplexFigure::move(int newX, int newY) {
    hide();

    position.x = newX;
    position.y = newY;

    triangle->move(newX, newY);

    int newRectX = triangle->getX() - triangle->getSide() / 4;
    int newRectY = triangle->getY() + triangle->getHeight() / 2;
    rect->move(newRectX, newRectY);

    draw();
}

