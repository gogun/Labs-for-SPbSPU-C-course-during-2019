#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
private:
  point_t center;
  double radius;
  double area;
  rectangle_t frameRect;

public:
  Circle(point_t center, double radius);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double x, double y);
  void moveTo(double x, double y);
};

#endif // CIRCLE_HPP
