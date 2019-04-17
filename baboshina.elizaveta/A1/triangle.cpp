#include "triangle.hpp"
#include <iostream>
#include <algorithm>

Triangle::Triangle(const point_t pointA, const point_t pointB, const point_t pointC):
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
}

double Triangle::getArea() const
{
  return abs(((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2);
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(pointA_.x, pointB_.x), pointC_.x);
  double minX = std::min(std::min(pointA_.x, pointB_.x), pointC_.x);
  double maxY = std::max(std::max(pointA_.y, pointB_.y), pointC_.y);
  double minY = std::min(std::min(pointA_.y, pointB_.y), pointC_.y);
  return { maxX - minX, maxY - minY, {minX + maxX / 2, minY + maxY / 2} };
}

void Triangle::move(const point_t point)
{
  point_t center = { (pointA_.x + pointB_.x + pointC_.x) / 3, (pointA_.y + pointB_.y + pointC_.y) / 3 };
  point_t delta = { point.x - center.x, point.y - center.y };
  pointA_.x += delta.x;
  pointB_.x += delta.x;
  pointC_.x += delta.x;
  pointA_.y += delta.y;
  pointB_.y += delta.y;
  pointC_.y += delta.y;
}

void Triangle::move(const double x, const double y)
{
  pointA_.x += x;
  pointB_.x += x;
  pointC_.x += x;
  pointA_.x += y;
  pointB_.y += y;
  pointC_.y += y;
}

void Triangle::getInfo() const
{
  std::cout << "\nPoint A is: x=" << pointA_.x << " y=" << pointA_.y << std::endl;
  std::cout << "Point B is: x=" << pointB_.x << " y=" << pointB_.y << std::endl;
  std::cout << "Point C is: x=" << pointC_.x << " y=" << pointC_.y << std::endl;
}
