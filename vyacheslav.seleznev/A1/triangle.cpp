#include "triangle.hpp"

#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(point_t pA, point_t pB, point_t pC):
  Shape({(pA.x + pB.x + pC.x) / 3, (pA.y + pB.y + pC.y) / 3}),
  pointA_(pA),
  pointB_(pB),
  pointC_(pC)
{
  lengthA_ = getLength(pA, pB);
  lengthB_ = getLength(pB, pC);
  lengthC_ = getLength(pC, pA);

  assert(getArea() > 0.0);
}

double Triangle::getLength(point_t a, point_t b)
{
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double Triangle::getArea() const
{
  double halfPer = (lengthA_ + lengthB_ + lengthC_) / 2;
  double area = sqrt(halfPer * (halfPer - lengthA_) * (halfPer - lengthB_) * (halfPer - lengthC_));

  return area;
}

rectangle_t Triangle::getFrameRect() const
{
  double minX = std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  double minY = std::min(pointA_.y, std::min(pointB_.y, pointC_.y));
  double maxX = std::max(pointA_.x, std::max(pointB_.x, pointC_.x));
  double maxY = std::max(pointA_.y, std::max(pointB_.y, pointC_.y));

  return {maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2}};
}
