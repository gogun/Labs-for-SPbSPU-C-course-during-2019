#include "circle.hpp"
#include <cmath>

Circle::Circle(point_t center, double radius)
{
  this->center = center;
  this->radius = radius;
  this->area = static_cast<double>(M_PI * std::pow(radius, 2));
  this->frameRect = {2 * radius, 2 * radius, center};
}

double Circle::getArea() const
{
  return this->area;
}

rectangle_t Circle::getFrameRect() const
{
  return this->frameRect;
}

void Circle::move(double x, double y)
{
  this->center.x += x;
  this->center.y += y;
  this->frameRect.pos = this->center;
}

void Circle::moveTo(double x, double y)
{
  this->center = {x, y};
  this->frameRect.pos = this->center;
}
