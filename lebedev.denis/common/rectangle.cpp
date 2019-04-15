#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>


lebedev::Rectangle::Rectangle(double height, double width, const point_t &pos):
  m_height(height),
  m_width(width),
  m_pos(pos)
{
  if (height <= 0)
  {
    throw std::invalid_argument("Invalid heigt, height must be more then 0");
  }
  if (width <= 0)
  {
    throw std::invalid_argument("Invalid width, width must be more then 0");
  }
}

double lebedev::Rectangle::getArea() const
{
  return (m_width * m_height);
}

lebedev::rectangle_t lebedev::Rectangle::getFrameRect() const
{
  return {m_width, m_height, m_pos};
}

void lebedev::Rectangle::move(const double x, const double y)
{
  m_pos.x += x;
  m_pos.y += y;
}

void lebedev::Rectangle::move(const point_t &new_point)
{
  m_pos = new_point;
}

void lebedev::Rectangle::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::invalid_argument("Invalid multiplier, multiplier must be more then 0");
  }
  m_height *= multiplier;
  m_width *= multiplier;
}
