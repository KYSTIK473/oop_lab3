#ifndef FUGL_H
#define FUGL_H

#include "figure.h"

class FUGL : public Figure {

    Point vertices[5];

public:
    FUGL();
    FUGL(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5);
    
    Point geometricCenter() const override;
    virtual double area() const;
    void print(std::ostream& vivod) const override;
    void read(std::istream& vvod) override;

    FUGL(const FUGL& other);
    FUGL& operator=(const FUGL& other);
    

    FUGL(FUGL&& other) noexcept;
    FUGL& operator=(FUGL&& other) noexcept;
    

    bool operator==(const FUGL& other) const;
    
};

#endif // RHOMBUS_H