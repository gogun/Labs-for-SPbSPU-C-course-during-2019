#include "triangle.hpp"
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t& pos, double side1, double side2, double side3) :
  centre_(pos),
  side1_(side1),
  side2_(side2),
  side3_(side3)
{
  assert((side1_ > 0.0) && (side2_ > 0.0) && (side3_ > 0.0));
  assert((side1_ + side2_) > side3_);
  assert((side2_ + side3_) > side1_);
  assert((side3_ + side1_) > side2_);
}

Triangle::Triangle(double x, double y, double side1, double side2, double side3) :
  centre_({x, y}),
  side1_(side1),
  side2_(side2),
  side3_(side3)
{
  assert((side1_ > 0.0) && (side2_ > 0.0) && (side3_ > 0.0));
  assert((side1_ + side2_) > side3_);
  assert((side2_ + side3_) > side1_);
  assert((side3_ + side1_) > side2_);
}

double Triangle::getArea() const
{
  double p = (side1_ + side2_ + side3_) / 2; // half_perimeter
  double s = sqrt(p * (p - side1_) * (p - side2_) * (p - side3_)); // Heron's formula
  return s;
}

rectangle_t Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  return {side1_, area * 2 / side1_, centre_};
}

void Triangle::move(const point_t& point)
{
  centre_ = point;
}

void Triangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

point_t Triangle::getPos() const
{
  return centre_;
}
