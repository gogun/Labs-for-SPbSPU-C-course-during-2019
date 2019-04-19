#include "triangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

frolov::Triangle::Triangle(const point_t &point0, const point_t &point1, const point_t &point2) :
  point0_(point0),
  point1_(point1),
  point2_(point2),
  center_({(point0_.x + point1_.x + point2_.x) / 3, (point0_.y + point1_.y + point2_.y) / 3})
{
  assert(getArea() > 0.0);
}

static double findDistance(const frolov::point_t &point1, const frolov::point_t &point2)
{
  const frolov::point_t vector = {(point2.x - point1.x), (point2.y - point1.y)};
  return sqrt(vector.x * vector.x + vector.y * vector.y);
}

double frolov::Triangle::getArea() const
{
  const double lengthVector1 = findDistance(point0_, point1_);
  const double lengthVector2 = findDistance(point0_, point2_);
  const double lengthVector3 = findDistance(point1_, point2_);
  const double halfPer = (lengthVector1 + lengthVector2 + lengthVector3) / 2;
  return sqrt(halfPer * (halfPer - lengthVector1) * (halfPer - lengthVector2) * (halfPer - lengthVector3));
}

frolov::rectangle_t frolov::Triangle::getFrameRect() const
{
  const double maxX = std::max({point0_.x, point1_.x, point2_.x});
  const double maxY = std::max({point0_.y, point1_.y, point2_.y});
  const double minX = std::min({point0_.x, point1_.x, point2_.x});
  const double minY = std::min({point0_.y, point1_.y, point2_.y});
  const double height = maxY - minY;
  const double width = maxX - minX;
  const point_t center = {minX + width / 2, minY + height / 2};
  return {center , height, width};
}

void frolov::Triangle::move(double dx, double dy)
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

void frolov::Triangle::move(const point_t &center)
{
  move((center.x - center_.x), (center.y - center_.y));
}

void frolov::Triangle::showPoint() const
{
  std::cout << "the point on the x-axis= " << center_.x << "\n";
  std::cout << "the point on the y-axis= " << center_.y << "\n";
}

void frolov::Triangle::scale(double factor)
{
  if (factor < 0)
  {
    throw std::invalid_argument("The Area can not be negative!");
  }
  point0_={factor * point0_.x - (factor - 1) * center_.x, factor * point0_.y - (factor - 1) * center_.y};
  point1_={factor * point1_.x - (factor - 1) * center_.x, factor * point1_.y - (factor - 1) * center_.y};
  point2_={factor * point2_.x - (factor - 1) * center_.x, factor * point2_.y - (factor - 1) * center_.y};
}
