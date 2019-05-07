#include "triangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdexcept>

sheve::Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  center_({ (pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3 }),
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  if (getArea() == 0.0)
  {
    throw std::invalid_argument("Triangle's argument is invalid.");
  }
}

double sheve::Triangle::getArea() const
{
  return fabs((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y) - (pointB_.x - pointC_.x) * (pointA_.y - pointC_.y)) / 2;
}

sheve::rectangle_t sheve::Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(pointA_.x, pointB_.x), pointC_.x);
  const double maxY = std::max(std::max(pointA_.y, pointB_.y), pointC_.y);
  const double minX = std::min(std::min(pointA_.x, pointB_.x), pointC_.x);
  const double minY = std::min(std::min(pointA_.y, pointB_.y), pointC_.y);
  const double width = maxX - minX;
  const double height = maxY - minY;
  return { { minX + width / 2, minY + height / 2 }, width, height };
}

void sheve::Triangle::move(const point_t &p)
{
  const double dx = p.x - center_.x;
  const double dy = p.y - center_.y;
  move(dx, dy);
}

void sheve::Triangle::move(double dx, double dy)
{
  center_.x += dx;
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;
  center_.y += dy;
  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void sheve::Triangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Triangle's argument of scale is invalid.");
  }
  else
  {
    pointA_.x = (pointA_.x - center_.x) * coefficient + center_.x;
    pointA_.y = (pointA_.y - center_.y) * coefficient + center_.y;
    pointB_.x = (pointB_.x - center_.x) * coefficient + center_.x;
    pointB_.y = (pointB_.y - center_.y) * coefficient + center_.y;
    pointC_.x = (pointC_.x - center_.x) * coefficient + center_.x;
    pointC_.y = (pointC_.y - center_.y) * coefficient + center_.y;
  }
}

void sheve::Triangle::printInfo() const
{
  std::cout << "Center: " << center_.x << ", " << center_.y << std::endl;
  std::cout << "A: " << pointA_.x << ", " << pointA_.y << std::endl;
  std::cout << "B: " << pointB_.x << ", " << pointB_.y << std::endl;
  std::cout << "C: " << pointC_.x << ", " << pointC_.y << std::endl;
  std::cout << "Triangle area: " << getArea() << std::endl;
  std::cout << "Frame rectangle:" << std::endl;
  std::cout << "-Center: " << getFrameRect().pos.x << ", " << getFrameRect().pos.y << std::endl;
  std::cout << "-Width: " << getFrameRect().width << std::endl;
  std::cout << "-Height: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
