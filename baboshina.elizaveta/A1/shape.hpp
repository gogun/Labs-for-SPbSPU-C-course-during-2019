#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t point) = 0;
  virtual void move(const double x, const double y) = 0;
  virtual void getInfo() const = 0;
};

#endif // !SHAPE_HPP
