#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &center, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &center) override;
  void move(double dx, double dy) override;

private:
  rectangle_t rectangle_;
};

#endif
