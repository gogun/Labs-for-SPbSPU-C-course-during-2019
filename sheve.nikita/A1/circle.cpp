#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

Circle::Circle(const point_t &p, double r):
  pos (p),
  radius (r)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius * radius;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t localRect;
  localRect.pos.x = Circle::pos.x;
  localRect.pos.y = Circle::pos.y;
  localRect.width = 2 * Circle::radius;
  localRect.height = 2 * Circle::radius;
  return localRect;
}

void Circle::move (const point_t &p)
{
  pos = p;
}

void Circle::move (double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
