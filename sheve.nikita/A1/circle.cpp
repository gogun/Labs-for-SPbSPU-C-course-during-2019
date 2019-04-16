#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

Circle::Circle(const point_t &p, double r):
  m_pos(p),
  m_radius(r)
{
  assert(m_radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_radius * 2, m_radius * 2, m_pos};
}

void Circle::move(const point_t &p)
{
  m_pos = p;
}

void Circle::move(double dx, double dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}
