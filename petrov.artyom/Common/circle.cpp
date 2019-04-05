#include "circle.hpp"
#include <math.h>
#include <stdexcept>

petrov::Circle::Circle(point_t centre, double radius):
  centre_(centre),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is less or equal 0");
  }
}

double petrov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t petrov::Circle::getFrameRect() const
{
  return rectangle_t {radius_ * 2, radius_ * 2, centre_};
}

void petrov::Circle::move(const point_t & centre)
{
  centre_ = centre;
}

void petrov::Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

point_t petrov::Circle::getCentre() const
{
  return centre_;
}

double petrov::Circle::getRadius() const
{
  return radius_;
}
