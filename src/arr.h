#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H

#include "figure.h"
#include <stdexcept>

class FigureArray {
private:
    Figure** data;
    size_t capacity;
    size_t currentSize;
    double totalAreaValue;

    void resize(size_t newCapacity);
    void updateTotalArea();

public:
    FigureArray();
    FigureArray(size_t initialCapacity);
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    ~FigureArray();

    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;

    Figure*& operator[](size_t index);
    const Figure* operator[](size_t index) const;

    void addFigure(Figure* figure);
    void removeFigure(size_t index);
    void clear();

    size_t size() const;
    double totalArea() const;
    size_t getCapacity() const;
    bool empty() const;
};

#endif // FIGURE_ARRAY_H