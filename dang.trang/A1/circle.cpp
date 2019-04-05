#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

Circle::Circle(const point_t & pos, const double & radius):
  Shape(pos),
  m_radius(radius)
{}

double Circle::printArea() const
{
  return M_PI * m_radius * m_radius;
}

rectangle_t Circle::printFrameRect() const
{
  return {m_pos, 2 * m_radius, 2 * m_radius};
}

void Circle::printFeatures() const
{
  std::cout << "radius: " << m_radius << "\n";
}

void Circle::move(const double & dx, const double & dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}

void Circle::move(const point_t & pos)
{
  m_pos = pos;
}
