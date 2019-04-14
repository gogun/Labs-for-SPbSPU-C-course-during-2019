//
// Created by Andrei Soprachev on 2019-03-31.
//
#include "circle.hpp"
#include <cassert> //need for assert
#include "math.h"  //need for pi constant

Circle::Circle(const point_t &pos, double radius) :
  Shape(pos),
  radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t result;
  result.pos = this->pos_.getPoint();
  result.height = this->radius_ * 2;
  result.width = this->radius_ * 2;
  return result;
}

std::string Circle::getName() const
{
  return "Circle";
}
