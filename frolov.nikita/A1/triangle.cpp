#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t &point0, const point_t &point1, const point_t &point2) :
  point0_(point0),
  point1_(point1),
  point2_(point2)
{
  rectangle_t frame = getFrameRect();
  assert((frame.height != 0) && (frame.width != 0));
  center_ = {(point0_.x + point1_.x + point2_.x) / 3, (point0_.y + point1_.y + point2_.y) / 3};
}

double findLengthVector(const point_t &point1, const point_t &point2)
{
  point_t vector = {(point2.x - point1.x), (point2.y - point1.y)};
  return sqrt(vector.x * vector.x + vector.y * vector.y);
}

double Triangle::getArea() const
{
  double lengthVector1 = findLengthVector(point0_, point1_);
  double lengthVector2 = findLengthVector(point0_, point2_);
  double lengthVector3 = findLengthVector(point1_, point2_);
  double perimeter = (lengthVector1 + lengthVector2 + lengthVector3) / 2;
  return sqrt(perimeter * (perimeter - lengthVector1) * (perimeter - lengthVector2) * (perimeter - lengthVector3));
}


rectangle_t Triangle::getFrameRect() const
{
  double width = std::max({point0_.x, point1_.x, point2_.x}) - std::min({point0_.x, point1_.x, point2_.x});
  double height = std::max({point0_.y, point1_.y, point2_.y}) - std::min({point0_.y, point1_.y, point2_.y});
  double minX = std::min({point0_.x, point1_.x, point2_.x});
  double minY = std::min({point0_.y, point1_.y, point2_.y});
  return {{minX + width / 2, minY + height / 2} , height, width};
}

void Triangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  point0_.x += dx;
  point0_.y += dy;
  point1_.x += dx;
  point1_.y += dy;
  point2_.x += dx;
  point2_.y += dy;
}

void Triangle::move(const point_t &center)
{
  move((center.x - center_.x), (center.y - center_.y));
}

void Triangle::showPoint() const
{
  std::cout << "the point on the x-axis= " << center_.x << "\n";
  std::cout << "the point on the y-axis= " << center_.y << "\n";
  std::cout << "the point of top 1= " << point0_.x << "\n";
  std::cout << "the point of top 1= " << point0_.y << "\n";
  std::cout << "the point of top 2= " << point1_.x << "\n";
  std::cout << "the point of top 2= " << point1_.y << "\n";
  std::cout << "the point of top 3= " << point2_.x << "\n";
  std::cout << "the point of top 3= " << point2_.y << "\n";
}
