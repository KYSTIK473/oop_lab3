#include "arr.h"
#include <iostream>
#include <algorithm>

FigureArray::FigureArray() : data(nullptr), capacity(0), currentSize(0), totalAreaValue(0.0) {}

FigureArray::FigureArray(size_t initialCapacity) : capacity(initialCapacity), currentSize(0), totalAreaValue(0.0) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        data[i] = nullptr;
    }
}

FigureArray::FigureArray(const FigureArray& other) : capacity(other.capacity), currentSize(other.currentSize), totalAreaValue(other.totalAreaValue) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < currentSize; ++i) {
        data[i] = other.data[i];
    }
    for (size_t i = currentSize; i < capacity; ++i) {
        data[i] = nullptr;
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept 
    : data(other.data), capacity(other.capacity), currentSize(other.currentSize), totalAreaValue(other.totalAreaValue) {
    other.data = nullptr;
    other.capacity = 0;
    other.currentSize = 0;
    other.totalAreaValue = 0.0;
}

FigureArray::~FigureArray() {
    clear();
    delete[] data;
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        clear();
        delete[] data;
        
        capacity = other.capacity;
        currentSize = other.currentSize;
        totalAreaValue = other.totalAreaValue;
        
        data = new Figure*[capacity];
        for (size_t i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
        for (size_t i = currentSize; i < capacity; ++i) {
            data[i] = nullptr;
        }
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        clear();
        delete[] data;
        
        data = other.data;
        capacity = other.capacity;
        currentSize = other.currentSize;
        totalAreaValue = other.totalAreaValue;
        
        other.data = nullptr;
        other.capacity = 0;
        other.currentSize = 0;
        other.totalAreaValue = 0.0;
    }
    return *this;
}

Figure*& FigureArray::operator[](size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const Figure* FigureArray::operator[](size_t index) const {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void FigureArray::resize(size_t newCapacity) {
    Figure** newData = new Figure*[newCapacity];
    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    for (size_t i = currentSize; i < newCapacity; ++i) {
        newData[i] = nullptr;
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void FigureArray::updateTotalArea() {
    totalAreaValue = 0.0;
    for (size_t i = 0; i < currentSize; ++i) {
        if (data[i] != nullptr) {
            totalAreaValue += data[i]->area();
        }
    }
}

void FigureArray::addFigure(Figure* figure) {
    if (currentSize >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[currentSize] = figure;
    currentSize++;
    totalAreaValue += figure->area();
}

void FigureArray::removeFigure(size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    if (data[index] != nullptr) {
        totalAreaValue -= data[index]->area();
        delete data[index];
    }
    
    for (size_t i = index; i < currentSize - 1; ++i) {
        data[i] = data[i + 1];
    }
    data[currentSize - 1] = nullptr;
    currentSize--;
}

void FigureArray::clear() {
    for (size_t i = 0; i < currentSize; ++i) {
        if (data[i] != nullptr) {
            delete data[i];
            data[i] = nullptr;
        }
    }
    currentSize = 0;
    totalAreaValue = 0.0;
}

size_t FigureArray::size() const {
    return currentSize;
}

double FigureArray::totalArea() const {
    return totalAreaValue;
}

size_t FigureArray::getCapacity() const {
    return capacity;
}

bool FigureArray::empty() const {
    return currentSize == 0;
}