#include "triangle.hpp"
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  double length12 = std::sqrt((p1_.x - p2_.x)*(p1_.x - p2_.x) + (p1_.y - p2_.y)*(p1_.y - p2_.y));
  double length13 = std::sqrt((p1_.x - p3_.x)*(p1_.x - p3_.x) + (p1_.y - p3_.y)*(p1_.y - p3_.y));
  double length23 = std::sqrt((p3_.x - p2_.x)*(p3_.x - p2_.x) + (p3_.y - p2_.y)*(p3_.y - p2_.y));
  double p = (length12 + length23 + length13) / 2;
  return sqrt(p * (p - length12) * (p - length23) * (p - length13));
}

rectangle_t Triangle::getFrameRect() const
{
  double left = std::fmin(p1_.x, std::fmin(p2_.x, p3_.x));
  double right = std::fmax(p1_.x, std::fmax(p2_.x, p3_.x));
  double top = std::fmin(p1_.y, std::fmin(p2_.y, p3_.y));
  double bottom = std::fmax(p1_.y, std::fmax(p2_.y, p3_.y));
  double width = right - left;
  double height = bottom - top;
  double x0 = (left + right) / 2;
  double y0 = (top + bottom) / 2;
  return { width, height, { x0, y0 }};
}

void Triangle::move(double dx, double dy)
{
  p1_.x += dx;
  p2_.x += dx;
  p3_.x += dx;
  p1_.y += dy;
  p2_.y += dy;
  p3_.y += dy;
}

void Triangle::move(const point_t &point)
{
  point_t preCentre = getCentre();
  move(point.x - preCentre.x, point.y - preCentre.y);
}

point_t Triangle::getCentre() const
{
  return { (p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3 };
}
