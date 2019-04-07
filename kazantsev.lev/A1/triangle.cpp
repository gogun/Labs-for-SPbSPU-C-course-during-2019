#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

Triangle::Triangle(const point_t &A, const point_t &B, const point_t &C) :
  Shape({ (A.x + B.x + C.x) / 3 , (A.y + B.y + C.y) / 3 }),
  pointA_(A),
  pointB_(B),
  pointC_(C)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Point of triange must be different!");
  }
}
double Triangle::getMin(const double &A, const double &B, const double &C)
{
  double min = A;
  if (B < min)
  {
    min = B;
  }
  if (C < min)
  {
    min = C;
  }
  return min;
}
double Triangle::getMax(const double &A, const double &B, const double &C)
{
  double max = A;
  if (B > max)
  {
    max = B;
  }
  if (C > max)
  {
    max = C;
  }
  return max;
}
double Triangle::getArea() const
{
  return ((std::abs(((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y)) - ((pointA_.y - pointC_.y) * (pointB_.x - pointC_.x))) / 2));
}
rectangle_t Triangle::getFrameRect() const
{
  double max_x = getMax(pointA_.x, pointB_.x, pointC_.x);
  double min_x = getMin(pointA_.x, pointB_.x, pointC_.x);
  double max_y = getMax(pointA_.y, pointB_.y, pointC_.y);
  double min_y = getMin(pointA_.y, pointB_.y, pointC_.y);
  return rectangle_t{ max_x - min_x, max_y - min_y, pos_ };
}
void Triangle::move(const point_t &to_position)
{
  pointA_.x += to_position.x - pos_.x;
  pointB_.x += to_position.x - pos_.x;
  pointC_.x += to_position.x - pos_.x;
  pointA_.y += to_position.y - pos_.y;
  pointB_.y += to_position.y - pos_.y;
  pointC_.y += to_position.y - pos_.y;
  pos_ = to_position;
}
void Triangle::move(const double &dx, const double &dy)
{
  pos_.x += dx;
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;
  pos_.y += dy;
  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}
void Triangle::printShapeInfo() const
{
  std::cout << "Triangle info" << "\n";
  std::cout << "Centre is in " << " X= " << pos_.x << " Y= " << pos_.y << "\n";
  std::cout << "A.x= " << pointA_.x << " A.y= " << pointA_.y << "\n";
  std::cout << "B.x= " << pointB_.x << " B.y= " << pointB_.y << "\n";
  std::cout << "C.x= " << pointC_.x << " C.y= " << pointC_.y << "\n";
}
