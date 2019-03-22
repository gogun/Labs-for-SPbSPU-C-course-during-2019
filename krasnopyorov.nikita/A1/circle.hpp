#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Circle: public Shape
{
public:
  Circle(double radius, point_t dot);
  void move(double deltax, double deltay);
  void move(const point_t &dot);
  double getArea() const;
  void writeChanges() const;
  rectangle_t getFrameRect() const;
private:
  point_t centre_;
  double r_;
};

#endif
