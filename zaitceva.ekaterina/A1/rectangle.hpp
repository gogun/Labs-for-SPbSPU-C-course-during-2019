#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle (double wdth, double hght, point_t ps);
    double getArea () const override;
    rectangle_t getFrameRect () const override;
    void move (point_t pnt) override;
    void move (double abs, double ord) override;
private:
    double width_;
    double height_;
    point_t pos_;
};

#endif //UNTITLED1_RECTANGLE_H
