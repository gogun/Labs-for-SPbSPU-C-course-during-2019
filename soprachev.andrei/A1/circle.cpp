//
// Created by Andrei Soprachev on 2019-03-31.
//
#include "circle.hpp"
#include <cassert> //need for assetr
#include "math.h"  //need for pi constant

Circle::Circle(const point_t &pos, double radius) :
  Shape(pos),
  radius(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius * radius;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t result;
  result.height = this->radius * 2;
  result.width = this->radius * 2;
  result.pos = this->pos;
  return result;
}
