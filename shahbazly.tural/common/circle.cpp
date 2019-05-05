#define _USE_MATH_DEFINES

#include "circle.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

shahbazly::Circle::Circle(double radius, const point_t & center):
  m_radius(radius),
  m_center(center)
{
  if (radius < 0.0)
  {
    throw std::invalid_argument("The radius must be greater than zero.");
  }
}

shahbazly::Circle::Circle(double radius, double dx, double dy):
  Circle(radius, {dx, dy})
{ }

double shahbazly::Circle::getArea() const
{
  return  M_PI * m_radius * m_radius;
}

shahbazly::rectangle_t shahbazly::Circle::getFrameRect() const
{
  return {2 * m_radius, 2 * m_radius, m_center};
}

void shahbazly::Circle::move(const point_t & position)
{
  m_center = position;
}

void shahbazly::Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void shahbazly::Circle::scale(double scaleFactor)
{
  if (scaleFactor < 0.0)
  {
    throw std::invalid_argument("Circle's scale factor must be greater than zero.");
  }
  else
  {
    m_radius *= scaleFactor;
  }
}

void shahbazly::Circle::showParameters() const
{
  std::cout << "Circle Parameters:\n"
      << "Center - {" << m_center.x << ", " << m_center.y << "}\n"
      << "Radius - " << m_radius << '\n'
      << "Area - " << getArea() << "\n\n";
}
