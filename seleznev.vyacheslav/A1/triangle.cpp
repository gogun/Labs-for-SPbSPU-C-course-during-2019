#include "triangle.hpp"

#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(const point_t& pA, const point_t& pB, const point_t& pC):
  centre_({(pA.x + pB.x + pC.x) / 3, (pA.y + pB.y + pC.y) / 3}),
  pointA_(pA),
  pointB_(pB),
  pointC_(pC)
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  return std::abs((pointC_.x - pointA_.x) * (pointC_.y - pointB_.y)
      - (pointC_.y - pointA_.y) * (pointC_.x - pointB_.x)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  double minX = std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  double minY = std::min(pointA_.y, std::min(pointB_.y, pointC_.y));
  double maxX = std::max(pointA_.x, std::max(pointB_.x, pointC_.x));
  double maxY = std::max(pointA_.y, std::max(pointB_.y, pointC_.y));

  return {maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2}};
}

void Triangle::move(const point_t& point)
{
  move(point.x - centre_.x, point.y - centre_.y);
}

void Triangle::move(const double dx, const double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;
  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
  centre_.x += dx;
  centre_.y += dy;
}
