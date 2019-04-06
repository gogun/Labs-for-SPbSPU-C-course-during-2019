#include "circle.hpp"

Circle::Circle(const point_t & center, const double radius):
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rect;
  rect.width = radius_ * 2;
  rect.height = radius_ * 2;
  rect.pos = center_;
  return rect;
}

void Circle::move(const point_t & center)
{
  center_ = center;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}