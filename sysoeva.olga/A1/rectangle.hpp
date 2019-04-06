#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cassert>
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t & point, const double height_, const double width_);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & point) override;
  void move(const double dx, const double dy) override;
private:
  rectangle_t rect;
};

#endif
