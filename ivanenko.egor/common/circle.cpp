#include "circle.hpp"
#include <cmath>
#include <stdexcept>

ivanenko::Circle::Circle(const point_t &position, double radius) :
  pos_(position),
  radius_(radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Invalid radius");
  }
}

double ivanenko::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

ivanenko::rectangle_t ivanenko::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void ivanenko::Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void ivanenko::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void ivanenko::Circle::scale(const double scale)
{
  if (scale <= 0.0)
  {
    throw std::invalid_argument("Invalid scale");
  }
  radius_ *= scale;
}

