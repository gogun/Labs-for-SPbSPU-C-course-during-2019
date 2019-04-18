#define _USE_MATH_DEFINES
#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

neupokoev::Triangle::Triangle(const point_t &cornerA, const point_t &cornerB, const point_t &cornerC) :
  A(cornerA),
  B(cornerB),
  C(cornerC)
{
  pos_.x = (A.x + B.x + C.x) / 3;
  pos_.y = (A.y + B.y + C.y) / 3;

  getSides();

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
  double maxX = std::fmax(std::fmax(A.x, B.x), C.x);
  double maxY = std::fmax(std::fmax(A.y, B.y), C.y);
  double minX = std::fmin(std::fmax(A.x, B.x), C.x);
  double minY = std::fmin(std::fmax(A.y, B.y), C.y);
  return {{(minX + maxX) / 2, (minY + maxY) / 2}, maxX - minX, maxY - minY};
}

void neupokoev::Triangle::move(const point_t &pos)
{
  move(pos.x - pos_.x, pos.y - pos_.y);
}

void neupokoev::Triangle::move(const double dx, const double dy)
{
  A.x += dx;
  A.y += dy;
  B.x += dx;
  B.y += dy;
  C.x += dx;
  C.y += dy;
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
    A.x = (A.x - pos_.x) * scaleFactor + pos_.x;
    A.y = (A.y - pos_.y) * scaleFactor + pos_.y;
    B.x = (B.x - pos_.x) * scaleFactor + pos_.x;
    B.y = (B.y - pos_.y) * scaleFactor + pos_.y;
    C.x = (C.x - pos_.x) * scaleFactor + pos_.x;
    C.y = (C.y - pos_.y) * scaleFactor + pos_.y;
  }
  getSides();
}

void neupokoev::Triangle::getSides()
{
  sideA_ = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
  sideB_ = sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
  sideC_ = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
}

void neupokoev::Triangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Triangle corners are {" << A.x << ", " << A.y << "}, {"
      << B.x << ", " << B.y << "}, { "
      << C.x << ", " << C.y << "}. \n"
      << "Triangle side A is " << sideA_ << ","
      << " side B is " << sideB_ << ","
      << " side C is " << sideC_ << " \n"
      << "Triangle centre is (" << pos_.x << ","
      << pos_.y << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
