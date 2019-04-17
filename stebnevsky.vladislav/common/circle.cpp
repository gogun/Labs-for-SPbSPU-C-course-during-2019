#include "circle.hpp"
#include <cmath>
#include <stdexcept>

stebnevsky::Circle::Circle(const point_t & center, double radius):
  m_center(center),
  m_radius(radius)
{
  if (m_radius <= 0.0)
  {
    throw std::invalid_argument("Radius must be greater than zero");
  }
}

double stebnevsky::Circle::getArea() const
{
  return M_PI * m_radius * m_radius;
}

stebnevsky::rectangle_t stebnevsky::Circle::getFrameRect() const
{
  return {m_center, m_radius * 2, m_radius * 2};
}

void stebnevsky::Circle::move(const point_t & point)
{
  m_center = point;
}

void stebnevsky::Circle::move(double dx, double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void stebnevsky::Circle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient of scaling must be greater than zero");
  }
  m_radius *= coefficient;
}
