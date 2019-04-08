#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const double &dX, const double &dY) = 0;
  virtual void move(const point_t &point) = 0;
  virtual void showInfo() const = 0;
  virtual void showCords() const = 0;
  virtual void showFrameRect() const = 0;
};

#endif
