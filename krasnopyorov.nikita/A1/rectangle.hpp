#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(rectangle_t characteristics);
  void move(const point_t &dot);
  void move(double deltax, double deltay);
  double getArea() const;
  void writeChanges() const;
  rectangle_t getFrameRect() const;
private:
  rectangle_t characteristics_;
};

#endif
