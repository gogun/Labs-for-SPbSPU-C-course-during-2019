#include "triangle.hpp"
#include <iostream>

Triangle::Triangle(const point_t pointA, const point_t pointB, const point_t pointC)
{
  pointA_ = pointA;
  pointB_ = pointB;
  pointC_ = pointC;
}

double Triangle::getArea() const
{
  return abs(((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2);
}

rectangle_t Triangle::getFrameRect() const
{
  double height = getMax(pointA_.x, pointB_.x, pointC_.x) - getMin(pointA_.x, pointB_.x, pointC_.x);
  double widht = getMax(pointA_.y, pointB_.y, pointC_.y) - getMin(pointA_.y, pointB_.y, pointC_.y);
  return { widht, height, {height / 2, widht / 2} };
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

double Triangle::getMax(double const first, double const second, double const third) const
{
  double max = first;
  if (second > max)
  {
    max = second;
  }
  if (third > max)
  {
    max = third;
  }
  return max;
}

double Triangle::getMin(double const first, double const second, double const third) const
{
  double min = first;
  if (second < min)
  {
    min = second;
  }
  if (third < min)
  {
    min = third;
  }
  return min;
}
