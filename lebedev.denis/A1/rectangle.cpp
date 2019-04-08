#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &pos, double width, double height) :
  m_width(pos),
  m_height(height),
  m_pos(width)
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
  return {m_width, m_height, {m_pos.x, m_pos.y}};
}

void Rectangle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void Rectangle::move(point_t point)
{
  m_pos = point;
}
