#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const double radius, const point_t &point);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(const point_t &point) override;
  void move(const double dx, const double dy) override;
private:
  double radius_;
  point_t pos_;
};

#endif
