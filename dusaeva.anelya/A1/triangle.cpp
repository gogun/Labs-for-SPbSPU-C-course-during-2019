#include "triangle.hpp"

#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pointA, const point_t &pointB, const point_t &pointC) :
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC),

  a_(getSide(pointA, pointB)),
  b_(getSide(pointB, pointC)),
  c_(getSide(pointA, pointC))
{
  assert((a_ > 0.0) && (b_ > 0.0) && (c_ > 0.0) && (a_ + b_ > c_) && (a_ + c_ > b_) && (b_ + c_ > a_));
  rectangle_t frameParameters = getFrameRect();
  center_ = frameParameters.pos;
}

double Triangle::getArea() const
{
  double p = (a_ + b_ + c_) / 2;
  double square = sqrt(p * (p - a_) * (p - b_) * (p - c_));
  return square;
}

rectangle_t Triangle::getFrameRect()const
{
  point_t center;

  double width = std::max(pointA_.x, std::max(pointB_.x, pointC_.x)) - std::min(pointA_.x, std::min(pointB_.x, pointC_.x));
  double height = std::max(pointA_.y, std::max(pointB_.y, pointC_.y))- std::min(pointA_.y, std::min(pointB_.y, pointC_.y));

  center.x = std::min(pointA_.x, std::min(pointB_.x, pointC_.x)) + width / 2;
  center.y = std::min(pointA_.y, std::min(pointB_.y, pointC_.y)) + height / 2;

  return {width, height, center};
}

void Triangle::move(double dx, double dy)
{
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;

  center_.x += dx;
  center_.y += dy;
}

void Triangle::move(const point_t &param)
{
  double dx = param.x - center_.x;
  double dy = param.y - center_.y;
  center_  = param;

  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;

  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::printInfo() const
{
  rectangle_t info = getFrameRect();
  std::cout << "a = " << a_ << ", b = " << b_  << ", c = " << c_ << "\n";
  std::cout << "Area = " << getArea() << "\n";
  std::cout << "Central coordinates of frame: (" << info.pos.x << ", " << info.pos.y << ")\n";
  std::cout << "Frame width = " << info.width <<", frame height = " << info.height << "\n\n";
}

double Triangle::getSide(const point_t &point1, const point_t &point2)
{
  double side = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));

  return side;
}
