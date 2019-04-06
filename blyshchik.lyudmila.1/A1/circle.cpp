#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t locO, double radius):
  circ_(locO),
  radius_(radius)
{
  assert (radius_ > 0.0);
}
Circle::Circle(double locX, double locY, double radius):
  Circle(point_t{locX, locY}, radius)
{
}

double Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  return {getPosition(), getRadius() * 2, getRadius() * 2};
}

void Circle::move(const point_t newCentre) const
{
  circ_ = newCentre;
}

void Circle::move(double newX, double newY) const
{
  circ_ = point_t{getPosition().locX + newX, getPosition().locY + newY};
}

point_t Circle::getPosition() const
{
  return circ_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::print() const
{
  std::cout << "Here is circle. Radius = " << getRadius() << ", coordinates (";
  std::cout << getPosition().locX << ", " << getPosition().locY << "), its area = ";
  std::cout << getArea() << ".\n Frame of circle: centre coordinates (";
  std::cout << getFrameRect().pos.locX << ", " << getFrameRect().pos.locY << ", ";
  std::cout << "width = " << getFrameRect().width << ", height = " << getFrameRect().height << ". \n\n";
}
