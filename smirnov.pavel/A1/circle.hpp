#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(double radius, const point_t & center);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & new_point) override;
  void move(double x_delta, double y_delta) override;
  void getInfo() const override;

private:
  double radius_;
  point_t center_;
};

#endif
