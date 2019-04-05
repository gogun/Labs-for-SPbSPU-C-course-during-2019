#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(point_t);
  virtual double getArea() const = 0;
  void move(const double dx,const double dy);
  void move(const point_t &newp);
  virtual rectangle_t getFrameRect() const = 0;
protected:
  point_t center_;
};
#endif