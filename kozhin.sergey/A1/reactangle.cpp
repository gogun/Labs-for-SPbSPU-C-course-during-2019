#include "reactangle.hpp"

Reactangle::Reactangle(point_t center, float width, float height)
{
  this->center = center;
  this->width = width;
  this->height = height;
  this->area = width * height;
  this->frameRect = {width, height, center};
}

float Reactangle::getArea()
{
  return this->area;
}

reactangle_t Reactangle::getFrameRect()
{
  return this->frameRect;
}

void Reactangle::move(float x, float y)
{
  this->center.x += x;
  this->center.y += y;
  this->frameRect.pos = this->center;
}

void Reactangle::moveTo(float x, float y)
{
  this->center = {x, y};
  this->frameRect.pos = this->center;
}
