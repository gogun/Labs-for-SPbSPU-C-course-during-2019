#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double height, double width, const point_t &pos):
  m_height(height),
  m_width(width),
  m_pos(pos)
{
  assert(m_width > 0.0);
  assert(m_height > 0.0);
}

double Rectangle::getArea() const
{
  return (m_width * m_height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {m_width, m_height, m_pos};
}

void Rectangle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void Rectangle::move(const point_t &new_point)
{
  m_pos = new_point;
}
