#ifndef CIRCLE_H
#define CIRCLE_H
#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &, const double);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(const double, const double) override;
  void move(const point_t &) override;
  void printInfo() const override;
private:
  double radius_;
  point_t center_;
};

#endif
