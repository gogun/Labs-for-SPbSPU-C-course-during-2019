#include "rectangle.hpp"

double Rectangle::getArea() const
{
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

void Rectangle::move(const float dltX, const float dltY)
{
  m_figure.pos.x += dltX;
  m_figure.pos.y += dltY;
};
