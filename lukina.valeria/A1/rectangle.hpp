#ifndef RectangleHPP
#define RectangleHPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double w, double h, point_t c);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t NewPoint) override;

private:
  double width_;
  double height_;
  point_t center_;
};

#endif
