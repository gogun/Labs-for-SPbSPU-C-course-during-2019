#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
private:
  point_t center;
  double width;
  double height;
  double area;
  rectangle_t frameRect;

public:
  Rectangle(point_t center, double width, double height);
  double getArea();
  rectangle_t getFrameRect();
  void move(double x, double y);
  void moveTo(double x, double y);
};

#endif // RECTANGLE_HPP
