#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>


Circle::Circle(const point_t &p, double r):
  pos (p),
  radius (r)
{
  if (radius <= 0)
  {
    std::cerr << "Invalid circle radius."<< std::endl;
    exit(1);
  }
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

void Circle::move (const double dx, const double dy)
{
  pos.x += dx;
  pos.y += dy;
}
