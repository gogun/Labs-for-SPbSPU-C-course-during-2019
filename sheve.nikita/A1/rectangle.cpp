#include "rectangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &p, double w, double h):
  m_pos(p),
  m_width(w),
  m_height(h)
{
  assert((m_width > 0.0) && (m_height > 0.0));
}

double Rectangle::getArea() const
{
  return (m_width * m_height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {m_width, m_height, m_pos};
}

void Rectangle::move(const point_t &p)
{
  m_pos = p;
}

void Rectangle::move(double dx, double dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}
