#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t dot, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t point) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif //RECTANGLE_HPP