#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(const point_t & center, double radius) :
  m_center_(center),
  m_radius_(radius)
{
  if (m_radius_ <= 0)
  {
    std::cerr << "radius must be positive\n";
    assert(false);
  }
}

double Circle::getArea() const
{
  return M_PI * m_radius_ * m_radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_center_, 2 * m_radius_, 2 * m_radius_};
}

void Circle::move(const point_t & newCenter)
{
  m_center_ = newCenter;
}

void Circle::move(double dX, double dY)
{
  m_center_.x += dX;
  m_center_.y += dY;
}
