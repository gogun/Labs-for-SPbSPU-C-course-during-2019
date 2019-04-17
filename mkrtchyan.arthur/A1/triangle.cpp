#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  pos_({(point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3})
{
  const double a = sqrt((point1_.x - point2_.x) * (point1_.x - point2_.x) + (point1_.y - point2_.y) * (point1_.y - point2_.y));
  const double b = sqrt((point2_.x - point3_.x) * (point2_.x - point3_.x) + (point2_.y - point3_.y) * (point2_.y - point3_.y));
  const double c = sqrt((point3_.x - point1_.x) * (point3_.x - point1_.x) + (point3_.y - point1_.y) * (point3_.y - point1_.y));
  assert((a > 0) && (b > 0) && (c > 0) && ((a + b) > c) && ((c + b) > a) && ((a + c) > b));
}

double Triangle::getArea() const
{
  const double a = sqrt((point1_.x - point2_.x) * (point1_.x - point2_.x) + (point1_.y - point2_.y) * (point1_.y - point2_.y));
  const double b = sqrt((point2_.x - point3_.x) * (point2_.x - point3_.x) + (point2_.y - point3_.y) * (point2_.y - point3_.y));
  const double c = sqrt((point3_.x - point1_.x) * (point3_.x - point1_.x) + (point3_.y - point1_.y) * (point3_.y - point1_.y));
  const double p = 0.5 * (a + b + c);
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

rectangle_t Triangle::getFrameRect() const
{
  const double xMax = std::max({point1_.x, point2_.x, point3_.x});
  const double xMin = std::min({point1_.x, point2_.x, point3_.x});
  const double yMax = std::max({point1_.y, point2_.y, point3_.y});
  const double yMin = std::min({point1_.y, point2_.y, point3_.y});
  return {xMax - xMin, yMax - yMin, {xMax - (xMax - xMin) / 2, yMax - (yMax - yMin) / 2}};
}

void Triangle::move(point_t point)
{
  point1_.x -= (pos_.x - point.x);
  point1_.y -= (pos_.y - point.y);
  point2_.x -= (pos_.x - point.x);
  point2_.y -= (pos_.y - point.y);
  point3_.x -= (pos_.x - point.x);
  point3_.y -= (pos_.y - point.y);
  pos_ = point;
}

void Triangle::move(double dx, double dy)
{
  point1_.x += dx;
  point1_.y += dy;
  point2_.x += dx;
  point2_.y += dy;
  point3_.x += dx;
  point3_.y += dy;
  pos_.x += dx;
  pos_.y += dy;
}
