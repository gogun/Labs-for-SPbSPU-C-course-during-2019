#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdexcept>

sheve::Circle::Circle(const point_t &p, double r):
  m_pos(p),
  m_radius(r)
{
  if (m_radius <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive!");
  }
}

double sheve::Circle::getArea() const
{
  return (M_PI * m_radius * m_radius);
}

sheve::rectangle_t sheve::Circle::getFrameRect() const
{
  return { m_pos, m_radius * 2, m_radius * 2 };
}

void sheve::Circle::move(const point_t &p)
{
  m_pos = p;
}

void sheve::Circle::move(double dx, double dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}

void sheve::Circle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient should be positive!");
  }
  else
  {
    m_radius *= coefficient;
  }
}

void sheve::Circle::printInfo() const
{
  std::cout << "Center: " << m_pos.x << ", " << m_pos.y << std::endl;
  std::cout << "Radius: " << m_radius << std::endl;
  std::cout << "Circle area: " << getArea() << std::endl;
  std::cout << "Frame rectangle:" << std::endl;
  std::cout << "-Center: " << getFrameRect().pos.x << ", " << getFrameRect().pos.y << std::endl;
  std::cout << "-Width: " << getFrameRect().width << std::endl;
  std::cout << "-Height: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
