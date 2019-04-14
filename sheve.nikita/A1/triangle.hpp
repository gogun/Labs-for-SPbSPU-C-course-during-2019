#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &p1, const point_t &p2, const point_t &p3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &p) override;
  void move(const double dx, const double dy) override;

private:
  point_t pos;
  point_t a;
  point_t b;
  point_t c;
};

#endif
