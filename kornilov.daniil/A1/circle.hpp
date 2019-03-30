#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(double radius, const point_t &centre);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &point) override;

private:
  point_t pos_;
  double radius_;
};

#endif
