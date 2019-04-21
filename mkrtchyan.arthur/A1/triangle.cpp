#include "triangle.hpp"
#include <cassert>
#include <cmath>
#include <algorithm>

Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  pos_({(point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3}),
  a_(sqrt(std::pow(point1.x - point2.x, 2) + std::pow(point1.y - point2.y, 2))),
  b_(sqrt(std::pow(point2.x - point3.x, 2) + std::pow(point2.y - point3.y, 2))),
  c_(sqrt(std::pow(point3.x - point1.x, 2) + std::pow(point3.y - point1.y, 2)))
{
  assert((a_ > 0) && (b_ > 0) && (c_ > 0) && ((a_ + b_) > c_) && ((c_ + b_) > a_) && ((a_ + c_) > b_));
}

double Triangle::getArea() const
{
  const double p = 0.5 * (a_ + b_ + c_);
  return sqrt(p * (p - a_) * (p - b_) * (p - c_));
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
  const double xDiff = pos_.x - point.x;
  const double yDiff = pos_.y - point.y;
  point1_.x -= xDiff;
  point1_.y -= yDiff;
  point2_.x -= xDiff;
  point2_.y -= yDiff;
  point3_.x -= xDiff;
  point3_.y -= yDiff;
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
