#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(float centerX, float centerY, float radius)
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

Circle::Circle(const point_t& center, float radius)
{
  if (radius <= 0)
  {
    std::cerr << "Circle: radius must be positive";
    exit(1);
  }
  m_center = center;
  m_radius = radius;
}

float Circle::getArea() const
{
  return ((float) M_PI) * m_radius * m_radius;
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

void Circle::move(float dltX, float dltY)
{
  m_center.x += dltX;
  m_center.y += dltY;
}
