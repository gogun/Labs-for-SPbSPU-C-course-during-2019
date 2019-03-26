#ifndef CIRCLE_H
#define CIRCLE_H
#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape{
private:
  point_t center_;
  double radius_;
public:
  Circle(const point_t &, double);

  double getArea() const override;

  void move(double, double) override;

  void move(point_t) override;
};

#endif
