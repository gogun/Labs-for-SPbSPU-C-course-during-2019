#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:
  Circle(double r, const point_t &position);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &p) override;
  point_t Center() const override;
  void print() const override;

private:
  double r_;
  point_t pos_;
};

#endif
