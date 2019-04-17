#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t &point0, const point_t &point1, const point_t &point2) :
  point0_(point0),
  point1_(point1),
  point2_(point2)
{
  rectangle_t frame = getFrameRect();
  assert((frame.height != 0) && (frame.width != 0));
  center_ = {(point0_.x + point1_.x + point2_.x) / 3, (point0_.y + point1_.y + point2_.y) / 3};
}

double Triangle::getArea() const
{
  double lengthVector1 = sqrt((point0_.x - point1_.x) * (point0_.x - point1_.x) + (point0_.y - point1_.y)
      * (point0_.y - point1_.y));
  double lengthVector2 = sqrt((point1_.x - point2_.x) * (point1_.x - point2_.x) + (point1_.y - point2_.y)
      * (point1_.y - point2_.y));
  double lengthVector3 = sqrt((point0_.x - point2_.x) * (point0_.x - point2_.x) + (point0_.y - point2_.y)
      * (point0_.y - point2_.y));
  double perimeter = (lengthVector1 + lengthVector2 + lengthVector3) / 2;
  return sqrt(perimeter * (perimeter - lengthVector1) * (perimeter - lengthVector2) * (perimeter - lengthVector3));
}


rectangle_t Triangle::getFrameRect() const
{
  double width = std::max(std::max(point0_.x, point1_.x), point2_.x)
      - std::min(std::min(point0_.x, point1_.x), point2_.x);
  double height = std::max(std::max(point0_.x, point1_.x), point2_.x)
      - std::min(std::min(point0_.x, point1_.x), point2_.x);
  return {center_, height, width};
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
  point_t shift = {(center_.x - center.x), (center_.y - center.y)};
  center_ = center;
  point0_.x += shift.x;
  point0_.y += shift.y;
  point1_.x += shift.x;
  point1_.y += shift.y;
  point2_.x += shift.x;
  point2_.y += shift.y;
}

void Triangle::showPoint() const
{
  std::cout << "the point on the x-axis " << center_.x << "\n";
  std::cout << "the point on the y-axis " << center_.y << "\n";
  std::cout << "the point of top 1 " << point0_.x << "\n";
  std::cout << "the point of top 1 " << point0_.y << "\n";
  std::cout << "the point of top 2 " << point1_.x << "\n";
  std::cout << "the point of top 2 " << point1_.y << "\n";
  std::cout << "the point of top 3 " << point2_.x << "\n";
  std::cout << "the point of top 3 " << point2_.y << "\n";
}
