#include "sugl.h"
#include <cmath>

SUGL::SUGL()
{
    for (int i = 0; i < 6; ++i)
    {
        vertices[i] = Point();
    }
}



SUGL::SUGL(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6)
    : vertices{p1, p2, p3, p4, p5, p6} {
}

Point SUGL::geometricCenter() const {
    Point center = {0, 0};
    for (int i = 0; i < 6; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= 6;
    center.y /= 6;
    return center;
}

double SUGL::area() const {
    double area = 0.0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6;
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

void SUGL::print(std::ostream& vivod) const {
    vivod << "Hexagon vertices: ";
    for (int i = 0; i < 6; ++i) {
        vivod << "(" << vertices[i].x << "," << vertices[i].y << ")";
        if (i < 5) vivod << " ";
    }
}

void SUGL::read(std::istream& vvod) {
    for (int i = 0; i < 6; ++i) {
        vvod >> vertices[i].x >> vertices[i].y;
    }
}

SUGL::SUGL(const SUGL& other) {
    for (int i = 0; i < 6; ++i) {
        vertices[i] = other.vertices[i];
    }
}

SUGL& SUGL::operator=(const SUGL& other) {
    if (this != &other) {
        for (int i = 0; i < 6; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

SUGL::SUGL(SUGL&& other) noexcept {
    for (int i = 0; i < 6; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

SUGL& SUGL::operator=(SUGL&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 6; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool SUGL::operator==(const SUGL& other) const {
    for (int i = 0; i < 6; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}