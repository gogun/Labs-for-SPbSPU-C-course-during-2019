#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

Circle::Circle(double radius, const point_t &pos):
  m_radius(radius),
  m_pos(pos)
{
  assert(m_radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * m_radius * m_radius);
}

rectangle_t Circle::getFrameRect() const
{
  return {m_radius * 2, m_radius * 2, { m_pos.x, m_pos.y }};
}

void Circle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void Circle::move(const point_t &new_point)
{
  m_pos = new_point;
}
