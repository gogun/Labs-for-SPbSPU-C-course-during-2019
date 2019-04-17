#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(const point_t &point1, const point_t &point2, const point_t &point3):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  centre_(getCentre())
{
  side1_ = sqrt((point1_.x - point2_.x)*(point1_.x - point2_.x) + (point1_.y - point2_.y)*(point1_.y - point2_.y));
  side2_ = sqrt((point2_.x - point3_.x)*(point2_.x - point3_.x) + (point2_.y - point3_.y)*(point2_.y - point3_.y));
  side3_ = sqrt((point1_.x - point3_.x)*(point1_.x - point3_.x) + (point1_.y - point3_.y)*(point1_.y - point3_.y));
  assert(((side1_ > 0) && (side2_ > 0) && (side3_ > 0)) && (2 * std::max({side1_, side2_, side3_}) < (side1_ + side2_ + side3_)));
}

point_t Triangle::getCentre() const
{
  point_t point;
  point.x = (point1_.x + point2_.x + point3_.x)/3;
  point.y = (point1_.y + point2_.y + point3_.y)/3;
  return (point);
}

double Triangle::getArea() const
{
  return abs(0.5*(point1_.x * (point2_.y - point3_.y) + point2_.x * (point3_.y - point1_.y) + point3_.x * (point1_.y - point2_.y)));
}

rectangle_t Triangle::getFrameRect() const
{
  double max_x = std::max({point1_.x, point2_.x, point3_.x});
  double max_y = std::max({point1_.y, point2_.y, point3_.y});
  double min_x = std::min({point1_.x, point2_.x, point3_.x});
  double min_y = std::min({point1_.y, point2_.y, point3_.y});
  point_t cenRect;
  cenRect.x = (max_x + min_x)/2;
  cenRect.y = (max_y + min_y)/2;
  return {max_x - min_x, max_y - min_y, cenRect};
}

void Triangle::move(const point_t &point)
{
  centre_ = point;
}

void Triangle::move(double abs, double ord)
{
  centre_.x += abs;
  centre_.y += ord;
}

void Triangle::printTriang() const
{
  std::cout << "Sides: " << side1_ << ", " << side2_ << ", " << side3_ << std::endl;
  std::cout << "Centre of gravity:" << " (" << centre_.x << "," << centre_.y << ")" << std::endl;
}
