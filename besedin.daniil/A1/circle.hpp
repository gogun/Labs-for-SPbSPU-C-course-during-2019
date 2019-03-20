#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double radius, point_t center);
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(double dx, double dy) noexcept override;
  void move(point_t newPos) noexcept override;

private:
  double radius_;
  point_t center_;
};

#endif
