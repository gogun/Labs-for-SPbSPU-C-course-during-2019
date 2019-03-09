#include "circle.hpp"
#include <cmath>

Circle::Circle(point_t center, float radius)
{
  this->center = center;
  this->radius = radius;
  this->area = static_cast<float>(M_PI * std::pow(radius, 2));
  this->frameRect = {2 * radius, 2 * radius, center};
}

float Circle::getArea()
{
  return this->area;
}

reactangle_t Circle::getFrameRect()
{
  return this->frameRect;
}

void Circle::move(float x, float y)
{
  this->center.x += x;
  this->center.y += y;
  this->frameRect.pos = this->center;
}

void Circle::moveTo(float x, float y)
{
  this->center = {x, y};
  this->frameRect.pos = this->center;
}
