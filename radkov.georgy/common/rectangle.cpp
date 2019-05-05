#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace radkov;

Rectangle::Rectangle(const point_t &pos, double width, double height) :
  points_{{pos.x - width / 2, pos.y + height / 2},
    {pos.x + width / 2, pos.y + height / 2},
    {pos.x + width / 2, pos.y - height / 2},
    {pos.x - width / 2, pos.y - height / 2}},
  width_(width),
  height_(height)
{
  if (width <= 0)
  {
    throw std::invalid_argument("invalid width");
  }

  if (height <= 0)
  {
    throw std::invalid_argument("invalid height");
  }
}

double Rectangle::getWidth() const noexcept
{
  return width_;
}

double Rectangle::getHeight() const noexcept
{
  return height_;
}

double Rectangle::getArea() const noexcept
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const noexcept
{ 
  point_t center = {(points_[0].x + points_[2].x) / 2, (points_[0].y + points_[2].y) / 2};

  point_t top_left = center;
  point_t bottom_right = center;

  for (size_t i = 0; i < 4; ++i)
  {
    top_left.x = std::min(points_[i].x, top_left.x);
    top_left.y = std::max(points_[i].y, top_left.y);
    bottom_right.x = std::max(points_[i].x, bottom_right.x);
    bottom_right.y = std::min(points_[i].y, bottom_right.y);
  }

  return {center, bottom_right.x - top_left.x, top_left.y - bottom_right.y};
}

void Rectangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 4; ++i)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void Rectangle::move(const point_t &pos) noexcept
{
  point_t center = getFrameRect().pos;
  move(pos.x - center.x, pos.y - center.y);
}

void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid scaling factor");
  }

  point_t center = getFrameRect().pos;
  
  for (size_t i = 0; i < 4; ++i)
  {
    points_[i] = {center.x + k * (points_[i].x - center.x), center.y + k * (points_[i].y - center.y)};
  }

  width_ *= k;
  height_ *= k;
}
