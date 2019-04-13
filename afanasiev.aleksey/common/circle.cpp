#include "circle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

afanasiev::Circle::Circle(const point_t &position, double radius):
  position_(position),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
}

double afanasiev::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

afanasiev::rectangle_t afanasiev::Circle::getFrameRect() const
{
  return {position_, radius_ * 2, radius_ * 2};
}

void afanasiev::Circle::move(const point_t &newPosition)
{
  position_ = newPosition;
}

void afanasiev::Circle::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
}

void afanasiev::Circle::scale(double zoomFactor)
{
  if (zoomFactor <= 0)
  {
    throw std::invalid_argument("Zoom factor must be positive");
  } else
  {
    radius_ *= zoomFactor;
  }
}
