#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

struct Point {
    double x;
    double y;
};

class Figure {
public:
    virtual ~Figure() = default;
    virtual Point geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

#endif // FIGURE_H