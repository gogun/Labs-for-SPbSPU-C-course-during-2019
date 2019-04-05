#include <iostream>
#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &pos, const double &width, const double &height):
  m_height(height),
  m_width(width),
  m_center(pos)
{
  assert((m_width > 0) && (m_height > 0));
}

double Rectangle::getArea() const
{
  return m_width * m_height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {m_height, m_width, m_center};
}

void Rectangle::move(const point_t & pos)
{
  m_center = pos;
}

void Rectangle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void Rectangle::showParameters() const
{
  std::cout << "Rectangle Parameters:\n"
  			<< "Center - {" << m_center.x << ", " << m_center.y << "}\n"
  			<< "Width - " << m_width << '\n'
  			<< "Height - " << m_height << '\n'
        << "Area - " << getArea() << "\n\n";
}
