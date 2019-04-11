#include "base-types.hpp"
#include "Triangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cassert>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  pos ({(p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3}),
  a(p1),
  b(p2),
  c(p3)
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  double f = (b.x - a.x);
  double g = (c.y - a.y);
  double h = (c.x - a.x);
  double i = (b.y - a.y);
  double s = (f * g - h * i) / 2;
  return s;
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = 0;
  double maxY = 0;
  maxX = std::max(std::max(a.x, b.x),c.x);
  maxY = std::max(std::max(a.y, b.y),c.y);
  double minX = 0;
  double minY = 0;
  minX = std::min(std::min(a.x, b.x),c.x);
  minY = std::min(std::min(a.y, b.y),c.y);

  rectangle_t localRect;
  localRect.pos.x = pos.x;
  localRect.pos.y = pos.y;
  localRect.width  = maxX - minX;
  localRect.height = maxY - minY;
  return localRect;
}
void Triangle::move(const point_t &p)
{
  double dx = p.x - pos.x;
  double dy = p.y - pos.y;
  move(dx, dy);
}

void Triangle::move(const double dx, const double dy)
{
  pos.x += dx;
  a.x += dx;
  b.x += dx;
  c.x += dx;
  pos.y += dy;
  a.y += dy;
  b.y += dy;
  c.y += dy;
}
