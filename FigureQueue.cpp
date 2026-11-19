#include "FigureQueue.h"
#include <windows.h>
#include <stdexcept>
//–еализаци€€ класса очередь
FigureQueue::FigureQueue() {
}

FigureQueue::FigureQueue(std::initializer_list<std::shared_ptr<Figure>> figs) {
    for (auto fig : figs) {
        figures.push(fig);
    }
}

FigureQueue::~FigureQueue() {
    while (!figures.empty()) {
        figures.pop();
    }
}

void FigureQueue::push(std::shared_ptr<Figure> figure) {
    figures.push(figure);
}

void FigureQueue::displayAll() {
    std::queue<std::shared_ptr<Figure>> temp = figures;

    while (!temp.empty()) {
        temp.front()->draw();
        Sleep(800);
        temp.pop();
    }
}

void FigureQueue::clear() {
    while (!figures.empty()) {
        figures.pop();
    }
}

void FigureQueue::hideAll() {
    std::queue<std::shared_ptr<Figure>> temp = figures;

    while (!temp.empty()) {
        temp.front()->hide();
        Sleep(600);
        temp.pop();
    }
}