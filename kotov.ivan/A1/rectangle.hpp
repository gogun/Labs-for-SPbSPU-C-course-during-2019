#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:

  Rectangle(const point_t & center, double widht, double heigth);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t & newCenter) override;
  void move(double dX, double dY) override;

private:
  rectangle_t rect_;
};

#endif // RECTANGLE_HPP
