#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base_types.hpp"

class Shape
{
public:
  virtual ~Shape () = default;
  virtual double getArea () const = 0;
  virtual rectangle_t getFrameRect () const = 0;
  virtual void move (point_t pnt) = 0;
  virtual void move (double abs, double ord) = 0;
};
#endif // SHAPE_HPP
