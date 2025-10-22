#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus()
{
    for (int i = 0; i < 4; ++i)
    {
        vertices[i] = Point();
    }
}

Rhombus::Rhombus(const Rhombus& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}


Rhombus::Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices{p1, p2, p3, p4} {
}


Point Rhombus::geometricCenter() const {
    Point center = {0, 0};
    for (int i = 0; i < 4; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= 4;
    center.y /= 4;
    return center;
}

double Rhombus::area() const {
    double d1 = std::sqrt(std::pow(vertices[0].x - vertices[2].x, 2) + 
                         std::pow(vertices[0].y - vertices[2].y, 2));
    double d2 = std::sqrt(std::pow(vertices[1].x - vertices[3].x, 2) + 
                         std::pow(vertices[1].y - vertices[3].y, 2));
    return (d1 * d2) / 2.0;
}

void Rhombus::print(std::ostream& vivod) const {
    vivod << "Vershini: ";
    for (int i = 0; i < 4; ++i) {
        vivod << "(" << vertices[i].x << "," << vertices[i].y << ")";
        if (i < 3) vivod << " ";
    }
}

void Rhombus::read(std::istream& vvod) {
    for (int i = 0; i < 4; ++i) {
        vvod >> vertices[i].x >> vertices[i].y;
    }
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}


Rhombus::Rhombus(Rhombus&& other) noexcept {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    for (int i = 0; i < 4; ++i) {
        if (vertices[i].x != other.vertices[i].x || 
            vertices[i].y != other.vertices[i].y) {
            return false;
        }
    }
    return true;
}