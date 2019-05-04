#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &, const point_t &, const point_t &);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getCentre() const override;
  void move(double dx, double dy) override;
  void move(const point_t &) override;

private:
  point_t p1_, p2_, p3_;
};

#endif
