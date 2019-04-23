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
  return fabs(((p1_.x - p3_.x) * (p2_.y - p3_.y) - (p2_.x - p3_.x) * (p1_.y - p3_.y))) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  double left = fmin(p1_.x, fmin(p2_.x, p3_.x));
  double right = fmax(p1_.x, fmax(p2_.x, p3_.x));
  double top = fmin(p1_.y, fmin(p2_.y, p3_.y));
  double bottom = fmax(p1_.y, fmax(p2_.y, p3_.y));
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
