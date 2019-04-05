#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#define _USE_MATH_DEFINES

#include "shape.hpp"
#include <cmath>
#include <cassert>

class Circle : public Shape
{
public:
  Circle(const point_t &center_, const double rad);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &center_) override;
  void move(const double dx, const double dy) override;
private:
  point_t center;
  double radius;
};

#endif
