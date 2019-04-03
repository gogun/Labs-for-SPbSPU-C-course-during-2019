#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(point_t position, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(point_t newPosition) override;
  void move(double dx, double dy) override;

private:
  point_t position_;
  double radius_;
};

#endif //CIRCLE_HPP
