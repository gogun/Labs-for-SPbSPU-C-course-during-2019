#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle (const point_t &p, double r);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &p) override;
  void move(double dx, double dy) override;

private:
  point_t pos;
  double radius;
};

#endif
