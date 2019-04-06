#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() = 0;
  virtual const rectangle_t getFrameRect() = 0;
  virtual void move(const point_t &NewCentre) = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual void print() = 0;
protected:
  Shape(const point_t &pos);
  point_t pos_;
};
#endif
