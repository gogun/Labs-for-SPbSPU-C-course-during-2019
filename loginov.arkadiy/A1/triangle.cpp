#include "triangle.hpp"
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  p1_(p1),
  p2_(p2),
  p3_(p3),
  length12_(getLength(p1, p2)),
  length23_(getLength(p2, p3)),
  length13_(getLength(p1, p3))
{
  const double EPSILON = 1e-6;
  double maxLength = std::fmax(length12_, std::fmax(length23_, length13_));
  double sumOther = length12_ + length23_ + length13_ - maxLength;
  assert(sumOther - EPSILON > maxLength);
}

double Triangle::getArea() const
{
  double p = (length12_ + length23_ + length13_) / 2;
  return sqrt(p * (p - length12_) * (p - length23_) * (p - length13_));
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

double Triangle::getLength(const point_t &p1, const point_t &p2) const
{
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}
