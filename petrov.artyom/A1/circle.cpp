#include "circle.hpp"
#include <math.h>
#include <stdexcept>

Circle::Circle(point_t centre, double radius):
  centre_(centre),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is less or equal 0");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t {radius_ * 2, radius_ * 2, centre_};
}

void Circle::move(const point_t & centre)
{
  centre_ = centre;
}

void Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

point_t Circle::getCentre() const
{
  return centre_;
}

double Circle::getRadius() const
{
  return radius_;
}
