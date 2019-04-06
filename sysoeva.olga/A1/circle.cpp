#include "circle.hpp"

Circle::Circle(const point_t & center_, const double rad) :
  center(center_),
  radius(rad)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius * radius;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rect;
  rect.width = radius * 2;
  rect.height = radius * 2;
  rect.pos = center;
  return rect;
}

void Circle::move(const point_t & center_)
{
  center = center_;
}

void Circle::move(const double dx, const double dy)
{
  center.x += dx;
  center.y += dy;
}