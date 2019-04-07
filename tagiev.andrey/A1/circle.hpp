#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &, double);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(double, double) override;
  void move(const point_t &) override;

private:
  point_t center_;
  double radius_;
};

#endif
