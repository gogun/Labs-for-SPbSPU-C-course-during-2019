#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(double centerX, double centerY, double radius)
{
  if (radius <= 0)
  {
    std::cerr << "Circle: radius must be positive";
    exit(1);
  }
  m_center.x = centerX;
  m_center.y = centerY;
  m_radius = radius;
}

Circle::Circle(const point_t& center, double radius)
{
  if (radius <= 0)
  {
    std::cerr << "Circle: radius must be positive";
    exit(1);
  }
  m_center = center;
  m_radius = radius;
}

double Circle::getArea() const
{
  return M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_radius * 2, m_radius * 2, m_center};
}

point_t Circle::getCenter() const
{
  return m_center;
}

void Circle::move(const point_t& pos)
{
  m_center = pos;
}

void Circle::move(double dltX, double dltY)
{
  m_center.x += dltX;
  m_center.y += dltY;
}
