#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual void move(double deltax, double deltay) = 0;
  virtual void move(const point_t &dot) = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
};

#endif
