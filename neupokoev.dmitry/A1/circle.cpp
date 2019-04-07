#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle(point_t point, double radius) :
  centre_(point),
  radius_(radius)
{
  assert((radius_ > 0.0) && ("Incorrect radius value"));
}

void Circle::move(const point_t &point)
{
  centre_ = point;
}

void Circle::move(double moveX, double moveY)
{
  centre_.x += moveX;
  centre_.y += moveY;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = 2 * radius_;
  frameRect.height = 2 * radius_;
  frameRect.pos = centre_;
  return frameRect;
}

void Circle::writeParameters() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Circle radius is (" << radius_;
  std::cout << ") Centre is (" << centre_.x << ",";
  std::cout << centre_.y << ")\n";
  std::cout << "Frame rectangle width = " << rectangle.width;
  std::cout << ", height = " << rectangle.height << "\n";
  std::cout << "Area = " << getArea() << "\n\n";
}
