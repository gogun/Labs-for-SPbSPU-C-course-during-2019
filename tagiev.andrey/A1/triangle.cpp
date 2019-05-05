#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <cstdlib>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),
  center_({(pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3})
{
  assert((pointA_.x != pointB_.x) || (pointA_.x != pointC_.x));
  assert((pointA_.y != pointB_.y) || (pointA_.y != pointC_.y));
  assert((pointA_.x != pointB_.x) || (pointA_.y != pointB_.y));
  assert((pointA_.x != pointC_.x) || (pointA_.y != pointC_.y));
  assert((pointB_.x != pointC_.x) || (pointB_.y != pointC_.y));
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::fmax(std::fmax(pointA_.x, pointB_.x), pointC_.x);
  const double minX = std::fmin(std::fmin(pointA_.x, pointB_.x), pointC_.x);
  const double maxY = std::fmax(std::fmax(pointA_.y, pointB_.y), pointC_.y);
  const double minY = std::fmin(std::fmin(pointA_.y, pointB_.y), pointC_.y);
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

double Triangle::getArea() const
{
  return (fabs((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2);
}

void Triangle::move(const point_t &newPoint)
{
  const double dx = newPoint.x - center_.x;
  const double dy = newPoint.y - center_.y;

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
