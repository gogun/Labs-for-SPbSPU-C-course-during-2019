#define _USE_MATH_DEFINES
#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

neupokoev::Triangle::Triangle(const point_t &cornerA, const point_t &cornerB, const point_t &cornerC) :
  a_(cornerA),
  b_(cornerB),
  c_(cornerC)
{
  if (getArea() <= 0)
  {
    throw std::invalid_argument("Invalid points");
  }
}

double neupokoev::Triangle::getArea() const
{
  return std::abs((a_.x - c_.x) * (b_.y - c_.y) - (b_.x - c_.x) * (a_.y - c_.y)) / 2;
}

neupokoev::rectangle_t neupokoev::Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(a_.x, b_.x), c_.x);
  double maxY = std::max(std::max(a_.y, b_.y), c_.y);
  double minX = std::min(std::max(a_.x, b_.x), c_.x);
  double minY = std::min(std::max(a_.y, b_.y), c_.y);
  return { {(minX + maxX) / 2, (minY + maxY) / 2}, maxX - minX, maxY - minY };
}

void neupokoev::Triangle::move(const point_t &pos)
{
  move(pos.x - (a_.x + b_.x + c_.x) / 3, pos.y - (a_.y + b_.y + c_.y) / 3);
}

void neupokoev::Triangle::move(const double dx, const double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void neupokoev::Triangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }
  else
  {
    point_t pos_ = { (a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3 };
    a_.x = (a_.x - pos_.x) * scaleFactor + pos_.x;
    a_.y = (a_.y - pos_.y) * scaleFactor + pos_.y;
    b_.x = (b_.x - pos_.x) * scaleFactor + pos_.x;
    b_.y = (b_.y - pos_.y) * scaleFactor + pos_.y;
    c_.x = (c_.x - pos_.x) * scaleFactor + pos_.x;
    c_.y = (c_.y - pos_.y) * scaleFactor + pos_.y;
  }
}

void neupokoev::Triangle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Triangle corners are {" << a_.x << ", " << a_.y << "}, {"
      << b_.x << ", " << b_.y << "}, { "
      << c_.x << ", " << c_.y << "}. \n"
      << "Triangle centre is (" << (a_.x + b_.x + c_.x) / 3 << ","
      << (a_.y + b_.y + c_.y) / 3 << ")\n"
      << "Frame rectangle width = " << rectangle.width
      << ", height = " << rectangle.height << "\n"
      << "Area = " << getArea() << "\n\n";
}
