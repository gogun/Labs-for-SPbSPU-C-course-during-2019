#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(const point_t &point1, const point_t &point2, const point_t &point3):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  centre_(getCentre()),
  side1_(getSide(point1, point2)),
  side2_(getSide(point2, point3)),
  side3_(getSide(point1, point3))
{
  assert(((side1_ > 0) && (side2_ > 0) && (side3_ > 0))
      && (2 * std::max({side1_, side2_, side3_}) < (side1_ + side2_ + side3_)));
}

point_t Triangle::getCentre() const
{
  return {(point1_.x + point2_.x + point3_.x)/3, (point1_.y + point2_.y + point3_.y)/3};
}

double Triangle::getSide(const point_t &point1, const point_t &point2)
{
  return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}

double Triangle::getArea() const
{
  return std::fabs(0.5 * (point1_.x * (point2_.y - point3_.y)
      + point2_.x * (point3_.y - point1_.y) + point3_.x * (point1_.y - point2_.y)));
}

rectangle_t Triangle::getFrameRect() const
{
  double max_x = std::max({point1_.x, point2_.x, point3_.x});
  double max_y = std::max({point1_.y, point2_.y, point3_.y});
  double min_x = std::min({point1_.x, point2_.x, point3_.x});
  double min_y = std::min({point1_.y, point2_.y, point3_.y});
  point_t cenRect = {(max_x + min_x)/2, (max_y + min_y)/2};
  return {max_x - min_x, max_y - min_y, cenRect};
}

void Triangle::move(const point_t &point)
{
  double movement_x = point.x - centre_.x;
  double movement_y = point.y - centre_.y;
  move(movement_x, movement_y);
}

void Triangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
  point1_.x += dx;
  point1_.y += dy;
  point2_.x += dx;
  point2_.y += dy;
  point3_.x += dx;
  point3_.x += dx;
}

void Triangle::printTriang() const
{
  std::cout << "Sides: " << side1_ << ", " << side2_ << ", " << side3_ << std::endl;
  std::cout << "Centre of gravity:" << " (" << centre_.x << "," << centre_.y << ")" << std::endl;
}
