#include "triangle.hpp"

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>

Triangle::Triangle(const point_t & pointA, const point_t & pointB, const point_t & pointC):
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),
  center_({(pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3})
{
  double Area = getArea();
  assert(Area > 0.0);
}

double Triangle::getArea() const
{
  return std::abs(((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y) - (pointB_.x - pointC_.x) * (pointA_.y - pointC_.y)) / 2);
}

rectangle_t Triangle::getFrameRect() const
{
  double minX = std::min(std::min(pointA_.x, pointB_.x), pointC_.x);
  double maxX = std::max(std::max(pointA_.x, pointB_.x), pointC_.x);
  double minY = std::min(std::min(pointA_.y, pointB_.y), pointC_.y);
  double maxY = std::max(std::max(pointA_.y, pointB_.y), pointC_.y);
  return {maxX - minX, maxY - minY, {(minX + maxX) / 2, (minY + maxY) / 2}};
}

void Triangle::move(double dx, double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;
  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::move(const point_t & point)
{
  double dx = point.x - center_.x;
  double dy = point.y - center_.y;
  Triangle::move(dx, dy);
  center_ = point;
}


void Triangle::show() const
{
  std::cout << "Triangle's area: " << getArea() << std::endl;
  std::cout << "Rectangle's width: " << getFrameRect().width << std::endl;
  std::cout << "Rectangle's height: " << getFrameRect().height << std::endl;
  std::cout << "Triangle's center: (" << getFrameRect().pos.x
      << "; " << getFrameRect().pos.y << ")" << std::endl;
}
