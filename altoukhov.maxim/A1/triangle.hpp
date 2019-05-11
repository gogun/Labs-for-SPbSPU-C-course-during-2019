#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t&, const point_t&, const point_t&);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getCenter() const override;
  void move(const point_t&) override;
  void move(double, double) override;

private:
  point_t a_, b_, c_;
};

#endif
