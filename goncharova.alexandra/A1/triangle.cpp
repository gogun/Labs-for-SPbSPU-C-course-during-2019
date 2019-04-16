#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &center, const point_t &pointA, const point_t &pointB, const point_t &pointC):
  center_(center),
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),

  a_(sqrt(pow((pointA.x - pointB.x), 2) + pow((pointA.y - pointB.y), 2))),
  b_(sqrt(pow((pointB.x - pointC.x), 2) + pow((pointB.y - pointC.y), 2))),
  c_(sqrt(pow((pointC.x - pointA.x), 2) + pow((pointC.y - pointA.y), 2)))

{
  assert((a_ > 0.0) && (b_ > 0.0) && (c_ > 0.0) && (a_ + b_ > c_) && (a_ + c_ > b_) && (b_ + c_ > a_));
}

double Triangle::getArea() const
{
  double p = (a_ + b_ + c_) / 2;
  double square = sqrt(p * (p - a_) * (p - b_) * (p - c_));
  return square;
}

rectangle_t Triangle::getFrameRect()const
{
  double width = (std::max(pointA_.x, std::max(pointB_.x, pointC_.x)))
      - (std::min(pointA_.x, std::min(pointB_.x, pointC_.x)));
  double height=(std::max(pointA_.y, std::max(pointB_.y, pointC_.y)))
      - (std::min(pointA_.y, std::min(pointB_.y, pointC_.y)));

  point_t trCenter;
  trCenter.x = ((std::min(pointA_.x, std::min(pointB_.x, pointC_.x)) + width / 2));
  trCenter.y = (((std::min(pointA_.y, std::min(pointB_.y, pointC_.y)))) + height / 2);

  return{trCenter, width, height};
}

void Triangle::move(const double dx, const double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;

  center_.x += dx;
  center_.y += dy;
}

void Triangle::move(const point_t &newPoint)
{
  double dx = newPoint.x - center_.x;
  double dy = newPoint.y - center_.y;
  center_  = newPoint;

  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::inform() const
{
  std::cout << "X: " << center_.x;
  std::cout << "\n Y: " << center_.y;
}
