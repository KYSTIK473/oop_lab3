#include "fugl.h"
#include <cmath>

FUGL::FUGL()
{
    for (int i = 0; i < 5; ++i)
    {
        vertices[i] = Point();
    }
}




FUGL::FUGL(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5)
    : vertices{p1, p2, p3, p4, p5} {
}


Point FUGL::geometricCenter() const {
    Point center = {0, 0};
    for (int i = 0; i < 5; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= 5;
    center.y /= 5;
    return center;
}

// Площадь (через формулу площади многоугольника)
double FUGL::area() const {
    double area = 0.0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

// Вывод вершин
void FUGL::print(std::ostream& vivod) const {
    vivod << "Pentagon vertices: ";
    for (int i = 0; i < 5; ++i) {
        vivod << "(" << vertices[i].x << "," << vertices[i].y << ")";
        if (i < 4) vivod << " ";
    }
}

// Чтение вершин
void FUGL::read(std::istream& vvod) {
    for (int i = 0; i < 5; ++i) {
        vvod >> vertices[i].x >> vertices[i].y;
    }
}

// Операция копирования
FUGL::FUGL(const FUGL& other) {
    for (int i = 0; i < 5; ++i) {
        vertices[i] = other.vertices[i];
    }
}

FUGL& FUGL::operator=(const FUGL& other) {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

FUGL::FUGL(FUGL&& other) noexcept {
    for (int i = 0; i < 5; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

FUGL& FUGL::operator=(FUGL&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 5; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool FUGL::operator==(const FUGL& other) const {
    for (int i = 0; i < 5; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}