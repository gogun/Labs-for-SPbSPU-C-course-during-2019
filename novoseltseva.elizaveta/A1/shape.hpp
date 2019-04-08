#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual void getArea() const = 0;
  void move(float dx, float dy);
  void move(const point_t& point);
  rectangle_t object;
  rectangle_t getFrameRect();
};

#endif
