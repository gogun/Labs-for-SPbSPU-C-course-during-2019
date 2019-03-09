#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(double x, double y) = 0;
  virtual void moveTo(double x, double y) = 0;
  virtual ~Shape(){};
};

#endif // SHAPE_HPP
