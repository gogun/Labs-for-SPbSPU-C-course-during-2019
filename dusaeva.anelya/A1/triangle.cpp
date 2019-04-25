#include "triangle.hpp"

#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  assert(getArea() > 0.0);
}

double Triangle::getArea() const
{
  double a = getSide(pointA_, pointB_);
  double b = getSide(pointB_, pointC_);
  double c = getSide(pointA_, pointC_);
  double p = (a + b + c) / 2;
  double square = sqrt(p * (p - a) * (p - b) * (p - c));

  return square;
}

rectangle_t Triangle::getFrameRect() const
{
  point_t minSide;
  minSide.x = std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  minSide.y = std::min(pointA_.y, std::min(pointB_.y, pointC_.y));

  point_t maxSide;
  maxSide.x = std::max(pointA_.x, std::max(pointB_.x, pointC_.x));
  maxSide.y = std::max(pointA_.y, std::max(pointB_.y, pointC_.y));

  double width = maxSide.x - minSide.x;
  double height = maxSide.y - minSide.y;

  point_t center;
  center.x = minSide.x + width / 2;
  center.y = minSide.y + height / 2;

  return rectangle_t{width, height, center};
}

void Triangle::move(double dx, double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::move(const point_t &param)
{
  rectangle_t frameRect(getFrameRect());
  point_t center = frameRect.pos;

  double dx = param.x - center.x;
  double dy = param.y - center.y;

  move(dx, dy);
}

void Triangle::printInfo() const
{
  rectangle_t info = getFrameRect();
  std::cout << "Area = " << getArea() << "\n";
  std::cout << "Central coordinates of frame: (" << info.pos.x << ", " << info.pos.y << ")\n";
  std::cout << "Frame width = " << info.width <<", frame height = " << info.height << "\n\n";
}

double Triangle::getSide(const point_t &point1, const point_t &point2) const
{
  double side = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));

  return side;
}
