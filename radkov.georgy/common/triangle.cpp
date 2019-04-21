#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace radkov;

Triangle::Triangle(const point_t &pos_a, const point_t &pos_b, const point_t &pos_c):
  points_{pos_a, pos_b, pos_c}
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("degenerate triangle");
  }
}

point_t Triangle::getCenter() const noexcept
{
  return {(points_[0].x + points_[1].x + points_[2].x) / 3,
      (points_[0].y + points_[1].y + points_[3].y) / 3};
}

double Triangle::getArea() const noexcept
{
  return fabs(((points_[0].x - points_[2].x) * (points_[1].y - points_[2].y)
      - (points_[1].x - points_[2].x) * (points_[0].y - points_[2].y))) / 2;
}

rectangle_t Triangle::getFrameRect() const noexcept
{ 
  point_t top_left = getCenter();
  point_t bottom_right = top_left;

  for (size_t i = 0; i < 3; ++i)
  {
    top_left.x = std::min(points_[i].x, top_left.x);
    top_left.y = std::max(points_[i].y, top_left.y);
    bottom_right.x = std::max(points_[i].x, bottom_right.x);
    bottom_right.y = std::min(points_[i].y, bottom_right.y);
  }

  return {{(top_left.x + bottom_right.x) / 2, (top_left.y + bottom_right.y) / 2},
      bottom_right.x - top_left.x, top_left.y - bottom_right.y};
}

void Triangle::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < 3; ++i)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void Triangle::move(const point_t &pos) noexcept
{
  point_t center = getCenter();
  move(pos.x - center.x, pos.y - center.y);
}

void Triangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid scaling factor");
  }

  point_t center = getCenter();
  
  for (size_t i = 0; i < 3; ++i)
  {
    points_[i] = {center.x + k * (points_[i].x - center.x), center.y + k * (points_[i].y - center.y)};
  }
}
