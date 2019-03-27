#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

double Circle::getArea() const
{
  assert(m_radius > 0); // point is not a case of a null circle
  return  M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_center, m_radius * 2, m_radius * 2};
}

void Circle::move(const point_t &pos)
{
  m_center = pos;
}

void Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}
