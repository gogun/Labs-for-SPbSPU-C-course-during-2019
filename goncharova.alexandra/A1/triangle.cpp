#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),
  center_{(pointA_.x + pointB_.x + pointC_.x) / 3, (pointA_.y + pointB_.y + pointC_.y) / 3}
{
  assert(fabs((pointB_.x - pointA_.x) * (center_.y - pointA_.y) 
      - (center_.x - pointA_.x) * (pointB_.y - pointA_.y)) > pow(10, -8));
}

double Triangle::getArea() const
{
  double square = fabs((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y)
      - (pointB_.x - pointC_.x) * (pointA_.y - pointC_.y)) / 2;
  return square;
}

rectangle_t Triangle::getFrameRect() const
{
  point_t point1 = {std::min(pointA_.x, std::min(pointB_.x, pointC_.x)),
      std::min(pointA_.y, std::min(pointB_.y, pointC_.y))};
  point_t point2 = {std::max(pointA_.x, std::max(pointB_.x, pointC_.x)),
      std::max(pointA_.y, std::max(pointB_.y, pointC_.y))};
  
  double width = point2.x - point1.x;
  double height = point2.y - point1.y;
  
  point_t trCenter = {(point1.x + point2.x) / 2, (point1.y + point2.y) / 2};

  return {trCenter, width, height};
}

void Triangle::shift(const double dx, const double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::move(const double dx, const double dy)
{
  shift(dx, dy);

  center_.x += dx;
  center_.y += dy;
}

void Triangle::move(const point_t &newPoint)
{
  double dx = newPoint.x - center_.x;
  double dy = newPoint.y - center_.y;
  center_  = newPoint;

  shift(dx, dy);
}

void Triangle::inform() const
{
  std::cout << "X: " << round(center_.x * 100) / 100;
  std::cout << "\n Y: " << round(center_.y * 100) / 100;
}
