#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(const point_t &pos, double radius):
  m_pos(pos),
  m_radius(radius)
{
  if (m_radius <= 0)
  {
    std::cerr << "radius must be positive\n";
    assert(false);
  }
}

double Circle::getArea() const
{
  return M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_pos, 2 * m_radius, 2 * m_radius};
}

void Circle::move(const point_t &pos)
{
  m_pos = pos;
}

void Circle::move(double dispX, double dispY)
{
  m_pos.x += dispX;
  m_pos.y += dispY;
}
