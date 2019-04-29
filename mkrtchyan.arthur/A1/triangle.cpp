#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  point1_(point1),
  point2_(point2),
  point3_(point3)
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  return 0.5 * std::fabs((point2_.x - point1_.x) * (point3_.y - point1_.y) - (point3_.x - point1_.x) * (point2_.y - point1_.y));
}

rectangle_t Triangle::getFrameRect() const
{
  const double xMax = std::max({point1_.x, point2_.x, point3_.x});
  const double xMin = std::min({point1_.x, point2_.x, point3_.x});
  const double yMax = std::max({point1_.y, point2_.y, point3_.y});
  const double yMin = std::min({point1_.y, point2_.y, point3_.y});
  const double rectWidth = xMax - xMin;
  const double rectHeight = yMax - yMin;
  return {rectWidth, rectHeight, {xMax - rectWidth / 2, yMax - rectHeight / 2}};
}

void Triangle::move(point_t point)
{
  const point_t center = {(point1_.x + point2_.x + point3_.x) / 3, (point1_.y + point2_.y + point3_.y) / 3};
  const double xDiff = point.x - center.x;
  const double yDiff = point.y - center.y;
  move(xDiff, yDiff);
}

void Triangle::move(double dx, double dy)
{
  point1_.x += dx;
  point1_.y += dy;
  point2_.x += dx;
  point2_.y += dy;
  point3_.x += dx;
  point3_.y += dy;
}
