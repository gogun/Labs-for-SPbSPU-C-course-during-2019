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
  lengthA_ = sqrt(pow((pointA_.x - pointB_.x), 2) + pow((pointA_.y - pointB_.y), 2));
  lengthB_ = sqrt(pow((pointB_.x - pointC_.x), 2) + pow((pointB_.y - pointC_.y), 2));
  lengthC_ = sqrt(pow((pointC_.x - pointA_.x), 2) + pow((pointC_.y - pointA_.y), 2));

  assert(lengthA_ + lengthB_ > lengthC_);
  assert(lengthA_ + lengthC_ > lengthB_);
  assert(lengthB_ + lengthC_ > lengthA_);
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
  double w = maxX - minX;
  double h = maxY - minY;
  double cenX = (minX + maxX) / 2;
  double cenY = (minY + maxY) / 2;

  return {w, h, {cenX, cenY}};
}
