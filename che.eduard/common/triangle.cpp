#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

che::Triangle::Triangle(const point_t& pointA, const point_t& pointB, const point_t& pointC) :
  centre_({(pointA.x + pointB.x + pointC.x) / 3, (pointA.y + pointB.y + pointC.y) / 3}),
  pointA_(pointA),
  pointB_(pointB),
  pointC_(pointC)
{
  if (std::abs((pointB.x - pointA.x) * (pointC.y - pointA.y)
      - (pointC.x - pointA.x) * (pointB.y - pointA.y)) < 0.0000001)
  {
	  throw std::invalid_argument("Points can't lie on the same line");
  }
}

double che::Triangle::getArea() const
{
  return std::abs((pointB_.x - pointA_.x) * (pointC_.y - pointA_.y) 
      - (pointC_.x - pointA_.x) * (pointB_.y - pointA_.y)) / 2;
}

che::rectangle_t che::Triangle::getFrameRect() const
{
  double max_x = fmax(fmax(pointA_.x, pointB_.x), pointC_.x);
  double min_x = fmin(fmin(pointA_.x, pointB_.x), pointC_.x);
  double max_y = fmax(fmax(pointA_.y, pointB_.y), pointC_.y);
  double min_y = fmin(fmin(pointA_.y, pointB_.y), pointC_.y);

  return {max_x - min_x, max_y - min_y, {(max_x + min_x) / 2, (max_y + min_y) / 2}};
}

void che::Triangle::move(const point_t& centre)
{
  move(centre.x - centre_.x, centre.y - centre_.y);
}

void che::Triangle::move(double deltaX, double deltaY)
{
  centre_ = {centre_.x + deltaX, centre_.y + deltaY};
  pointA_ = {pointA_.x + deltaX, pointA_.y + deltaY};
  pointB_ = {pointB_.x + deltaX, pointB_.y + deltaY};
  pointC_ = {pointC_.x + deltaX, pointC_.y + deltaY};
}

void che::Triangle::scale(double coef)
{
  if (coef <= 0)
  {
	  throw std::invalid_argument("Triangle scale coef can't be negativ");
  }
  pointA_ = {centre_.x + coef * (pointA_.x - centre_.x),
    centre_.y + coef * (pointA_.y - centre_.y)};
  pointB_ = {centre_.x + coef * (pointB_.x - centre_.x),
    centre_.y + coef * (pointB_.y - centre_.y)};
  pointC_ = {centre_.x + coef * (pointC_.x - centre_.x),
    centre_.y + coef * (pointC_.y - centre_.y)};
}

void che::Triangle::showInfo1() const
{
  std::cout << "Coordinates:" << "\n";
  std::cout << "A: (" << pointA_.x << "; " << pointA_.y << ")" << "\n";
  std::cout << "B: (" << pointB_.x << "; " << pointB_.y << ")" << "\n";
  std::cout << "C: (" << pointC_.x << "; " << pointC_.y << ")" << "\n";
  std::cout << "Area: " << getArea() << "\n";
  std::cout << "frame rect centre:" << getFrameRect().point.x << "; " << getFrameRect().point.y << "\n";
  std::cout << "frame rect width: " << getFrameRect().width << "\n";
  std::cout << "frame rect height: " << getFrameRect().height << "\n";
}
