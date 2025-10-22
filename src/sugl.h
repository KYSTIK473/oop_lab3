#ifndef SUGL_H
#define SUGL_H

#include "figure.h"

class SUGL : public Figure {

    Point vertices[6];

public:
    SUGL();
    SUGL(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5, const Point& p6);
    
    Point geometricCenter() const override;
    virtual double area() const;
    void print(std::ostream& vivod) const override;
    void read(std::istream& vvod) override;

    SUGL(const SUGL& other);
    SUGL& operator=(const SUGL& other);
    

    SUGL(SUGL&& other) noexcept;
    SUGL& operator=(SUGL&& other) noexcept;
    

    bool operator==(const SUGL& other) const;
    
};

#endif // RHOMBUS_H