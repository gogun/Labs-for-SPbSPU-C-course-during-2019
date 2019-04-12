#define _USE_MATH_DEFINES
#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

neupokoev::Triangle::Triangle(const point_t &pos, const double sideA, const double sideB, const double sideC) :
  pos_(pos),
  sideA_(sideA),
  sideB_(sideB),
  sideC_(sideC)
{
  if ((sideA_ <= 0) || (sideB_ <= 0) || (sideC_ <= 0))
  {
    throw std::invalid_argument("Sides must be positive numbers");
  }

  if (((sideA_ + sideB_) <= sideC_) || ((sideA_ + sideC_) < sideB_) || ((sideB_ + sideC_) < sideA_))
  {
    throw std::invalid_argument("One side must be less then two others in summ");
  }
}

double neupokoev::Triangle::getArea() const
{
  double p = (sideA_ + sideB_ + sideC_) / 2;
  return sqrt(p * (p - sideA_) * (p - sideB_) * (p - sideC_));
}

neupokoev::rectangle_t neupokoev::Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  return {pos_, sideA_, area * 2 / sideA_ };
}

void neupokoev::Triangle::move(const point_t &pos)
{
  pos_ = pos;
}

void neupokoev::Triangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void neupokoev::Triangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }
  else
  {
    sideA_ *= scaleFactor;
    sideB_ *= scaleFactor;
    sideC_ *= scaleFactor;
  }
}

void neupokoev::Triangle::writeParameters() const
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
