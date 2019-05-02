#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t & center):
  m_radius(radius),
  m_center(center)
{
  assert(radius > 0);
}

Circle::Circle(double radius, double center_x, double center_y):
  Circle(radius, {center_x, center_y})
{ }

double Circle::getArea() const
{
  return  M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_center, m_radius * 2, m_radius * 2 };
}

void Circle::move(const point_t & pos)
{
  m_center = pos;
}

void Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void Circle::showParams() const
{
  std::cout << "Circle: center - {" << m_center.x << ","
            << m_center.y << "}\n" << "Radius - " << m_radius
            << '\n' << "Area - " << getArea() << '\n';
}
