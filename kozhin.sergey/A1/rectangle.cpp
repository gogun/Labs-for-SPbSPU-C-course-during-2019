#include "rectangle.hpp"

Rectangle::Rectangle(point_t center, float width, float height)
{
  this->center = center;
  this->width = width;
  this->height = height;
  this->area = width * height;
  this->frameRect = {width, height, center};
}

float Rectangle::getArea()
{
  return this->area;
}

reactangle_t Rectangle::getFrameRect()
{
  return this->frameRect;
}

void Rectangle::move(float x, float y)
{
  this->center.x += x;
  this->center.y += y;
  this->frameRect.pos = this->center;
}

void Rectangle::moveTo(float x, float y)
{
  this->center = {x, y};
  this->frameRect.pos = this->center;
}
