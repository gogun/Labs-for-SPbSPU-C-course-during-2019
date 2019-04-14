#include "triangle.hpp"

#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t& pos, double sideA, double sideB, double sideC) :
  centre_(pos),
  sideA_(sideA),
  sideB_(sideB),
  sideC_(sideC)
{
  assert((sideA_ > 0) && (sideB_ > 0) && (sideC_ > 0));
  assert(sideA_ < (sideB_ + sideC_));
  assert(sideB_ < (sideA_ + sideC_));
  assert(sideC_ < (sideA_ + sideB_));
}

Triangle::Triangle(double x, double y, double sideA, double sideB, double sideC) :
  Triangle({x, y}, sideA, sideB, sideC)
{
  assert((sideA_ > 0) && (sideB_ > 0) && (sideC_ > 0));
  assert(sideA_ < (sideB_ + sideC_));
  assert(sideB_ < (sideA_ + sideC_));
  assert(sideC_ < (sideA_ + sideB_));
}

double Triangle::getArea() const
{
  double p = (sideA_ + sideB_ + sideC_) / 2; //half the perimeter of the triangle
  return sqrt(p * (p - sideA_) * (p - sideB_) * (p - sideC_)); //Heron's formula
}

rectangle_t Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  return {sideA_, 2 * area / sideA_, centre_ }; //S = 1/2 * h * sideA_; --> S * 2 / sideA_ = h;
}

point_t Triangle::getPos() const
{
  return centre_;
}

void Triangle::move(const point_t& centre)
{
  centre_ = centre;
}

void Triangle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}
