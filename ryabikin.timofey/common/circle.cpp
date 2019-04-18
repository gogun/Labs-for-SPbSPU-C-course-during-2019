#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>
#include <stdexcept>

ryabikin::Circle::Circle(double radius, const point_t &pos):
  m_radius(radius),
  m_pos(pos)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double ryabikin::Circle::getArea() const
{
  return (M_PI * m_radius * m_radius);
}

ryabikin::rectangle_t ryabikin::Circle::getFrameRect() const
{
  return {m_radius * 2, m_radius * 2, m_pos};
}

void ryabikin::Circle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void ryabikin::Circle::move(const point_t &new_point)
{
  m_pos = new_point;
}

void ryabikin::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  m_radius *= coefficient;
}
