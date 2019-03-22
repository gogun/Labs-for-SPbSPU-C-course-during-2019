#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(double width, double height, double x, double y);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const point_t &point) override;
    void move(const double dx, const double dy) override;

  private:
    rectangle_t parameters_;
};
 
#endif