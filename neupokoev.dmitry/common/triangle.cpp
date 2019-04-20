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
  if (getArea() <= 0)
  {
    throw std::invalid_argument("Invalid points");
  }
}

double neupokoev::Triangle::getArea() const
{
  return std::abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y)) / 2;
}

neupokoev::rectangle_t neupokoev::Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(A.x, B.x), C.x);
  double maxY = std::max(std::max(A.y, B.y), C.y);
  double minX = std::min(std::max(A.x, B.x), C.x);
  double minY = std::min(std::max(A.y, B.y), C.y);
  return { {(minX + maxX) / 2, (minY + maxY) / 2}, maxX - minX, maxY - minY };
}

void neupokoev::Triangle::move(const point_t &pos)
{
  move(pos.x - (A.x + B.x + C.x) / 3, pos.y - (A.y + B.y + C.y) / 3);
}

void neupokoev::Triangle::move(const double dx, const double dy)
{
  A.x += dx;
  A.y += dy;
  B.x += dx;
  B.y += dy;
  C.x += dx;
  C.y += dy;
}

void neupokoev::Triangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }
  else
  {
    point_t pos_ = { (A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3 };
    A.x = (A.x - pos_.x) * scaleFactor + pos_.x;
    A.y = (A.y - pos_.y) * scaleFactor + pos_.y;
    B.x = (B.x - pos_.x) * scaleFactor + pos_.x;
    B.y = (B.y - pos_.y) * scaleFactor + pos_.y;
    C.x = (C.x - pos_.x) * scaleFactor + pos_.x;
    C.y = (C.y - pos_.y) * scaleFactor + pos_.y;
  }
}

void neupokoev::Triangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Triangle corners are {" << A.x << ", " << A.y << "}, {"
      << B.x << ", " << B.y << "}, { "
      << C.x << ", " << C.y << "}. \n"
      << "Triangle centre is (" << (A.x + B.x + C.x) / 3 << ","
      << (A.y + B.y + C.y) / 3 << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
