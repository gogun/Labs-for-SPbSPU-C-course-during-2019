#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t &pos_a, const point_t &pos_b, const point_t &pos_c):
  corners_{pos_a, pos_b, pos_c}
{
  if (getArea() != 0.0)
  {
    throw std::invalid_argument("Area must be = 0.0")
  }
}

point_t Triangle::getCenter() const
{
  point_t center = {0, 0};

  for (size_t i = 0; i < 3; i++)
  {
    center.x += corners_[i].x / 3;
    center.y += corners_[i].y / 3;
  }

  return center;
}

double Triangle::getArea() const
{
  return 0.5 * fabs(((corners_[0].x - corners_[2].x) * (corners_[1].y - corners_[2].y)
      - (corners_[1].x - corners_[2].x) * (corners_[0].y - corners_[2].y)));
}

rectangle_t Triangle::getFrameRect() const
{
  point_t top_left = getCenter();
  point_t bottom_right = top_left;

  for (size_t i = 0; i < 3; i++)
  {
    if (corners_[i].x < top_left.x)
    {
      top_left.x = corners_[i].x;
    }

    if (corners_[i].y > top_left.y)
    {
      top_left.y = corners_[i].y;
    }

    if (corners_[i].x > bottom_right.x)
    {
      bottom_right.x = corners_[i].x;
    }

    if (corners_[i].y < bottom_right.y)
    {
      bottom_right.y = corners_[i].y;
    }
  }

  point_t center = {(top_left.x + bottom_right.x) / 2, (top_left.y + bottom_right.y) / 2};

  return {center, bottom_right.x - top_left.x, top_left.y - bottom_right.y};
}

void Triangle::move(const point_t &pos)
{
  point_t center = getCenter();
  move(pos.x - center.x, pos.y - center.y);
}

void Triangle::move(const double dx, const double dy)
{
  for (size_t i = 0; i < 3; i++)
  {
    corners_[i].x += dx;
    corners_[i].y += dy;
  }
}

void Triangle::printInformation() const
{
  center = getCenter();

  std::cout << "Position: (" << center.x << ", " << center.y << ")" << std::endl
      << "Area: " << getArea() << std::endl
      << "Frame Rectangle: " << getFrameRect().width << ", " << getFrameRect().height << std::endl;
}
