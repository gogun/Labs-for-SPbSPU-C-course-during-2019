#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t getCenter() const = 0;
  virtual void move(const point_t&) = 0;
  virtual void move(double, double) = 0;
};

#endif
