#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>
#include <stdexcept>

lebedev::Circle::Circle(double radius, const point_t &pos):
  m_radius(radius),
  m_pos(pos)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Invalid radius, radius must be more then 0");
  }
}

double lebedev::Circle::getArea() const
{
  return (M_PI * m_radius * m_radius);
}

lebedev::rectangle_t lebedev::Circle::getFrameRect() const
{
  return {m_radius * 2, m_radius * 2, m_pos};
}

void lebedev::Circle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void lebedev::Circle::move(const point_t &new_point)
{
  m_pos = new_point;
}

void lebedev::Circle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid multiplier, multiplier must be more then 0");
  }
  m_radius *= multiplier;
}
