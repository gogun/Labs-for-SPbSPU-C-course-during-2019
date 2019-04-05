#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t & pos, const double & width, const double & height):
  Shape(pos),
  m_width(width),
  m_height(height)
{}

double Rectangle::printArea() const
{
  return m_width * m_height;
}

rectangle_t Rectangle::printFrameRect() const
{
  return {m_pos, m_width, m_height};
}

void Rectangle::printFeatures() const
{
  std::cout << "width: " << m_width << "\n"
    << "height: " << m_height << "\n";
}

void Rectangle::move(const double & dx, const double & dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}

void Rectangle::move(const point_t & pos)
{
  m_pos = pos;
}
