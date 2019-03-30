#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(rectangle_t rectangle);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &point) override;

private:
  rectangle_t rectangle_;
};

#endif
