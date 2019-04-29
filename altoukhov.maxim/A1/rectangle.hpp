#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t&, double, double);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t&) override;
  void move(double, double) override;

private:
  point_t pos_;
  double width_, height_;
};

#endif
