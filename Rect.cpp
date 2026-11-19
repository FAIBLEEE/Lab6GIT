#include "Rect.h"
#include "string"
//Реализация класса квадрат

Rect::Rect(int x, int y, int w, int h, COLORREF bg, COLORREF border) : Figure(x, y, bg, border), width(w), height(h) {
    if (w <= 0 || h <= 0) {
        std::string msg = "Ширина = " + std::to_string(w) + "\nВысота: = "+std::to_string(h) +"\nПараметры прямоугольника должны быть положительными";
        throw InvalidParameters(msg);
    }
}

Rect::~Rect() {}

void Rect::draw() {
    int left = position.x;
    int top = position.y;
    int right = position.x + width;
    int bottom = position.y + height;

    if (left < windowRect.left || top < windowRect.top ||
        right > windowRect.right || bottom > windowRect.bottom) {
        std::string msg = "Прямоугольник: left=" + std::to_string(left) + ", top=" + std::to_string(top) +
            ", right=" + std::to_string(right) + ", bottom=" + std::to_string(bottom) +
            ". Фигура выходит за границы окна (границы: left=" + std::to_string(windowRect.left) +
            ", top=" + std::to_string(windowRect.top) +
            ", right=" + std::to_string(windowRect.right) +
            ", bottom=" + std::to_string(windowRect.bottom) + ")";
        throw BorderException(msg);
    }

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    Rectangle(hDC, left, top, right, bottom);

    DeleteObject(pen);
    DeleteObject(brush);
}

void Rect::hide() {
    int left = position.x;
    int top = position.y;
    int right = position.x + width;
    int bottom = position.y + height;

    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    Rectangle(hDC, left, top, right, bottom);

    DeleteObject(pen);
    DeleteObject(brush);
}