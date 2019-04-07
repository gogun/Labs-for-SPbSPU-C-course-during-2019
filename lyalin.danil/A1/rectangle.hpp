#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &position, double width, double height);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(double dx, double dy) override;

  void move(const point_t &position) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif
