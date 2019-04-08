#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

struct Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t & point) = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual void show() const = 0;
};

#endif
