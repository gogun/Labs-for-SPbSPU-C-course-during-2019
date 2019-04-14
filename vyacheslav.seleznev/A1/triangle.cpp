#include "triangle.hpp"

#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(point_t pA, point_t pB, point_t pC, point_t p):
  Shape(p),
  pointA_(pA),
  pointB_(pB),
  pointC_(pC)
{
  lenghtA_ = sqrt(pow((pointA_.x - pointB_.x), 2) + pow((pointA_.y - pointB_.y), 2));
  lenghtB_ = sqrt(pow((pointB_.x - pointC_.x), 2) + pow((pointB_.y - pointC_.y), 2));
  lenghtC_ = sqrt(pow((pointC_.x - pointA_.x), 2) + pow((pointC_.y - pointA_.y), 2));

  assert((lenghtA_ + lenghtB_ > lenghtC_) || (lenghtA_ + lenghtC_ > lenghtB_) || (lenghtB_ + lenghtC_ > lenghtA_));
}

double Triangle::getArea() const
{
  double halfPer = (lenghtA_ + lenghtB_ + lenghtC_) / 2;
  double area = sqrt(halfPer * (halfPer - lenghtA_) * (halfPer - lenghtB_) * (halfPer - lenghtC_));

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
