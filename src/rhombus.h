#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {

    Point vertices[4];

public:
    Rhombus();
    Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    
    Point geometricCenter() const override;
    virtual double area() const;
    void print(std::ostream& vivod) const override;
    void read(std::istream& vvod) override;

    Rhombus(const Rhombus& other);
    Rhombus& operator=(const Rhombus& other);
    

    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(Rhombus&& other) noexcept;
    

    bool operator==(const Rhombus& other) const;
    
};

#endif // RHOMBUS_H