#define _USE_MATH_DEFINES
#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pos, const double sideA, const double sideB, const double sideC) :
  pos_(pos),
  sideA_(sideA),
  sideB_(sideB),
  sideC_(sideC)
{
  assert((sideA_ > 0) && (sideB_ > 0) && (sideC_ > 0));
  assert((sideA_ + sideB_) > sideC_);
  assert((sideA_ + sideC_) > sideB_);
  assert((sideB_ + sideC_) > sideA_);
}

double Triangle::getArea() const
{
  double p = (sideA_ + sideB_ + sideC_) / 2;
  return sqrt(p * (p - sideA_) * (p - sideB_) * (p - sideC_));
}

rectangle_t Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  return {pos_, sideA_, area * 2 / sideA_ };
}

void Triangle::move(const point_t &pos)
{
  pos_ = pos;
}

void Triangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Triangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Triangle side A is " << sideA_ << ","
      << " side B is " << sideB_ << ","
      << " side C is " << sideC_ << " \n"
      << "Triangle centre is (" << pos_.x << ","
      << pos_.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
