#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(point_t pos, double width, double height) :
  m_width(width),
  m_height(height),
  m_pos(pos)
{
  assert(m_width > 0.0);
  assert(m_height > 0.0);
}

double Rectangle::getArea() const
{
  return  (m_width*m_height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { m_width, m_height, {m_pos.x, m_pos.y} };
}

void Rectangle::move(double x, double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void Rectangle::move(point_t point)
{
  m_pos = point;
}
