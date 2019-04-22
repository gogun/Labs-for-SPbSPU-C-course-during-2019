#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

sheve::Rectangle::Rectangle(const point_t &p, double w, double h):
  m_pos(p),
  m_width(w),
  m_height(h)
{
  if ((m_width <= 0.0) || (m_height <= 0.0))
  {
    throw std::invalid_argument("Rectangle parameters must be positive!");
  }
}

double sheve::Rectangle::getArea() const
{
  return (m_width * m_height);
}

sheve::rectangle_t sheve::Rectangle::getFrameRect() const
{
  return { m_pos, m_width, m_height };
}

void sheve::Rectangle::move(const point_t &p)
{
  m_pos = p;
}

void sheve::Rectangle::move(double dx, double dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
}

void sheve::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient should be positive!");
  }
  else
  {
    m_width *= coefficient;
    m_height *= coefficient;
  }
}

void sheve::Rectangle::printInfo() const
{
  std::cout << "Center: " << m_pos.x << ", " << m_pos.y << std::endl;
  std::cout << "Width: " << m_width << std::endl;
  std::cout << "Height: " << m_height << std::endl;
  std::cout << "Rectangle area: " << getArea() << std::endl;
  std::cout << "Frame rectangle:" << std::endl;
  std::cout << "-Center: " << getFrameRect().pos.x << ", " << getFrameRect().pos.y << std::endl;
  std::cout << "-Width: " << getFrameRect().width << std::endl;
  std::cout << "-Height: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
