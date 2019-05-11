#include "circle.hpp"
#include <stdexcept>
#include <cmath>

tagiev::Circle::Circle(const tagiev::point_t &center, const double &radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Radius <= 0");
  }
}

tagiev::rectangle_t tagiev::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

double tagiev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void tagiev::Circle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;
}

void tagiev::Circle::move(const tagiev::point_t &newPoint)
{
  center_ = newPoint;
}

void tagiev::Circle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("K <= 0");
  }
  radius_ *= k;
}
