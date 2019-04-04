#ifndef LABS_SHAPE_HPP
#define LABS_SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  public:
  virtual ~Shape() = default;

  virtual void move(const point_t &newCenter) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void writeInfo() const = 0;
};

#endif
