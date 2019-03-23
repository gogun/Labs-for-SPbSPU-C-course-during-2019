#include "circle.hpp"
#include <cmath>

Circle::Circle(const point_t &center, double radius)
{
  this->center_ = center;
  this->radius_ = radius;
  this->area_ = (M_PI * radius * radius);
  this->frameRect_ = {2 * radius, 2 * radius, center};
}

double Circle::getArea() const
{
  return this->area_;
}

rectangle_t Circle::getFrameRect() const
{
  return this->frameRect_;
}

void Circle::move(double x, double y)
{
  this->center_.x += x;
  this->center_.y += y;
  this->frameRect_.pos = this->center_;
}

void Circle::move(const point_t &point)
{
  this->center_ = point;
  this->frameRect_.pos = this->center_;
}
