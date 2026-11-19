#include "Triangle.h"
//Реализация класса треугольника

Triangle::Triangle(int x, int y, int s, COLORREF bg, COLORREF border)
    : Figure(x, y, bg, border), side(s) {
    if (s <= 0) {
        std::string msg = "Сторона треугольника = " + std::to_string(s) + "\nСторона треугольника должна быть положительной";
        throw InvalidParameters(msg);
    }
    height = (int)(side * sqrt(3) / 2);
}

Triangle::~Triangle() {}

void Triangle::draw() {
    POINT pts[3] = {
        {position.x, position.y},
        {position.x - side / 2, position.y + height},
        {position.x + side / 2, position.y + height}
    };

    if (pts[0].x < windowRect.left || pts[0].y < windowRect.top ||
        pts[1].x < windowRect.left || pts[2].x > windowRect.right ||
        pts[2].y > windowRect.bottom) {
        std::string msg = "Координаты вершины: (" + std::to_string(position.x) + "," + std::to_string(position.y) +
            "), сторона a=" + std::to_string(side) +
            ". Треугольник выходит за границы окна";
        throw BorderException(msg);
    }

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    Polygon(hDC, pts, 3);

    DeleteObject(pen);
    DeleteObject(brush);
}

void Triangle::hide() {
    POINT pts[3] = {
        {position.x, position.y},
        {position.x - side / 2, position.y + height},
        {position.x + side / 2, position.y + height}
    };

    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    Polygon(hDC, pts, 3);

    DeleteObject(pen);
    DeleteObject(brush);
}