#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

ryabikin::Rectangle::Rectangle(double height, double width, const point_t &pos):
  m_height(height),
  m_width(width),
  m_pos(pos)
{
  if (height <= 0)
  {
    throw std::invalid_argument("Invalid heigt");
  }
  if (width <= 0)
  {
    throw std::invalid_argument("Invalid width");
  }
}

double ryabikin::Rectangle::getArea() const
{
  return (m_width * m_height);
}

ryabikin::rectangle_t ryabikin::Rectangle::getFrameRect() const
{
  return {m_width, m_height, m_pos};
}

void ryabikin::Rectangle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void ryabikin::Rectangle::move(const point_t &new_point)
{
  m_pos = new_point;
}

void ryabikin::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  m_height *= coefficient;
  m_width *= coefficient;
}
