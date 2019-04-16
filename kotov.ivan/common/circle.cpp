#include "circle.hpp"
#include <cmath>
#include <stdexcept>

kotov::Circle::Circle(const kotov::point_t & center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Invalid radius of circle");
  }
}

const char * kotov::Circle::getShapeName() const
{
  return "circle";
}

double kotov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

kotov::rectangle_t kotov::Circle::getFrameRect() const
{
  return {
    center_,
    2 * radius_,
    2 * radius_
  };
}

void kotov::Circle::move(const kotov::point_t & newCenter)
{
  center_ = newCenter;
}

void kotov::Circle::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}

void kotov::Circle::scale(double scale)
{
  if (scale > 0)
  {
    radius_ *= scale;
  }
  else
  {
    throw std::invalid_argument("Invalid scale");
  }
}
