#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t locO, double radius):
  centre_(locO),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

Circle::Circle(double x, double y, double radius):
  Circle(point_t{x, y}, radius)
{
}

double Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  return {centre_, radius_ * 2, radius_ * 2};
}

void Circle::move(const point_t newCentre)
{
  centre_ = newCentre;
}

void Circle::move(double newX, double newY)
{
  centre_.x += newX;
  centre_.y += newY;
}

point_t Circle::getPosition() const
{
  return centre_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::print() const
{
  std::cout << "Here is circle. Radius = " << radius_ << ", coordinates of centre (";
  std::cout << centre_.x << ", " << centre_.y << "), its area = ";
  std::cout << getArea() << ".\n Frame of circle: centre coordinates (";
  std::cout << getFrameRect().pos.x << ", " << getFrameRect().pos.y << ", ";
  std::cout << "width = " << getFrameRect().width << ", height = " << getFrameRect().height << ". \n\n";
}
