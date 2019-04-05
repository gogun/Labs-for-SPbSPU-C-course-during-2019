#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, const double height, const double width);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const double dx, const double dy);
  void move(const point_t &point);
  point_t getCenter() const;
  void show() const ;

private:
  rectangle_t rect_;
};

#endif
