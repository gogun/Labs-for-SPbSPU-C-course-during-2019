#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(double radius, const point_t & center):
  m_radius(radius),
  m_center(center)
{
   assert(radius > 0.0);
}

Circle::Circle(double radius, double dx, double dy):
  Circle(radius, {dx, dy})
{ }

double Circle::getArea() const
{
  return  M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * m_radius, 2 * m_radius, m_center};
}

void Circle::move(const point_t & position)
{
  m_center = position;
}

void Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void Circle::showParameters() const
{
  std::cout << "Circle Parameters:\n"
  			<< "Center - {" << m_center.x << ", " << m_center.y << "}\n"
  			<< "Radius - " << m_radius << '\n'
  			<< "Area - " << getArea() << "\n\n";
}
