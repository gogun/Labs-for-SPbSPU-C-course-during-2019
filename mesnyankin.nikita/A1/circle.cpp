#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>


Circle::Circle(double radius, const point_t &pos) :
  radius_(radius),
  pos_(pos)
{
  assert(radius_ >= 0.0);
}

Circle::Circle(double radius, double posX, double posY) :
  radius_(radius),
  pos_({posX, posY})
{
  assert(radius_ >= 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

double Circle::getRadius() const
{
  return radius_;
}

point_t Circle::getPos() const
{
  return pos_;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, radius_ * 2, radius_ * 2};
}
