#ifndef shape_hpp
#define shape_hpp

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &newPoint) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void info() const = 0;
};

#endif
