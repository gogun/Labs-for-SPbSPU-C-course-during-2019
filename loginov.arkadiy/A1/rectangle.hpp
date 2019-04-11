#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &point, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getCentre() const override;
  void move(double dx, double dy) override;
  void move(const point_t &) override;

private:
  rectangle_t rectangle_;
};

#endif
