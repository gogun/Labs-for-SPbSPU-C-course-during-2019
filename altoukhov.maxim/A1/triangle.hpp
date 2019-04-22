#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t& pos, double base, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& pos) override;
  void move(double x, double y) override;

private:
  point_t pos_;
  double base_, height_;
};

#endif
