#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

shahbazly::Rectangle::Rectangle(const point_t & pos, const double & width, const double & height):
  m_height(height),
  m_width(width),
  m_center(pos)
{
  if ((m_width <= 0.0) || (m_height <= 0.0))
  {
    throw std::invalid_argument("Width and height must be greater than zero.");
  }
}

double shahbazly::Rectangle::getArea() const
{
  return m_width * m_height;
}

shahbazly::rectangle_t shahbazly::Rectangle::getFrameRect() const
{
  return {m_height, m_width, m_center};
}

void shahbazly::Rectangle::move(const point_t & pos)
{
  m_center = pos;
}

void shahbazly::Rectangle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void shahbazly::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle's scale factor must be greater than zero.");
  }
  else
  {
    m_width *= scaleFactor;
    m_height *= scaleFactor;
  }
}

void shahbazly::Rectangle::showParameters() const
{
  std::cout << "Rectangle Parameters:\n"
      << "Center - {" << m_center.x << ", "<< m_center.y << "}\n"
      << "Width - " << m_width << '\n'
      << "Height - " << m_height << '\n'
      << "Area - " << getArea() << '\n'
      << "Size - " << m_width << "x" << m_height << "\n\n";
}
