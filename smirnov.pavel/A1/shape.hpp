#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t & new_point) = 0;
  virtual void move(double x_delta, double y_delta) = 0;
  virtual void getInfo() const = 0;
};

#endif
