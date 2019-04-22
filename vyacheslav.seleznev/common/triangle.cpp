#include "triangle.hpp"

#include <cmath>
#include <stdexcept>
#include <algorithm>

seleznev::Triangle::Triangle(point_t pA, point_t pB, point_t pC):
  Shape({(pA.x + pB.x + pC.x) / 3, (pA.y + pB.y + pC.y) / 3}),
  pointA_(pA),
  pointB_(pB),
  pointC_(pC)
{
  lengthA_ = getLength(pA, pB);
  lengthB_ = getLength(pB, pC);
  lengthC_ = getLength(pC, pA);

  if (getArea() == 0)
    throw std::out_of_range("Radius is out of range");
}

double seleznev::Triangle::getLength(point_t a, point_t b)
{
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double seleznev::Triangle::getArea() const
{
  double halfPer = (lengthA_ + lengthB_ + lengthC_) / 2;
  double area = sqrt(halfPer * (halfPer - lengthA_) * (halfPer - lengthB_) * (halfPer - lengthC_));

  return area;
}

seleznev::rectangle_t seleznev::Triangle::getFrameRect() const
{
  double minX = std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  double minY = std::min(pointA_.y, std::min(pointB_.y, pointC_.y));
  double maxX = std::max(pointA_.x, std::max(pointB_.x, pointC_.x));
  double maxY = std::max(pointA_.y, std::max(pointB_.y, pointC_.y));
  double w = maxX - minX;
  double h = maxY - minY;
  double cenX = (minX + maxX) / 2;
  double cenY = (minY + maxY) / 2;

  return {w, h, {cenX, cenY}};
}

void seleznev::Triangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::out_of_range("Wrong coefficient");
  }
  double x = (pointA_.x + pointB_.x + pointC_.x) / 3;
  double y = (pointA_.y + pointB_.y + pointC_.y) / 3;

  pointA_.x = coefficient * pointA_.x - (coefficient - 1) * x;
  pointA_.y = coefficient * pointA_.y - (coefficient - 1) * y;
  pointB_.x = coefficient * pointB_.x - (coefficient - 1) * x;
  pointB_.y = coefficient * pointB_.y - (coefficient - 1) * y;
  pointC_.x = coefficient * pointC_.x - (coefficient - 1) * x;
  pointC_.y = coefficient * pointC_.y - (coefficient - 1) * y;
}

double seleznev::Triangle::getLengthA()
{
  return lengthA_;
}

double seleznev::Triangle::getLengthB()
{
  return lengthB_;
}

double seleznev::Triangle::getLengthC()
{
  return lengthC_;
}
