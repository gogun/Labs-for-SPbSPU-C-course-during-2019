#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{

public:

  Rectangle(double width, double height, point_t center);

  double getArea() const noexcept override;

  rectangle_t getFrameRect() const noexcept override;

  void move(double dx, double dy) noexcept override;

  void move(point_t newPos) noexcept override;

private:

  double width_;
  double height_;
  point_t center_;

};

#endif