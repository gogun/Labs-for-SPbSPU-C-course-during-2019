#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &center, double width, double height);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t &newPoint);
  void move(double dx, double dy);
  void inform() const;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif
