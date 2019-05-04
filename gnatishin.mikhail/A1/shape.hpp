#ifndef SHAPE_OF_MG
#define SHAPE_OF_MG

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t getPosition() const = 0;
  virtual void move(const point_t &center) = 0;
  virtual void move(double dx, double dy) = 0;
};

#endif
