#pragma once
#include <queue>
#include <memory>
#include <initializer_list>
#include "Figure.h"
//Класс очереди
class FigureQueue {
public:
    FigureQueue();
    FigureQueue(std::initializer_list<std::shared_ptr<Figure>> figs);
    ~FigureQueue();

    void push(std::shared_ptr<Figure> figure);
    void clear();
    void displayAll();
    void hideAll();

private:
    std::queue<std::shared_ptr<Figure>> figures;
};