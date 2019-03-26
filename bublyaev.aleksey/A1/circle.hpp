#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &center, double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newPos) override;
  void move(double dx, double dy) override;
  void printInfo() const override;
private:
  point_t center_;
  double radius_;
};

#endif // CIRCLE_H
