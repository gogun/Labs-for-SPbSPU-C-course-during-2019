#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

golikov::Circle::Circle(double radius, const point_t & center):
  m_radius(radius),
  m_center(center)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Circle's radius should be positive");
  }
}

golikov::Circle::Circle(double radius, double center_x, double center_y):
  Circle(radius, {center_x, center_y})
{ }

double golikov::Circle::getArea() const
{
  return  M_PI * m_radius * m_radius;
}

golikov::rectangle_t golikov::Circle::getFrameRect() const
{
  return {m_center, m_radius * 2, m_radius * 2};
}

void golikov::Circle::move(const point_t & pos)
{
  m_center = pos;
}

void golikov::Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void golikov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wouldn't multiply on a negative coefficient");
  }
  else
  {
    m_radius *= coefficient;
  }
}

void golikov::Circle::showParams() const
{
  std::cout << "Circle: center - {" << m_center.x << ","
            << m_center.y << "}\n" << "Radius - " << m_radius
            << '\n' << "Area - " << getArea() << '\n';
}
