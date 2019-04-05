#include "circle.hpp"
#include <math.h>
#include <cassert>

Circle::Circle(point_t pos, double radius):
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

void Circle::move(double x, double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void Circle::move(point_t point)
{
  m_pos = point;
}
