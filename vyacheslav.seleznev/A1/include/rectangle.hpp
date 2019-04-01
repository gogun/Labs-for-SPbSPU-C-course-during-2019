#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base_types.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
  public:
  Rectangle(double width, double height, point_t pos);
  double getArea();
  rectangle_t getFrameRect();

  private:
  double width;
  double height;
};

#endif