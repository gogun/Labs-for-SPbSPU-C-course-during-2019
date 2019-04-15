#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace lebedev
{
  class Shape
  {
    public:
	  virtual ~Shape() = default;
	  virtual double getArea() const = 0;
	  virtual rectangle_t getFrameRect() const = 0;
	  virtual void move(const double x, const double y) = 0;
	  virtual void move(const point_t &new_dot) = 0;
	  virtual void scale(const double multiplier) = 0;
  };
}
#endif
