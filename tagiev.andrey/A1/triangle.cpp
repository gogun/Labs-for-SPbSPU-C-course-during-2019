#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <cstdlib>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  assert((pointA_.x != pointB_.x) || (pointA_.x != pointC_.x));
  assert((pointA_.y != pointB_.y) || (pointA_.y != pointC_.y));
  assert((pointA_.x != pointB_.x) || (pointA_.y != pointB_.y));
  assert((pointA_.x != pointC_.x) || (pointA_.y != pointC_.y));
  assert((pointB_.x != pointC_.x) || (pointB_.y != pointC_.y));

  center_.x = (pointA_.x + pointB_.x + pointC_.x) / 3;
  center_.y = (pointA_.y + pointB_.y + pointC_.y) / 3;
}

rectangle_t Triangle::getFrameRect() const
{
  rectangle_t FrameRect{};
  FrameRect.width = std::fmax(std::fmax(pointA_.x, pointB_.x), pointC_.x)
      -std::fmin(std::fmin(pointA_.x, pointB_.x), pointC_.x);
  FrameRect.height = std::fmax(std::fmax(pointA_.y, pointB_.y), pointC_.y)
      -std::fmin(std::fmin(pointA_.y, pointB_.y), pointC_.y);
  FrameRect.pos = center_;

  return FrameRect;
}

double Triangle::getArea() const
{
  return (fabs((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2);
}

void Triangle::move(const point_t &newPoint)
{
  const double dx = center_.x - newPoint.x;
  const double dy = center_.y - newPoint.y;

  pointA_.x += dx;
  pointA_.y += dy;

  pointB_.x += dx;
  pointB_.y += dy;

  pointC_.x += dx;
  pointC_.y += dy;

  center_ = newPoint;
}

void Triangle::move(const double &dx, const double &dy)
{
  center_.x += dx;
  center_.y += dy;

  pointA_.x += dx;
  pointA_.y += dy;

  pointB_.x += dx;
  pointB_.y += dy;

  pointC_.x += dx;
  pointC_.y += dy;
}
