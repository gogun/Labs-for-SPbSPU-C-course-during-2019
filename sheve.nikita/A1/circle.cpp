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
  rectangle_t localRect;
  localRect.m_pos.x = m_pos.x;
  localRect.m_pos.y = m_pos.y;
  localRect.width = 2 * m_radius;
  localRect.height = 2 * m_radius;
  return localRect;
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
