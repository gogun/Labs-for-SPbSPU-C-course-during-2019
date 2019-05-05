#include "circle.hpp"

#include <stdexcept>
#include <math.h>

tolstikov::Circle::Circle(point_t centre, double radius):
  centre_(centre),
  radius_(radius)
{
  if (radius <= 0) {
    throw std::invalid_argument("Radius must be a positive number!\n");
  }
}

double tolstikov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

double tolstikov::Circle::getRadius() const
{
  return radius_;
}

tolstikov::rectangle_t tolstikov::Circle::getFrameRect() const
{
  return { centre_, 2 * radius_, 2 * radius_ };
}

void tolstikov::Circle::scale(double scaleFactor)
{
  if (scaleFactor <= 0) {
    throw std::invalid_argument("Factor of sacle must be a positive number!\n");
  }

  radius_ *= scaleFactor;
}

void tolstikov::Circle::move(point_t point)
{
  centre_ = point;
}

void tolstikov::Circle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
