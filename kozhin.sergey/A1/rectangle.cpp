#include "rectangle.hpp"

Rectangle::Rectangle(point_t center, double width, double height)
{
  this->center = center;
  this->width = width;
  this->height = height;
  this->area = width * height;
  this->frameRect = {width, height, center};
}

double Rectangle::getArea()
{
  return this->area;
}

rectangle_t Rectangle::getFrameRect()
{
  return this->frameRect;
}

void Rectangle::move(double x, double y)
{
  this->center.x += x;
  this->center.y += y;
  this->frameRect.pos = this->center;
}

void Rectangle::moveTo(double x, double y)
{
  this->center = {x, y};
  this->frameRect.pos = this->center;
}
