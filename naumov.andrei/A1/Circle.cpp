#include "Circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

float Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.height = radius_;
  frameRect.width = radius_;
  frameRect.pos = centre_;
  return frameRect;
}

void Circle::move(const point_t & newCentre)
{
  centre_ = newCentre;
}

void Circle::move(float newX, float newY)
{
  centre_.x = newX;
  centre_.y = newY;
}

void Circle::setRadius(float newRadius)
{
  radius_ = newRadius;
}
