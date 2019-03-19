#include "Circle.hpp"

#include <corecrt_math_defines.h>

const float Circle::getArea()
{
  return radius_ * radius_ * M_PI;
}

const rectangle_t Circle::getFrameRect()
{
  rectangle_t frameRect;
  frameRect.height = radius_;
  frameRect.width = radius_;
  frameRect.pos = centre_;
  return frameRect;
}

void Circle::move(point_t & newCentre)
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