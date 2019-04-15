#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &center, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &center) override;
  void move(double dx, double dy) override;

private:
  point_t center_;
  double radius_;
};

#endif
