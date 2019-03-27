#include "rectangle.hpp"
#include <cassert>

double Rectangle::getArea() const
{
  assert( (m_figure.width > 0) || (m_figure.height > 0) );
  return m_figure.width * m_figure.height;
};

rectangle_t Rectangle::getFrameRect() const
{
  return m_figure;
};

void Rectangle::move(const point_t &pos)
{
  m_figure.pos = pos;
};

void Rectangle::move(double dx, double dy)
{
  m_figure.pos.x += dx;
  m_figure.pos.y += dy;
};
