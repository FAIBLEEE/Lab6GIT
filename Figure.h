#pragma once
#include <iostream>
#include "string"
#include <windows.h>
#include <stdexcept>
#include <memory>
//Базовый класс фигуры
class Figure {
public:
    Figure();
    Figure(int x, int y, COLORREF bg, COLORREF border);
    virtual ~Figure();

    virtual void draw();
    virtual void hide();
    virtual void move(int newX, int newY);

    class BorderException : public std::range_error {
    public:
        BorderException(const std::string& msg) : std::range_error(msg) {}
    };

    class InvalidParameters : public std::invalid_argument {
    public:
        InvalidParameters(const std::string& msg) : std::invalid_argument(msg) {}
    };

protected:
    COLORREF bgColor;
    COLORREF borderColor;
    HWND hWindow;
    HDC hDC;
    RECT windowRect;
    POINT position;
};