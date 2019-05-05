#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t &pos_a, const point_t &pos_b, const point_t &pos_c):
  points_{pos_a, pos_b, pos_c}
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Area mustn't be = 0");
  }
}

point_t Triangle::getPosition() const
{
  return {(points_[0].x + points_[1].x + points_[2].x) / 3,
      (points_[0].y + points_[1].y + points_[2].y) / 3};
}

double Triangle::getArea() const
{
  return fabs(((points_[0].x - points_[2].x) * (points_[1].y - points_[2].y)
      - (points_[1].x - points_[2].x) * (points_[0].y - points_[2].y))) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  point_t top_left = getPosition();
  point_t bottom_right = top_left;

  for (size_t i = 0; i < 3; ++i)
  {
    top_left.x = std::min(points_[i].x, top_left.x);
    top_left.y = std::max(points_[i].y, top_left.y);
    bottom_right.x = std::max(points_[i].x, bottom_right.x);
    bottom_right.y = std::min(points_[i].y, bottom_right.y);
  }

  point_t center = {(top_left.x + bottom_right.x) / 2, (top_left.y + bottom_right.y) / 2};

  return {center, bottom_right.x - top_left.x, top_left.y - bottom_right.y};
}

void Triangle::move(const point_t &pos)
{
  point_t center = getPosition();
  move(pos.x - center.x, pos.y - center.y);
}

void Triangle::move(const double dx, const double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}
