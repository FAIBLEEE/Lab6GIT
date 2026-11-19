//Реализация базовой фигуры
#include "Figure.h"

Figure::Figure() : position{ 0, 0 }, bgColor(RGB(240, 240, 240)), borderColor(RGB(240, 240, 240)) {
    hWindow = GetConsoleWindow();
    hDC = GetDC(hWindow);
    GetClientRect(hWindow, &windowRect);
}

Figure::Figure(int x, int y, COLORREF bg, COLORREF border)
    : position{ x, y }, bgColor(bg), borderColor(border) {
    hWindow = GetConsoleWindow();
    hDC = GetDC(hWindow);
    GetClientRect(hWindow, &windowRect);
}

Figure::~Figure() {
    ReleaseDC(hWindow, hDC);
}

void Figure::move(int newX, int newY) {
    hide();
    position.x = newX;
    position.y = newY;
    draw();
}

void Figure::draw() {
}

void Figure::hide() {
}
